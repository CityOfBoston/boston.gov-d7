## Cloud Hooks

This directory contains [Acquia Cloud hooks](https://docs.acquia.com/cloud/manage/cloud-hooks).

### Directory Structure

    tests
    ├── common    - contains hooks that will be executed for _all_ environments.
    ├── dev       - contains hooks that will be executed for _dev_ environment.
    ├── prod      - contains hooks that will be executed for _prod_ environment.
    ├── samples   - contains example Cloud Hooks.
    ├── templates - contains templates, which may be cloned and used as a starting point for creating your own custom cloud hook scripts.
    └── test      - contains hooks that will be executed for _test_ environment.

### Documentation

For detailed information on how to implement these hooks, read the [documentation on Acquia.com]((https://docs.acquia.com/cloud/manage/cloud-hooks)) 
or visit the [Cloud Hook repository](https://github.com/acquia/cloud-hooks).

### City of Boston Notes
March 2019 
1. COB deploy workflow starts with a commit/merge to the develop branch of the CoB "boston.gov-d7" github repo 
(usually in the github UI). Travis then initiates an update to the develop-build branch of the Acquia-hosted git repo. 
Beyond merging/commiting in github, no other actions are required.
1. The "City of Boston" and "Hub" application develop environment is linked to the "develop-build" branch in the repo 
managed by Acquia.
1. Each Applications develop environment is always the first step in the deploy chain.  No manual action is required, 
this hook does all the necessary tasks to update the develop environment in each Application.
1. When ready to move through the deploy workflow, the github develop branch is merged to the master branch. Travis 
then initiates an update to the master-build branch of the Acquia-hosted git repo.  Beyond merging/commiting in github, 
no other actions are required.
1. Each Applications stage environment is linked to the "master-build" branch in the repo managed by Acquia.
1. When ready to deploy to live, code is simply dragged from the develop to the prod environment to update the live 
boston.gov website.
1. These Aquia hooks manage the backup and synchronization of databases, so the only manual deploy actions required 
are to drag code around in the Acquia Cloud UI.