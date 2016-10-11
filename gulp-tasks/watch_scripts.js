'use strict';

module.exports = function (gulp, plugins, options) {
  return function () {
    var stream = gulp.watch([
                        options.boston + '/src/js/*.js',
                        options.boston + '/src/vendor-js/*.js',
                        options.scripts_vendor + '/*.js',
                        options.scripts + '/*.js'
                      ], ['lint:js', 'scripts']);

    return stream;
  };
};
