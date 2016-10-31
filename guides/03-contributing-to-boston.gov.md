# Contributing to Boston.gov

:+1::tada: Thank you for being interested in contributing to Boston.gov! :tada::+1:

This is a guideline for contributing to the development of Boston.gov. We're open to improvements, so feel free to send a PR for this document, or create an issue.

## Jump right in

 * [Report issues on Boston.gov](#reporting-bugs)
 * [Suggest new features](#suggest-new-features)
 * [Contribute to development](#contribute-to-development)

### Reporting bugs

If you need to submit a bug report for Boston.gov, please follow these guidelines. This will help us and the community better understand your report, reproduce the bug, and find related issues.

#### Before you submit a bug

 * Verify that you are able to reproduce it repeatedly. Try multiple browsers, devices, etc. Also, try clearing your cache.
 * Perform a quick search of our [existing issues](https://github.com/CityOfBoston/boston.gov/issues) to see if it has been logged previously.

#### Submit a bug

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

#### Feature template

```
## User story

[Don't write:
  "As a <type of user>, I want <some goal> so that <some reason>."]

[Tell us a story instead:
  "I like knowing what major construction projects are planned for my neighborhood. It makes me good to review
  those project documents and share my opinion on them at any public hearings. It's a hassle to constantly 
  check the website, though. Is there any way I can automatically get an email when something is happening
  within a certain distance from my apartment?]

## Acceptance criteria

1. [FIRST]
2. [SECOND]
3. [THIRD]

[Example:
1. Be able to sign up for an email notification.
2. Receive an email notification with proposed construction projects and associated hearings.
3. Be able to indicate an intent to attend a specific hearing.]

## Good examples to share

[Add links, screenshots, mockups, or any other example of where you've seen someone do what you're requesting
_well_. Add a brief description of what you like and/or dislike about it.]

```

### Contribute to development

To contribute to the development of Boston.gov, you'll need to get a development environment up and running. This section will get you started.

Our process resembles a [Gitflow Workflow](https://www.atlassian.com/git/workflows#!workflow-gitflow) with the following specifics:

* The `master` branch is always ready for deployment.
* All development is performed against a `develop` branch.
* Before release, `develop` is deployed to our staging environment and tested. It is then merged into `master` and `master` is deployed to production.


#### Project setup

Each contributor should [fork](https://help.github.com/articles/fork-a-repo) the primary Boston.gov repo. All developers should then checkout a local copy of the `develop` branch to begin work.

For any work, pull requests must be created for individual tasks and submitted for review. Before submitting a pull request, be sure to [sync the local branch](https://help.github.com/articles/syncing-a-fork) with the upstream primary branch.

Pull requests should be submitted from the forked repo to the `develop` branch of the primary repo. Make sure to give your pull request a **clear and descriptive title** and use the template below.

#### Pull request template

```
## Changes

 * [First change]
 * [Second change]
 * [Third change]

This PR references #[GitHub issue number]
```
