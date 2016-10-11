'use strict';

module.exports = function (gulp, plugins, options) {
  return function () {
    var stream = gulp.src(options.styles + "/styles.scss")
      // Initializes sourcemaps
      .pipe(plugins.sourcemaps.init())
      .pipe(plugins.cssGlobbing({
          // Configure it to use SCSS files
          extensions: ['.scss']
      }))
      .pipe(plugins.sass({
          errLogToConsole: true,
          outputStyle: 'expanded',
          includePaths: [
            './node_modules/chroma-sass/sass',
            './node_modules/susy/sass',
            './node_modules/compass-mixins/lib',
            './node_modules/breakpoint-sass/stylesheets',
            './node_modules/typey/stylesheets'
          ]
        }))
      .pipe(plugins.autoprefixer({
        browsers: ['last 3 versions'],
        cascade: false
      }))
      // Writes sourcemaps into the CSS file
      .pipe(plugins.sourcemaps.write())
      .pipe(gulp.dest(options.dest + '/css'));

    return stream;
  };
};
