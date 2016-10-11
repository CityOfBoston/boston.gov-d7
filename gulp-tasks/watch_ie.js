'use strict';

module.exports = function (gulp, plugins, options) {
  return function () {
    var stream = gulp.watch([
      options.boston + '/src/ie/**/**',
      options.ie + '/**/**'
    ], ['ie']);

    return stream;
  };
};
