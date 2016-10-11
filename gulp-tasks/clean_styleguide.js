'use strict';

let del = require('del');

module.exports = function (gulp, plugins, options) {
  var stream = function () {
    del([
      options.dest + '/styleguide/*.html',
      options.dest + '/styleguide/public',
      options.dest + '/css/**/*.hbs'
    ], {force: true});
  };

  return stream;
};
