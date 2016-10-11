#!/bin/sh
#
# Cloud Hook: post-db-copy
#
# The post-db-copy hook is run whenever you use the Workflow page to copy a
# database from one environment to another. See ../README.md for
# details.
#
# Usage: post-db-copy site target-env db-name source-env

site="$1"
target_env="$2"
db_name="$3"
source_env="$4"


# Scrub the db of any PII if not on prod environemnt
if [ "$site" != 'boston' ] && [ "$target_env" != 'prod' ]; then
  echo "$site.$target_env: The $db_name database has been deployed from $source_env to $target_env.."
  echo "$site.$target_env: Scrubbing database $db_name..."
   (cat <<EOF
  --
  -- Scrub important information from a Drupal database.
  --

  -- Remove all email addresses.
  UPDATE users SET mail=CONCAT('user', uid, '@example.com'), init=CONCAT('user', uid, '@example.com') WHERE uid != 0;

  TRUNCATE field_data_field_home_address;
  TRUNCATE field_data_field_personal_email;
  TRUNCATE field_data_field_phone_number;
  TRUNCATE field_data_field_mailing_address;
  TRUNCATE field_data_field_emergency_contact_phone;
  TRUNCATE field_data_field_emergency_contact_name;
EOF
) | drush @$site.$target_env ah-sql-cli --db=$db_name
  echo "Database '$db_name' scrub complete..."
else
   echo "$site.$target_env: The $db_name database has been deployed from $source_env to $target_env."
fi