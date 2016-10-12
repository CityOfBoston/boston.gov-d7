# Setting up your local environment

## Build Status
*  [![Build Status](https://travis-ci.com/CityOfBoston/boston.gov.svg?token=4Mk5JW5r1ifn1vTCrTF7&branch=master)](https://travis-ci.com/CityOfBoston/boston.gov)

## Prereqs
* Account on Acquia
* composer 1.1.2 [See documentation here](https://getcomposer.org/doc/00-intro.md#installation-linux-unix-osx)
* nvm 0.31 - `curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.31.0/install.sh | bash`
* node 5.4.0 - `source ~/.bashrc; nvm install 5.4.0; nvm use 5.4.0`
* Acquia Dev Desktop [Download here](https://dev.acquia.com/downloads)
* Drush Aliases [Download here](https://accounts.acquia.com/account/1195776/security/drush_aliases/download?site=insight)
  * Install like so: `tar -C $HOME -xf $HOME/Downloads/acquiacloud.tar.gz`

## Initial repo setup

* Fork the repository to your local github account.
* Clone your local forked repository to your local machine
* Remove the following file:
  * `composer.lock`

* Modify the following files:
  * docroot/sites/default/settings/local.settings.php
    * set `port` to `33067`
    * set `base_url` to `https://spyglass.dd:8443` 
  * docroot/sites/hub/settings/local.settings.php
    * set `port` to `33067`
    * set `base_url` to `https://hub.dd:8443`

* Copy and modify these files:

  * `copy docroot/sites/example.local.site.php docroot/sites/local.site.php`
    * **local.sites.php**: Uncomment both `$sites` lines; remove `loc.` from each config line.

  * `copy tests/behat/example.local.yml tests/behat/local.yml`
    * **local.yml**: Update default: base_url: https://spyglass.dd:8443 ; Update hub: base_url: https://hub.dd:8443

* In the root of repository:
~~~~
composer update
composer install
./task.sh setup:git-hooks
./task.sh frontend:install
./task.sh frontend:build
./task.sh setup:build:make
~~~~

## Set up Acquia Dev Desktop
* Click on `+` symbol
* Click on `Import local drupal site`
* Set `Local Code Base` folder to $your_repository_root/docroot
* Set `Site name` to 'spyglass'
* Click 'Ok'

## Finish initial setup
* In the root of repository: `./task.sh build:local`

## Kerjigger Hub setup
* Open Dev Desktop and select the existing spyglass site.
* At the top of the screen there will be a dropdown for "Multisite"
  * Select "hub" from the dropdown.
  * Click "Initialize this site"
  * Set the domain name to "hub" so the URL will be hub.dd:8083.
* Run install from root of repository
  * `./hub-task.sh build:local`

## Get content
  * In $your_repository_root/docroot directory:
    * drush sql-sync @boston.test @self
	*drush rsync @boston.prod:%files/ @self:%files

