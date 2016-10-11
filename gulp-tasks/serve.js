'use strict';

let browserSync = require('browser-sync').create();

module.exports = function (gulp, plugins, options, util) {
  var stream = function() {
    browserSync.init({
      port: 3001,
      proxy: util.env.uri || 'https://spyglass.dd:8443',
      files: options.dest + '/css/**/*.css',
    });
  };

  return stream;
};
