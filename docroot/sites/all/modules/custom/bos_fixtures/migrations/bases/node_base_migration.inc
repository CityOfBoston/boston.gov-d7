<?php
/**
 * @file
 * Contains NodeBaseMigration class.
 */

/**
 * Class NodeBaseMigration.
 */
abstract class NodeBaseMigration extends FixtureMigrationXml {

  /**
   * Get the node migration's type/bundle.
   *
   * @return string
   *   The machine name of the node type/bundle.
   */
  protected abstract function getNodeType();

  /**
   * Class constructor.
   *
   * @param array $arguments
   *   Migration arguments.
   */
  public function __construct($arguments = array()) {
    $arguments['schema'] = MigrateDestinationNode::getKeySchema();
    parent::__construct($arguments);
    $this->destination = new MigrateDestinationNode($this->getNodeType());
  }

  /**
   * All node migration sub-classes should call this.
   *
   * @param object $node
   *   The entity preparing to be saved.
   * @param object $row
   *   The row data for the current item being imported.
   */
  public function prepare($node, $row) {
    // If the incoming row has specified a workbench state, make sure
    // that state gets set on the entity before it's saved.
    if (isset($row->xml->workbench_state)) {
      $node->workbench_moderation_state_new = $row->xml->workbench_state;
    }
  }

}
