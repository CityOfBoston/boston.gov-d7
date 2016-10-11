#!/usr/bin/env bash

# Drop the current database.
drush @local.mysite sql-drop --yes

# Download the new database.
# drush sql-sync [source databse] [target database] --no-cache --yes
drush sql-sync @mysite.dev @local.mysite --yes --structure-tables-key=lightweight

# Clear the cache.
drush @local.mysite cc all

# Run update hooks.
drush @local.mysite updb --yes

# Obtain a ULI link.
drush @local.mysite uli
