<?php
/**
 * @file
 * bos_text_formats.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function bos_text_formats_filter_default_formats() {
  $formats = array();

  // Exported format: Filtered HTML.
  $formats['filtered_html'] = array(
    'format' => 'filtered_html',
    'name' => 'Filtered HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'wysiwyg' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(
          'valid_elements' => '@[class|style|title],
a[href|target<_blank|title|rel|name],
em/i, strong/b, s, sub, sup,
img[width|height|alt|title|src],
p[align<center?justify?left?right],
div[align<center?justify?left?right],
br,address, hr, blockquote, pre, cite, code, span, footer,q,section,
iframe[width|height|frameborder|scrolling|src|allowfullscreen],
h2,h3,h4,h5,h6,
ul,ol,li,dl,dt,dd,
table[width|cellpadding|cellspacing|border|summary],
colgroup,col,
picture,
source[media|srcset],
tr[align|valign|rowspan],
td[align|valign|width|colspan|data-label],
th[align|valign|width],tbody,thead,tfoot',
          'allow_comments' => 0,
          'nofollow_policy' => 'whitelist',
          'nofollow_domains' => array(
            0 => 'boston.dev',
            2 => 'boston.gov',
            4 => 'cityofboston.gov',
          ),
          'style_color' => array(
            'color' => 0,
            'background' => 0,
            'background-color' => 0,
            'background-image' => 0,
            'background-repeat' => 0,
            'background-attachment' => 0,
            'background-position' => 0,
          ),
          'style_font' => array(
            'font' => 0,
            'font-family' => 0,
            'font-size' => 0,
            'font-size-adjust' => 0,
            'font-stretch' => 0,
            'font-style' => 0,
            'font-variant' => 0,
            'font-weight' => 0,
          ),
          'style_text' => array(
            'text-align' => 'text-align',
            'text-decoration' => 'text-decoration',
            'text-indent' => 'text-indent',
            'text-transform' => 'text-transform',
            'letter-spacing' => 'letter-spacing',
            'word-spacing' => 'word-spacing',
            'white-space' => 'white-space',
            'direction' => 0,
            'unicode-bidi' => 0,
          ),
          'style_box' => array(
            'margin' => 'margin',
            'margin-top' => 'margin-top',
            'margin-right' => 'margin-right',
            'margin-bottom' => 'margin-bottom',
            'margin-left' => 'margin-left',
            'padding' => 'padding',
            'padding-top' => 'padding-top',
            'padding-right' => 'padding-right',
            'padding-bottom' => 'padding-bottom',
            'padding-left' => 'padding-left',
          ),
          'style_border-1' => array(
            'border' => 0,
            'border-top' => 0,
            'border-right' => 0,
            'border-bottom' => 0,
            'border-left' => 0,
            'border-width' => 0,
            'border-top-width' => 0,
            'border-right-width' => 0,
            'border-bottom-width' => 0,
            'border-left-width' => 0,
          ),
          'style_border-2' => array(
            'border-color' => 0,
            'border-top-color' => 0,
            'border-right-color' => 0,
            'border-bottom-color' => 0,
            'border-left-color' => 0,
            'border-style' => 0,
            'border-top-style' => 0,
            'border-right-style' => 0,
            'border-bottom-style' => 0,
            'border-left-style' => 0,
          ),
          'style_dimension' => array(
            'height' => 'height',
            'line-height' => 'line-height',
            'max-height' => 'max-height',
            'max-width' => 'max-width',
            'min-height' => 'min-height',
            'min-width' => 'min-width',
            'width' => 'width',
          ),
          'style_positioning' => array(
            'bottom' => 'bottom',
            'overflow' => 'overflow',
            'vertical-align' => 'vertical-align',
            'clip' => 0,
            'left' => 0,
            'right' => 0,
            'top' => 0,
            'z-index' => 0,
          ),
          'style_layout' => array(
            'clear' => 'clear',
            'display' => 'display',
            'float' => 'float',
            'position' => 'position',
            'visibility' => 'visibility',
          ),
          'style_list' => array(
            'list-style' => 0,
            'list-style-image' => 0,
            'list-style-position' => 0,
            'list-style-type' => 0,
          ),
          'style_table' => array(
            'border-collapse' => 'border-collapse',
            'border-spacing' => 'border-spacing',
            'caption-side' => 'caption-side',
            'empty-cells' => 'empty-cells',
            'table-layout' => 'table-layout',
          ),
          'style_user' => array(
            'cursor' => 0,
            'outline' => 0,
            'outline-width' => 0,
            'outline-style' => 0,
            'outline-color' => 0,
            'zoom' => 0,
          ),
          'rule_valid_classes' => array(
            0 => 'icon-*',
            2 => 'button',
            4 => 'button-*',
            6 => 'wysiwyg-photo-wrapper',
            8 => 'inner-photo-wrapper',
            10 => 'caption',
            12 => 'red',
            14 => 'supporting*',
            16 => 'rte*',
            18 => 'image-left',
            20 => 'image-right',
            22 => 'standalone-image',
            24 => 'time*',
            26 => 'step*',
            28 => 'pending',
            30 => 'big',
            32 => 'intro-text',
            34 => 'small',
            36 => 'completed',
            38 => 'no-*',
            40 => 'responsive-table*',
          ),
          'rule_valid_ids' => array(),
          'rule_style_urls' => array(),
        ),
      ),
      'shortcode' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(
          'form' => 0,
          'poll' => 0,
        ),
      ),
      'filter_tokens' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'picture' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -41,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => -40,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -39,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Full HTML.
  $formats['full_html'] = array(
    'format' => 'full_html',
    'name' => 'Full HTML',
    'cache' => 0,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'filter_url' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -43,
        'status' => 1,
        'settings' => array(),
      ),
      'shortcode' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(
          'form' => 1,
          'poll' => 1,
        ),
      ),
      'filter_tokens' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -7,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Script Source URL.
  $formats['script_source_url'] = array(
    'format' => 'script_source_url',
    'name' => 'Script Source URL',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_html' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(
          'allowed_html' => '',
          'filter_html_help' => 1,
          'filter_html_nofollow' => 0,
        ),
      ),
      'filter_html_escape' => array(
        'weight' => -10,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
