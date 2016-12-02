# Setting up your local environment

## Prereqs
* Composer 1.1.2 [See documentation here](https://getcomposer.org/doc/00-intro.md#installation-linux-unix-osx)
* NVM 0.31 - `curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.31.0/install.sh | bash`
* node 5.4.0 - `source ~/.bashrc; nvm install 5.4.0; nvm use 5.4.0`

## Initial repo setup
* Fork the repository to your local github account.
* Clone your local forked repository to your local machine
* Remove the following file:
  * `composer.lock`

* Modify the following files:
  * docroot/sites/default/settings/default.local.settings.php
    * set `port` to `33067`
    * set `base_url` to `https://spyglass.dd:8443`
  * docroot/sites/hub/settings/default.local.settings.php
    * set `port` to `33067`
    * set `base_url` to `https://hub.dd:8443`

* Copy and modify these files:

  * `copy docroot/sites/example.local.sites.php docroot/sites/local.sites.php`
    * **local.sites.php**: Uncomment both `$sites` lines; remove `loc.` from each config line.

  * `copy tests/behat/example.local.yml tests/behat/local.yml`
    * **local.yml**: Update local: extensions: base_url: https://spyglass.dd:8443 ; Update hub: extensions: Behat\MinkExtension: base_url: https://hub.dd:8443

* In the root of repository:
```
composer update
composer install
./task.sh setup:git-hooks
./task.sh frontend:install
./task.sh frontend:build
./task.sh setup:build:make
```

## Finish initial setup
* In the root of repository: `./task.sh build:local`

## Finish Hub setup
* Run install from root of repository
  * `./hub-task.sh build:local`