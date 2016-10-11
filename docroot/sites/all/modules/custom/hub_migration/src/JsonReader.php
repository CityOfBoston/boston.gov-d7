<?php
/**
 * @file
 * JsonReader.
 */

namespace Drupal\hub_migration;

/**
 * Class JsonReader.
 *
 * @package Drupal\hub_migration
 */
class JsonReader extends \MigrateJSONReader {

  /**
   * {@inheritdoc}
   */
  public function next() {
    migrate_instrument_start('MigrateJSONReader::next');

    $this->currentElement = $this->currentId = NULL;

    // Open the file and position it if necessary.
    if (!$this->fileHandle) {
      $this->fileHandle = fopen($this->url, 'r');
      if (!$this->fileHandle) {
        \Migration::displayMessage(t('Could not open JSON file !url',
          array('!url' => $this->url)));
        return;
      }

      // Lets move forward until we find the beginning of the array.
      while ($char = $this->getNonBlank() != '[') {
        // If we hit the end of the file and never found the array, throw an
        // exception.
        if ($char === FALSE) {
          \Migration::displayMessage(t('!url is not a JSON file containing an array of objects',
            array('!url' => $this->url)));
          return;
        }
      }
    }

    // We expect to be positioned either at an object (beginning with {) or
    // the end of the file (we should see a ] indicating this). Or, an
    // object-separating comma, to be skipped. Note that this treats
    // commas as optional between objects, which helps with processing
    // malformed JSON with missing commas (as in Ning exports).
    $c = $this->getNonBlank();
    if ($c == ',') {
      $c = $this->getNonBlank();
    }
    // Ning sometimes emits a ] where there should be a comma.
    elseif ($c == ']') {
      $c = $this->getNonBlank();
      if ($c != '{') {
        $c = NULL;
      }
    }
    // We expect to be at the first character of an object now.
    if ($c == '{') {
      // Start building a JSON string for this object.
      $json = $c;
      // Look for the closing }, ignoring brackets in strings, tracking nested
      // brackets. Watch out for escaped quotes, but also note that \\" is not
      // an escaped quote.
      $depth = 1;
      $in_string = FALSE;
      $in_escape = FALSE;
      while (($c = fgetc($this->fileHandle)) !== FALSE) {
        $json .= $c;
        if ($in_string) {
          // Quietly accept an escaped character.
          if ($in_escape) {
            $in_escape = FALSE;
          }
          else {
            switch ($c) {
              // Unescaped " means end of string.
              case '"':
                $in_string = FALSE;
                break;

              // Unescaped \\ means start of escape.
              case '\\':
                $in_escape = TRUE;
                break;
            }
          }
        }
        else {
          // Outside of strings, recognize {} as depth changes, " as start of
          // string.
          switch ($c) {
            case '{':
              $depth++;
              break;

            case '}':
              $depth--;
              break;

            case '"':
              $in_string = TRUE;
              break;
          }
          // We've found our match, exit the loop.
          if ($depth < 1) {
            break;
          }
        }
      }

      // Turn the JSON string into an object.
      $this->currentElement = json_decode($json);
      $this->currentId = $this->currentElement->{$this->idField};
    }
    else {
      $this->currentElement = NULL;
      $this->currentId = NULL;
    }
    migrate_instrument_stop('MigrateJSONReader::next');
  }

}
