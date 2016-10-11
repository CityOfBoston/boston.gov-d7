'use strict';

/*
  Can use the --fail flag to fail this task if not linted correctly
*/

module.exports = function (gulp, plugins, options, util) {
  return function () {
    var stream = gulp.src(options.styles + '**/*.s+(a|c)ss')
                     .pipe(plugins.sassLint())
                     .pipe(plugins.sassLint.format())
                     .pipe(plugins.if(util.env.fail, plugins.sassLint.failOnError()));

    return stream;
  };
};
