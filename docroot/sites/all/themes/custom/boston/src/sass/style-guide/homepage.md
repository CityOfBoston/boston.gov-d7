# KSS Style Guide

This web site is built using Sass and component-based styles. This front-end style guide documents the design components and the Sass variables, functions and mixins used to build the site. This styleguide is based on the styleguide from the Zen theme.

## Organization

We categorize our CSS styles to make them easy to find and apply to our HTML.

- Defaults: These are the default base styles applied to HTML elements.
- Layouts: The layout styling for major parts of the page that are included with the theme.
- Forms: Form components are specialized design components that are applied to forms or form elements.
- Components: Design components are reusable designs that can be applied using just the CSS class names specified in the component.
- Colors and Sass: Colors used throughout the site. And Sass documentation for mixins, etc.

While our styles are organized as above in the style guide, our Sass files are organized in a file hierarchy like this:

- init: Sass needed to load variables, 3rd-party libraries and custom mixins and
  functions.
- base: default HTML styles
- components: component-based styles
- layout: component styles that only apply layout to major chunks of the page
- style-guide: some helper files needed to build this automated style guide
