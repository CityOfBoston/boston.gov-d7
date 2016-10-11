'use strict';

let cliSass = 'node_modules/node-sass/bin/node-sass';
let exec = require('child_process').exec;

module.exports = function (gulp, plugins, options) {
  var stream = function () {
    exec('mkdir -p ' + options.dest + '/css/style-guide');
    exec(cliSass + ' --no-cache --sourcemap=none --style expanded ' + options.styles + '/style-guide/chroma-kss-markup.scss ' + options.dest + '/css/style-guide/chroma-kss-markup.hbs.tmp');
    exec('head -n 2  ' + options.dest + '/style-guide/chroma-kss-markup.hbs.tmp | tail -n 1 > ' + options.dest + '/css/style-guide/chroma-kss-markup.hbs');
    exec('rm ' + options.dest + '/css/style-guide/chroma-kss-markup.hbs.tmp');
  };

  return stream;
};
