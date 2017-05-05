thunder
==========

Acquia PS Drupal starter theme

To get started building your subtheme:

Make sure that you have the following installed:

- bower

- node and npm

Run these commands from your subtheme directory:

`bower install`

This reads bower.json and installs libraries to the bower_components folder.

`yarn install`

This reads package.json and installs node modules to node_modules.
IMPORTANT it also runs a script to remove .info files from the node_modules folder that will cause issues with
Drupal and drush. See [https://www.drupal.org/node/2329453](Ignore vendor folders to improve directory search performance) for details.

// Resources

ESLint

- http://davidwalsh.name/eslint
