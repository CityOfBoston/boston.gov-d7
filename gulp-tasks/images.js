'use strict';

/*
  Can use the --fail flag to fail this task if not linted correctly
*/

module.exports = function (gulp, plugins, options, util) {
  return function () {
    var stream = gulp.src([
                       options.boston + '/src/img/**/*.{png,jpg,jpeg,gif,svg}',
                       options.images + '/**/*.{png,jpg,jpeg,gif,svg}'
                     ])
                     .pipe(plugins.debug({title: 'optimized images:'}))
                     .pipe(plugins.imagemin({progressive: true}))
                     .pipe(gulp.dest(options.dest + '/img'));

    return stream;
  };
};
