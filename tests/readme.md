# Testing

This directory contains all projects tests, grouped by testing technology. For
all configuration related to builds that actually run these tests, please see
the [build](/build) directory.

    tests
    ├── behat - contains all Behat tests
    │    ├── features
    │    │   ├── bootstrap
    │    │   └── Example.feature 
    │    ├── behat.yml - contains behat configuration common to all behat profiles.
    │    └── integration.yml - contains behat configuration for the integration profile, which is used to run tests on the integration environment.
    ├── jmeter  - contains all jMeter tests
    └── phpunit - contains all PHP Unit tests

# Executing tests

Before attempting to execute any tests, verify that composer dependencies
are built by running `composer install` in the project root.

Each testing type can be either executed directly, or via a corresponding Phing
target. Phing will execute the tests with default values defined in your
project's yaml configuration files (project.yml, local.yml). Examples: 

* `./task.sh tests:all`
* `./task.sh tests:behat`
* `./task.sh tests:phpunit`

To execute the tests directly (without Phing) see the following examples:

* `./bin/behat -c tests/behat/local.yml test/behat/features/Examples.feature`
* `./bin/phpunit tests/phpunit/ProjectTemplateTest.php`

For more information on the commands, run:

* `./bin/phpunit --help`
* `./bin/behat --help`
