'use strict';

module.exports = function (gulp, plugins, options) {
  return function () {
    var stream = gulp.watch([
                        options.boston + '/src/sass/**/*.s+(a|c)ss',
                        options.styles + '/**/*.s+(a|c)ss',
                        options.styles + '/**/*.hbs'
                      ], ['styleguide']);

    return stream;
  };
};
