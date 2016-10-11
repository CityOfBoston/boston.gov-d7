<?php
/**
 * @file
 * Contains class MenuContext.
 */

namespace Boston\Contexts;

use Behat\Behat\Context\SnippetAcceptingContext;
use Drupal\DrupalExtension\Context\RawDrupalContext;

/**
 * Class MenuContext.
 */
class MenuContext extends RawDrupalContext implements SnippetAcceptingContext {

  private $menuLinkTitles = array();

  /**
   * Cleanup menu items.
   *
   * @AfterScenario
   */
  public function cleanMenuItems() {
    if (empty($this->menuLinkTitles)) {
      return;
    }
    $query = db_select('menu_links', 'ml');
    $links = $query->fields('ml', array('mlid', 'link_title'))
      ->condition('link_title', $this->menuLinkTitles)
      ->execute()
      ->fetchAllAssoc('mlid');
    $mlids = array_keys($links);
    if (!empty($mlids)) {
      foreach ($mlids as $mlid) {
        menu_link_delete($mlid);
      }
    }
  }

  /**
   * Create a placeholder link via the UI.
   *
   * @Given I add a placeholder link to the :menu
   */
  public function iAddAplaceholderLinkToThe($menu) {
    $menus = menu_get_menus();
    $menus = array_flip($menus);
    $machine_name = $menus[$menu];
    $this->visitPath('admin/structure/menu/manage/' . $machine_name . '/add');
    $page = $this->getSession()->getPage();
    $menu_label = 'Verify Main Menu Nolink Add';
    $page->fillField('Menu link title', $menu_label);
    $page->fillField('Path', '<nolink>');
    $page->checkField('Enabled');
    $page->pressButton('Save');
    // Add the test menu link title here so it gets cleaned up after the
    // scenario completes.
    $this->menuLinkTitles[] = $menu_label;
  }

  /**
   * Verify the placeholder link appears in the main menu.
   *
   * @Then the placeholder link appears in the :menu
   */
  public function thePlaceholderLinkAppearsInThe($menu) {
    $page = $this->getSession()->getPage();
    $this->visitPath('/');
    $link = $page->findLink('Verify Main Menu Nolink Add');
    if (empty($link)) {
      throw new \Exception('Placeholder item is not present on the homepage.');
    }
    if ($link->getAttribute('href') !== '#') {
      throw new \Exception('Placeholder item does not match the expected href value of "#".');
    }
  }

}
