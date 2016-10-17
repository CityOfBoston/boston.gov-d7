# Contributing to Boston.gov

:+1::tada: Thank-you for being interested in contributing to Boston.gov! :tada::+1:

This is a guideline for contributing to the development of Boston.gov. We're open to improvements in our process, so feel free to send a PR for this document, or create an issue.

## Jump right in

 * [Report issues on Boston.gov](#reporting-bugs)
 * [Suggest new features](#suggest-new-features)
 * [Contributing to development](#contributing-to-development)

### Reporting bugs

If you need to submit a bug report for Boston.gov, please follow these guidelines. Following these guidelines helps us and the community better understand your report, reproduce the bug, and find related issues.

#### Prior to submitting a bug

 * Verify that you are able to reproduce it repeatedly. Try multiple browsers, devices, etc. Also, try clearing your cache.
 * Perform a quick search of our [existing issues](https://github.com/CityOfBoston/boston.gov/issues) to see if it has been logged previously.

#### Submitting a bug

 * Use a **clear and descriptive** title when creating your issue.
 * Include a bulleted list of steps to reproduce your issue.
 * Include the URL of the page that you're seeing the issue on.
 * Include screenshots if possible. Bonus points if you include an animated GIF of the issue.
 * Include details about your browser (which one, what version, using ad blockers?).
 * When filing your issue, assume that the recipient knows nothing about what you're talking about. There is no such thing as too many details when filing your issue.

#### Bug report template

```
## Basic details

URL: [URL]

## Steps to reproduce

1. [FIRST]
2. [SECOND]
3. [THIRD]

## What I think should happen

[Describe your expected behavior here]

## What did happen

[Describe the actual behavior here]

## Browser details

Browser: [Enter browser]
Version: [Enter version]
Ad blocker: [Ad blocker?]

[SCREENSHOT]
```

### Suggest new features

Have an idea for Boston.gov? If so, [create an issue](https://github.com/CityOfBoston/boston.gov/issues). Prior to submitting your feature request, please do a basic search of existing issues to see if it's already been suggested.

### Contributing to development

This section will help you get started contributing to the development of Boston.gov. To get started, you'll need to get a development environment up and running.

Our process resembles a [Gitflow Workflow](https://www.atlassian.com/git/workflows#!workflow-gitflow) with the follow specifics -

* The `master` branch is always ready for deployment.
* All development is performed against a `develop` branch.
* Prior to release, `develop` is deployed to our staging environment and tested. It is tehn merged into `master` and `master` is deployed to production.


#### Project Setup

Each contributor should [fork](https://help.github.com/articles/fork-a-repo) the primary Boston.gov repo. All developers should then checkout a local copy of the `develop` branch to begin work.

For any work, pull requests must be created for individual tasks and submitted for review. Before submitting a pull request, be sure to [sync the local branch](https://help.github.com/articles/syncing-a-fork) with the upstream primary branch.

Pull requests should be submitted from the forked repo to the `develop` branch of the primary repo. Make sure to give your pull request a **clear and descriptive title**.

Use this template when creating your pull request:

```
## Changes

 * [First change]
 * [Second change]
 * [Third change]

This PR references #[GitHub issue number]
```
