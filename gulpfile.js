'use strict';

let gulp = require('gulp');
let util = require('gulp-util');
let plugins = require('gulp-load-plugins')();
let runSequence = require('run-sequence')


// Set config options needed
let options = {};

options.base_path = "./docroot/sites/all/themes/custom";
options.hub_path = options.base_path + "/boston_hub";
options.public_path = options.base_path + "/boston_public";
options.default_path = options.base_path + "/boston";

// Determine which theme we should work on for this task.
// Default to the default theme, if --hub or --public flag used
// then work with them.
let theme_path = options.default_path;

if (util.env.hub) {
  theme_path = options.hub_path;
}

if (util.env.public) {
  theme_path = options.public_path;
}

// Create object of needed paths
options.paths = {
  boston: options.default_path,
  dest: theme_path + "/dist",
  ie: theme_path + "/src/ie",
  images: theme_path + "/src/img",
  scripts: theme_path + "/src/js",
  scripts_vendor: theme_path + "/src/vendor-js",
  theme_path: theme_path
}

// This will get the task to allow us to use the configs above
function getTask(task) {
  return require('./gulp-tasks/' + task)(gulp, plugins, options.paths, util);
}

// Tasks!
// -----------------------

// Javascript tasks
gulp.task('scripts', getTask('scripts'));
gulp.task('scripts:iframe', getTask('scripts_iframe'));

// Lint tasks
gulp.task('lint', ['lint:js']);
gulp.task('lint:js', getTask('lint_scripts'));

// Optimize images
gulp.task('images', getTask('images'));

// Watch tasks
gulp.task('watch', ['build','watch:ie','watch:js']);
gulp.task('watch:ie', getTask('watch_ie'));
gulp.task('watch:js', getTask('watch_scripts'));

// Build
gulp.task('build', ['images', 'scripts', 'scripts:iframe'], function (cb) {
  // Run linting last, otherwise its output gets lost.
  runSequence(['lint'], cb);
});

// Default task
gulp.task('default', ['build']);
