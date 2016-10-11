# Custom Scripts

This directory contains scripts that may be used to general project 
maintenance.

    scripts
    ├── project.make.yml   - this make file is used to track all drupal project dependencies, such as modules, themes, and libraries, and their correspondign patches. The docroot should consist only of projects specificied in this make file. 
    ├── rebuild-contrib.sh - rebuilds all contributed projects by running drush make on project.make.yml
    ├── update-local-db.sh - drops the local db and replaces it with a remote db
