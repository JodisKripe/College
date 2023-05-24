# Definition

The maven's build Lifecycle is a well-defined series of phases and goals which describe the order in which maven executes its build tasks. It consists primarily of three phases: the default life-cycle, the clean lifecycle and the site lifecycle.

# Phases

## Default Lifecycle:

This is the default lifecycle that takes place when one runs the 'mvn' binary without specifying a particular phase. It has the following subphases:

- validate: Validates the project configuration.
- compile: conmpiles the source code of the project.
- test: Runs predefined tests on the compiled source code.
- package: packages the compiled code into a distributable format eg. JAR or WAR
- verify: Performs checks on the results of integration tests to ensure quality criteria are met.
- install: Installs the packaged artifact into the local maven repository, making it available to other projects.
- deploy: copies the final packaged artifact to a remote repository for sharing with others

## Clean Lifecycle:

Is responsible for cleaning the project by removing any build artifacts from previous builds

- pre-clean: Executes any necessary tasks pre-coded by the developer.
- clean: Removes all build artifacts from the project.
- post-clean: Executes pre-coded tasks deemed necessary by the developer.

## Site Lifecycle:

Is used to gather project documentation and reports.

- pre-site: Executes pre-coded tasks deemed necessary by the developer.
- site: generates the project documentation.
- post-site: Executes pre-coded tasks deemed necessary by the developer.
- site-deploy: Deploys the generated documentation to a remote server for sharing
