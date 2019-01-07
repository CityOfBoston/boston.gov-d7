### Status
[![Build Status](https://travis-ci.org/CityOfBoston/boston.gov-d7.png)](https://travis-ci.org/CityOfBoston/boston.gov-d7)

<img src="https://cloud.githubusercontent.com/assets/9234/19400090/8c20c53c-9222-11e6-937c-02bce55e5301.png" alt="City of Boston" width="150" />

The source code for [Boston.gov](https://boston.gov), the official site of the City of Boston. Boston.gov is built on Drupal and serves as the digital front door for the City of Boston.

> _Welcome! We've released the code for Boston.gov in the public domain to engage developers and designers like you. We welcome your contributions to improve the City's digital front door, and are looking forward to sharing what we create together with the public._
> 
> — Mayor Martin J. Walsh

There’s a large, civic-minded ecosystem of software developers out there, especially in the Drupal community, and we’re hoping they’re willing to lend a hand and help Boston.gov grow, as well as foster collaboration between multiple organizations to solve common technical hurdles.    

## Developers

Get started with our [developer guide](https://github.com/CityOfBoston/boston.gov/blob/develop/guides/02-setting-up-development.md). 

Each contributor should [fork](https://help.github.com/articles/fork-a-repo) the primary Boston.gov repo. All developers should then checkout a local copy of the `develop` branch to begin work.

For any work, pull requests must be created for individual tasks and submitted for review. Before submitting a pull request, be sure to [sync the local branch](https://help.github.com/articles/syncing-a-fork) with the upstream primary branch.

Pull requests should be submitted from the forked repo to the `develop` branch of the primary repo. Make sure to give your pull request a **clear and descriptive title** and use the template below.

#### Pull request template

```
## Changes

This PR references #[GitHub issue number]

 * [First change]
 * [Second change]
 * [Third change]

This PR references #[GitHub issue number]
```

### Docker Quick-Start
[Watch a YouTube video of this quick-start.](https://www.youtube.com/watch?v=KgUzuKq-pfA&feature=youtu.be)

1. Download [Docker for
   Mac](https://www.docker.com/docker-machttps://www.docker.com/docker-mac) or
   [Docker for Windows](https://www.docker.com/docker-windows), or otherwise get
   a Docker environment with Docker Compose installed.
1. Clone this repo.
1. Run `docker-compose up` in the root directory. **This will start the servers**
   **and stay open to show their logs.**
1. In another terminal window, initialize the database: `docker exec
   bostongov_drupal_1 scripts/init-docker-container.sh` (this will take 10+
   minutes).
1. Visit http://127.0.0.1:8888/ to see the blank install. Visit
   http://127.0.0.1:8888/user?local to log in, with admin/admin as username and
   password.

The Hub — our internal Drupal install — can run in the same container and
against the same MySQL server. To initialize it, run:

`docker exec bostongov_drupal_1 scripts/init-docker-container.sh hub`

It’s available at http://127.0.0.1:8889/ and you can log in with admin/admin at
http://127.0.0.1:8889/user?local

Since pulling files through the Docker volume mount is relatively slow, we keep
vendored packages within the container and only map in our custom directories.
So, only local edits to the following directories will be seen within the
container:

```
  docroot/profiles
  docroot/sites/default
  docroot/sites/hub
  docroot/sites/all/modules/custom
  docroot/sites/all/modules/features
  docroot/sites/all/settings
  docroot/sites/all/themes/custom
```

You can modify this list by editing `scripts/init-docker-container.sh`

#### Running `drush` commands

To get a shell within a running Drupal container, run `docker exec -it
bostongov_drupal_1 /bin/bash`

From there you can run `drush` or `task.sh` commands.

#### Running tests in Docker

Assuming you have already done the local initialization, you can run:
```
docker exec bostongov_drupal_1 ./task.sh -Dbehat.run-server=true -Dproject.build_db_from=initialize tests:all
```

_Note: as of this writing, the tests do not work for the Hub environment (`./hub-task.sh`)._

##### Running `drush` commands with Acquia cloud site alias
A drush alias is a shortcut to a remote Drupal site. It is in essence a tunnel through which drush commands can be issued. To use Drush to connect to Acquia Cloud site aliases, you must:

1. [Register SSH public keys for your Acquia user profile](https://docs.acquia.com/acquia-cloud/ssh/enable/add-key)
2. [Download Drush aliases for all of your sites and extract the archive into $HOME.](https://docs.acquia.com/acquia-cloud/drush/aliases)
3. Ensure that your Acquia cloud site aliases are available with `drush sa`.  You should see the aliases listed.  If not, check that you exported the archive to your $HOME directory.

### On-demand test instances

_For City team members._

You can push your local repository up to a test instance on our staging cluster
on AWS. This will let you show off functionality using data from a staging
snapshot of Boston.gov.

#### Prerequisites

* You will need Docker installed on your local machine
* Install the [AWS Command Line Interface](https://aws.amazon.com/cli/)
* Get a “CLI” IAM user with an access key and secret key
* Use `aws configure` to log your CLI user in locally. Use `us-east-1` as the
  default region.

#### Setup

To create a place to upload your code, follow the instructions in the
[CityOfBoston/digital-terraform](https://github.com/CityOfBoston/digital-terraform)
repo to make a “variant” of the Boston.gov staging deployment.

#### Pushing local code

To push your local repository up to the cluster, run:

```
$ ./doit stage <variant>
```

Where “`<variant>`” is the variant name you created in
`CityOfBoston/digital-terraform`.

This will build a container image locally and upload it to ECR. It will then
update your staging ECS service to use the new code.

By default, the container startup process will initialize its MySQL database
with a snapshot of the staging environment from Acquia.

After the container starts up and is healthy, the `doit` script will print
useful URLs and then quit.

#### Running drush on staging

Direct SSH access is not generally available on the ECS cluster. To run `drush`
commands on your test instance, you can visit the `webconsole.php` page at its
domain. This will give you a shell prompt where you can run _e.g._ `drush uli`
to get a login link.

The `webconsole.php` shell starts in `docroot`.

Talk to another developer to get the username and password.

#### Preserving the database between pushes

By default, each time you deploy code to your test instance it starts with a
fresh copy of the Drupal database.

If you want to preserve state between test runs, log in to `webconsole.php` and
run:

```
$  ../doit stash-db
```

(The `..` is because `webconsole.php` starts in the `docroot`.)

This will take a snapshot of your database and upload it to S3. The next time
your test instance starts up, it will start its sync from this database rather
than the Acquia staging one.

To clear the stash, so that your database starts fresh on the next test instance
push, use `webconsole.php` to run:

```
$ ../doit stash-db reset
```

## Public domain

This project is in the worldwide [public domain](LICENSE.md). As stated in [LICENSE](LICENSE.md):

> This project is in the public domain within the United States, and copyright and related rights in the work worldwide are waived through the [CC0 1.0 Universal public domain dedication](https://creativecommons.org/publicdomain/zero/1.0/).
>
> All contributions to this project will be released under the CC0 dedication. By submitting a pull request, you are agreeing to comply with this waiver of copyright interest.

## Staying organized

All projects, open source or not, need some way to stay organized. Whether reporting a bug ([check out the template](https://github.com/CityOfBoston/boston.gov/blob/develop/guides/03-contributing-to-boston.gov.md#bug-report-template)), suggesting a feature [another template](https://github.com/CityOfBoston/boston.gov/blob/develop/guides/03-contributing-to-boston.gov.md#feature-template), filing a pull request [yay, templates](https://github.com/CityOfBoston/boston.gov/blob/develop/guides/03-contributing-to-boston.gov.md#pull-request-template), or even just seeing what's next in the queue, here are some ways we keep things clear on the Digital Team:

### Contribute to development

Check out our current prioroities for boston.gov in our [Git project](https://github.com/orgs/CityOfBoston/projects/3).
