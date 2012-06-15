<?php

/**
 * @file 
 * Admin-related functions for the jQuery Multi module.
 */

/**
 * Admin form for jQuery Multi module.
 */
function jqmulti_admin_form() {
  $form = array();
  
  // This will rebuild the files list if they're not cached.
  jqmulti_get_files();
  
  $version = jqmulti_get_version();
  
  if (!$version) {
    // no jQuery is available
    $form['jqmulti_version'] = array(
      '#value' => t('No jQuery library could be found. Please add a version of jQuery in the libraries folder (see README.txt for details)'),
    );
    
    return $form;
  }
  
  $form['jqmulti_version'] = array(
    '#type' => 'item',
    '#title' => 'jQuery Version',
    '#value' => t('Using jQuery version %version', array('%version' => $version)),
  );
  
  $form['jqmulti_load_always'] = array(
    '#type' => 'checkbox',
    '#title' => t('Always load this jQuery library, even if no libraries or files are targeted to it'),
    '#default_value' => variable_get('jqmulti_load_always', FALSE),
    '#description' => t('Turn this on if you want to use the newer version of jQuery in custom scripts, using the alias provided'),
  );

  $form['jqmulti_load_libraries_always'] = array(
    '#type' => 'checkbox',
    '#title' => t('Always load libraries assigned to this version of jQuery'),
    '#default_value' => variable_get('jqmulti_load_libraries_always', FALSE),
    '#description' => t('Turn this on if you want all libraries and files targeted to jqmulti to be loaded on every page.') . '<br />' .
                      t('Otherwise, the files will only be loaded if they have been added using a traditional drupal method, for example with drupal_add_js().') . '<br />' .
                      t('This affects javascript added using the settings below, and using the jqmulti API hooks.'),
  );

  // Find all libraries that are turned on by the hook.
  $available_libraries = jqmulti_get_available_libraries();
  
  $form['jqmulti_libraries'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Libraries',
    '#options' => $available_libraries,
    '#description' => t('Select libraries to target to the version of jQuery selected above'),
    '#default_value' => variable_get('jqmulti_libraries', array()),
  );
  
  $form['#after_build'] = array('jqmulti_admin_afterbuild');
  $form['#submit'][] = 'jqmulti_admin_submit';

  return system_settings_form($form);
}

/**
 * An after_build callback for the admin form.
 */
function jqmulti_admin_afterbuild($form, &$form_state) {
  // disable libraries that are turned on by hooks
 $hooked_libraries = module_invoke_all('jqmulti_libraries');
 $available_libraries = $form['jqmulti_libraries']['#options'];
 foreach ($available_libraries as $library => $lib) {
   if (in_array($library, $hooked_libraries)) {
     $form['jqmulti_libraries'][$library]['#default_value'] = TRUE;
     $form['jqmulti_libraries'][$library]['#value'] = TRUE;
     $form['jqmulti_libraries'][$library]['#attributes']['disabled'] = 'disabled';
   }
 }
 return $form;
}

/**
 * Submit callback for the admin form.
 */
function jqmulti_admin_submit($form, &$form_state) {
  // clear the files cache, so it'll rebuild after new values are saved
  cache_clear_all('jqmulti_files', 'cache');
}
