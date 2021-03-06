////////////////////////////////////////////
//
//  jQuery Multi
//
////////////////////////////////////////////

-- SUMMARY --

Need to use a higher version of jQuery for your module or theme than the one provided by Drupal/jQuery Update?

jQuery Multi allows you to load an extra version of the jQuery library in parallel to Drupal's version, without 
conflicting with Drupal's version. You can then choose any JavaScript library or files to use the new version
of jQuery. No need to alter packaged jQuery plugins!

-- INSTALLATION --

  1. Place a version of the minified jQuery library in the libraries folder, so that
     the path to the actual jQuery library will be: sites/all/libraries/jquery/jquery-<version>.min.js
  2. Download and install jQuery Multi in the usual fashion.

-- USAGE --

  1. Enable the module.
  2. Navigate to the settings page at admin/config/settings/jqmulti.
  3. Ensure that your jQuery library has been detected.
  
  4. To target certain JavaScript files to run with the jQuery Multi version, choose
     one of the following methods:
  
    A) Put the JS in sites/all/libraries/ and use the UI at admin/config/system/jqmulti
       to select your library. All the library's JS files will be loaded with the jqmulti jQuery version. 
       There is no need to use the alias in this case. This is ideal if you're using a 
       prepackaged jQuery library or plugin.
    B) Put the JS in sites/all/libraries/ and use hook_jqmulti_libraries() to include the library.
       No need to use the alias. This is ideal if you're using a prepackaged jQuery library or plugin,
       and is equivalent to method A.
    C) Put the JS anywhere else, like in a custom module, and use hook_jqmulti_files() to load it. No need to use the alias.
    D) Put the JS anywhere, use the provided alias, and don't use the jqmulti hooks or UI. Simply load 
       with drupal_add_js() or something similar. If you're only using this method, make sure to select
       the 'Load Always' checkbox in the jQuery Multi config.

        To use the automatically provided jQuery alias in your custom scripts:
  
            Use the version of jQuery loaded by jQuery Multi in your custom scripts by referencing
            the automatically provided alias in your script closure. The alias names are
            generated using the jQuery version number, with the periods removed.
  
            For instance, if you're loading jQuery-1.7.1, the alias will be jq171, and you can
            use it in your scripts by wrapping your code as follows:
  
            (function($){
              // your code here, using jQuery 1.7.1
            })(jq171)
    
  NOTE: Loading libraries with Jquery Multi will only load the JS files within the library. You must
        call drupal_add_css() separately to load any included CSS files that may be in the library.

  NOTE: All jQuery targeted to use jQuery Multi (using methods A, B, or C above) must properly use a 
        closure around the jQuery code, as is best practice for all Drupal jQuery code, i.e.:
        
            (function($){
              // your code here, using jQuery 1.7.1
            })(jQuery)

  