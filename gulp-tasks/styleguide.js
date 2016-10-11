'use strict';

let exec = require('child_process').exec;
let path = require('path');

module.exports = function (gulp, plugins, options, util) {
  let flags = [], values;

  let styleGuideOptions = {
    source: [
      options.styles,
      options.dest + '/css/style-guide/'
    ],
    destination: options.theme_path + '/styleguide',

    // The css and js paths are URLs, like '/misc/jquery.js'.
    // The following paths are relative to the generated style guide.
    css: [
      path.relative(options.theme_path + '/styleguide', options.dest + '/css/styles.css'),
      path.relative(options.theme_path + '/styleguide', options.dest + '/css/style-guide/chroma-kss-styles.css'),
      path.relative(options.theme_path + '/styleguide', options.dest + '/css/style-guide/kss-only.css')
    ],
    js: [
    ],

    homepage: 'homepage.md',
    title: 'Living Style Guide'
  };

  for (var flag in styleGuideOptions) {
    if (styleGuideOptions.hasOwnProperty(flag)) {
      values = styleGuideOptions[flag];
      if (!Array.isArray(values)) {
        values = [values];
      }
      for (var i = 0; i < values.length; i++) {
        flags.push('--' + flag + '=\'' + values[i] + '\'');
      }
    }
  }

  flags = util.env.verbose ? flags.join(' ') + ' --verbose' : flags.join(' ');

  var stream = function() {
    exec('./node_modules/.bin/kss-node ' + flags);
  };

  return stream;
};
