<?php
/**
 * @file
 * bos_text_formats.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function bos_text_formats_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html.
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'JustifyBlock' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Source' => 1,
          'HorizontalRule' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'ShowBlocks' => 1,
          'RemoveFormat' => 1,
          'Format' => 1,
          'Styles' => 1,
          'Find' => 1,
          'Replace' => 1,
          'CreateDiv' => 1,
          'Iframe' => 1,
          'SpellChecker' => 1,
          'Scayt' => 1,
        ),
        'citedblockquote' => array(
          'CitedBlockquote' => 1,
        ),
        'table' => array(
          'Table' => 1,
        ),
        'tabletools' => array(
          'TableTools' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 1,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'self',
      'css_path' => 'https://patterns.boston.gov/legacy/public.css',
      'stylesSet' => '',
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 0,
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 1,
      'user_choose' => 0,
      'version' => '4.5.8.c1fc9a9',
    ),
    'name' => 'formatfiltered_html',
    'rdf_mapping' => array(),
  );

  // Exported profile: full_html.
  $profiles['full_html'] = array(
    'format' => 'full_html',
    'editor' => 'ckeditor',
    'settings' => array(
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'JustifyBlock' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Image' => 1,
          'TextColor' => 1,
          'BGColor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Source' => 1,
          'HorizontalRule' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'ShowBlocks' => 1,
          'RemoveFormat' => 1,
          'Format' => 1,
          'Font' => 1,
          'FontSize' => 1,
          'Styles' => 1,
          'SelectAll' => 1,
          'Find' => 1,
          'Replace' => 1,
          'CreateDiv' => 1,
          'Iframe' => 1,
          'Maximize' => 1,
          'SpellChecker' => 1,
          'Scayt' => 1,
        ),
        'citedblockquote' => array(
          'CitedBlockquote' => 1,
        ),
        'table' => array(
          'Table' => 1,
        ),
        'tabletools' => array(
          'TableTools' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'self',
      'css_path' => 'https://patterns.boston.gov/legacy/public.css',
      'stylesSet' => '',
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 0,
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 1,
      'user_choose' => 0,
      'version' => '4.5.8.c1fc9a9',
    ),
    'name' => 'formatfull_html',
    'rdf_mapping' => array(),
  );

  return $profiles;
}
