////////////////////////////////////////////
//
//  jQuery Multi
//
////////////////////////////////////////////

Features:
  - run a newer version of jQuery in parallel to Drupal's without interfering with things
    that use the default jQuery version, using jQuery's built in noConflict mode
  - use the newer version of jQuery in custom scripts using the provided alias
  - configure specific libraries to use the newer jQuery
  - configure any JS file in the system to load using the newer jQuery

Usage:
  1. Enable the module
  2. Navigate to the settings page
  3. Select the version of jQuery you want to load 
  4. Select any libraries you want to load with the selected jQuery

---------------------------------

  You can also use the API to add or remove libraries or any individual files that will be
  loaded with the selected version of jQuery. See jqmulti.api.php (not in existence yet).

---------------------------------

  You can also use the selected jQuery in your custom scripts simply by referencing
  the automatically provided alias in your script closure. The alias names are
  generated using the jQuery version number, with the periods removed.
  
  For instance, if you're loading jQuery-1.7.1, the alias will be: jq171, and you can
  use it in your scripts by wrapping your code as follows:
  
  (function($){
    // your code here, using jQuery 1.7.1
  })(jq171)



TODO:
  - Add CDN support
  - Add targeting for modules and themes
  - Theme js files currently won't work at all, even using jqueries_add_file(). This needs to change
  - Improve UI
