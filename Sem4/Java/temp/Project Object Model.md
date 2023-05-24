# Definition

Project Object Model is an XML file that describes the configuration and dependencies of a Maven project. Its the main building block of a maven project and acts as a blueprint.
The POM file, name 'pom.xml' is placed in the project's root directory and contains various elements and settings that define how Maven should build the project.

# Usage

The POM acts as a project descriptor that Maven uses to understand the project's structure, build process, build plugins and other project-specific configurations. It provides a standardized way to define project setting and makes it easier to collaborate or share the project within a Maven based ecosystem.
By customizing the POM file, you can tailor the build process, manage dependencies, configure plugins, generate reports and control various ascpects of the Maven project

# Key Aspects

## Project Information

- `<groupId>`: Specifies the unique identifier of the group or organisation that owns the project.
- `<artifactId>`: Defines the project's unique identifier or name.
- `<version>`: Specifies the project's version number
- `<name>`: Provides a human readable name for the project.
- `<description>`: Gives a brief description of the project.

## Project Structure

- `<dependencies>`: Lists the external files/dependencies required by the project
- `<build>`: Contains configuration elements related to the project's build process. eg source directories, build plugins and build profiles etc.
- `<plugins>`: Specifies the plugins used during the build process, including their configurations and goals

## Inheritance and Modules

- `<parent>`: Allows a project to inherit settings from a parent POM, promoting consistency
- `<modules>`: Defines the list of modules within a multi-module project.

## Repositories and Dependency Management

- `<repositories>`: Specifies the remote repositories from which Maven retrieves dependencies.
- `<dependencyManagement>`: Centralized dependency definitions and versions for multi-module projects, ensuring consistent dependency usage across modules

## Reporting and Documentation

- `<reporting>`: Configures the reporting plugins to generate project reports and documentation.
- `<site>`: configures the generation of the Project documentation and repots for the 'site' lifecycle.
