# Behat Testing
The following is a guide on how to bootstrap Behat testing.

## Local system

1. Execute `composer install` in project root.
1. Set up Behat local.yml file `./task.sh setup:behat`
1. Execute behat tests either via Phing target, or directly from binary:
  * Via Phing: `./task.sh tests:behat` 
  * Fron binary: `./vendor/bin/behat tests/behat/features --config=tests/behat/local.yml -p local`
