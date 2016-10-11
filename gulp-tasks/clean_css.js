'use strict';

let del = require('del');

module.exports = function (gulp, plugins, options) {
  var stream = function () {
    del([
      options.dest + '/**/.sass-cache',
      options.dest + '/**/*.css',
      options.dest + '/**/*.map'
    ], {force: true});
  };

  return stream;
};
