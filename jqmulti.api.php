<?php

/**
 * @file
 * API documentation for the jQuery Multi module
 */
 
 /**
  * @addtogroup hooks
  * @{
  */

 /**
  * Add files to be loaded with jQuery Multi's jQuery library
  * @return
  *   An array of full paths to files that should be loaded with the jqmulti's jQuery library
  *   (paths are relative to Drupal root)
  */
 function hook_jqmulti_files() {
   return array(
    'path/to/file.js',
    'another/full/file/path.js',
   );
 }

 /**
  * Add libraries to be loaded with jQuery Multi's jQuery library.
  * @return
  *   An array of library names, where the name corresponds to the name of a directory
  *   in the sites/all/libraries directory. All and only the .js files in this directory will
  *   be automatically loaded by jQuery Multi.
  */
 function hook_jqmulti_libraries() {
   return array(
    'some_library',
    'another_library',
   );
 }

 /**
  * @} End of "addtogroup hooks".
  */
