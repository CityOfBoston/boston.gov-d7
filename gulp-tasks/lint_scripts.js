'use strict';

/*
  Can use the --fail flag to fail this task if not linted correctly
*/

module.exports = function (gulp, plugins, options, util) {
  return function () {
    var stream = gulp.src([
                        options.boston + '/src/js/*.js',
                        options.scripts + '/*.js'
                      ])
                      .pipe(plugins.jshint())
                      .pipe(plugins.jshint.reporter('default', { verbose: true }))

    return stream;
  };
};
