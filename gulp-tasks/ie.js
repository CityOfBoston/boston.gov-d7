'use strict';

module.exports = function (gulp, plugins, options) {
  return function () {
    console.log(options.dest + '/ie');
    var stream = gulp.src([options.ie + '**/**']).pipe(gulp.dest(options.dest))
    return stream;
  };
};
