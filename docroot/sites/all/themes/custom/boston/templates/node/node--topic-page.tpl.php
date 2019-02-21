<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 *
 * @see https://drupal.org/node/1728164
 */
?>
<article class="<?php print $classes; ?> clearfix node-<?php print $node->nid; ?>"<?php print $attributes; ?>>

  <?php if ($title_prefix || $title_suffix || $display_submitted || $unpublished || $preview || !$page && $title): ?>
    <header class="topic-header">
      <?php print render($title_prefix); ?>
      <?php if (!$page && $title): ?>
        <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
      <?php endif; ?>
      <?php print render($title_suffix); ?>

      <?php if ($unpublished): ?>
        <mark class="watermark"><?php print t('Unpublished'); ?></mark>
      <?php elseif ($preview): ?>
        <mark class="watermark"><?php print t('Preview'); ?></mark>
      <?php endif; ?>

      <div class="topic-hero-text-wrapper">
        <div class="intro-container fullwidth">
          <?php if ($title): ?>
            <div class="intro-title">
              <div class="intro-title-wrapper">
                <div class="topic-title-prefix"><span></span>guide<span></span></div>
                <h1 id="topicTitle"><?php print render($title); ?></h1>
                <div class="topic-subhead">Last updated <?php print render($content['field_updated_date']);?></div>
              </div>
            </div><!-- End intro-title -->
          <?php endif; ?>
          <div class="intro-content">
            <?php if (isset($content['field_intro_text'])): ?>
              <div class="topic-intro-text-container">
                <div class="intro-text-top"></div>
                <div class="topic-intro-text-content">
                  <?php print render($content['field_intro_text']); ?>
                </div><!-- End .topic-intro-text-container -->
              </div><!-- End .topic-intro-text-wrapper -->
            <?php endif; ?>
          </div><!-- End .intro-content -->
        </div><!-- End .intro-container -->
      </div><!-- End .topic-hero-text-wrapper -->

      <div class="section-nav-button-container">
        <button class="sub-nav-button">
          <?php print _boston_findsvg($GLOBALS['theme_info'], 'subnav-toggle.svg'); ?>
        </button>
      </div>

      <nav class="topic-nav">
        <ul></ul>
        <a name="section-nav"></a>
      </nav>

    </header>
  <?php endif; ?>


  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    // Keep field_intro_image hidden. Output rendered to page level.
    hide($content['field_intro_image']);
    hide($content['field_intro_text']);
    hide($content['field_updated_date']);
    hide($content['field_published_date']);
    hide($content['field_contacts']);
    print render($content);
  ?>

   <!-- begin Bibblio custom markup-->
       <div class="bibblio-container entity entity-paragraphs-item paragraphs-item-text component-section" about="" typeof="">
          <div class="content">
              <div class="sh">
                <h2 class="sh-title">Suggested Content</h2>
              </div>
              <div class="paragraphs-items paragraphs-items-field-text-blocks paragraphs-items-field-text-blocks-full paragraphs-items-full">
                  <div class="entity entity-paragraphs-item paragraphs-item-text-one-column component-section" about="" typeof="">
                      <div class="content">
                          <div id="bibblio-custom">
                              <div class="g"></div>
                          </div>
                      </div>
                  </div>
              </div>
          </div>
        </div>
  <!-- end Bibblio custom markup -->

  <?php if (isset($content['field_contacts'][0])): ?>
    <section class="b b--fw b--g">
      <div class="b-c">
        <div class="sh m-b500">
          <h2 data-short-title="Departments" class="sh-title">Departments You May Need</h2>
        </div>
        <div class="g">
          <?php print render($content['field_contacts']); ?>
        </div>
        <!-- End .departments-wrapper -->
      </div>
      <!-- End topic-departments-container -->
    </section><!-- End departments-container -->
  <?php endif; ?>
</article>

<!-- begin Bibblio custom code -->
<script>
    function getHTML(bibContent){
      var listItem = '';
      jQuery(bibContent).each(function(index,value){
          let bibFields = value.fields;
          let assetDefaultURL = "<?php  print $asset_url ?>/images/wallpaper.svg";
          let bgImg = bibFields.moduleImage !== null ? bibFields.moduleImage.contentUrl : assetDefaultURL;
          
          let bibName = bibFields.name;
          let bibUrl = bibFields.url;
          let bibDesc = bibFields.description; 
          listItem += '<a class= "cd g--4 g--4--sl m-t500" href="'+bibUrl+'"><div class="cd-ic" style="background-image:url('+bgImg+')"><\/div><div class="cd-c"><div class="cd-t">'+bibName+'<\/div><div class="cd-d"\>'+bibDesc+'<\/div><\/div><\/a>';
          
      });
      //console.log(listItem);
      jQuery('#bibblio-custom div.g').append(listItem);
    }
    const pageURL = window.location.pathname;
    jQuery.ajax({
      method: "GET",
      url: "https://api.bibblio.org/v1/recommendations",
      contentType: "application/json",
      headers: {
        "Authorization": "Bearer 6364c775-5133-4a32-a80e-a2116bac884b"
      },
      data:{ 
        "customUniqueIdentifier": "https://bostonuat.prod.acquia-sites.com" + pageURL,
        "fields":"name,moduleImage,url,datePublished,description", 
        "limit":"3",
      },
      success: function (res){
        let bibContent = res.results;
        getHTML(bibContent); 
        //alert('success' + res.status);
      },
      error: function (res){
            if(res.status == '404'){
              jQuery(".bibblio-container").hide();
            };
      }
     });       
  </script>
<!-- end Bibblio custom code -->


