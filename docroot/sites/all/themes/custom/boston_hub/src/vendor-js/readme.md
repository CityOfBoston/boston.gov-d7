This is for javascript/libraries/plugins that come from third
parties. The reason why they're separate from the js folder is
we don't want to lint minified js.

Vendor js is concatenated first so it's read before your theme's js.

This is done through the scripts task in the gulpfile.
