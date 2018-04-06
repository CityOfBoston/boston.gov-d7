<nav class="nv-h">
  <ul class="nv-h-l">
    <?php if ($logged_in && $GLOBALS['theme'] == 'boston_hub'): ?>
      <li class="nv-h-l-i nv-dd">
        <input type="checkbox" name="nv-dd-tr" id="nv-tr[0]" class="nv-dd-tr">
        <label class="nv-h-l-a nv-h-l-a--k nv-dd-l" for="nv-tr[0]"><?php if ($first_name): ?>Hello, <?php print $first_name ?><?php else: ?>My Account<?php endif; ?></label>
        <ul class="nv-dd-c">
          <li><a href="<?php print $profile_path; ?>" title="Visit my profile" class="nv-dd-c-link">Profile</a></li>
          <li><a href="<?php print $change_password_path; ?>" title="Change password" class="nv-dd-c-link">Change password</a></li>
          <li><a href="<?php print $security_questions_path; ?>" title="Security questions" class="nv-dd-c-link">Security questions</a></li>
          <li><a href="<?php print $logout_path; ?>" title="log out" class="nv-dd-c-link">Log Out</a></li>
        </ul>
      </li>
    <?php endif; ?>
    <?php foreach ($secondary_menu as $link) { ?>
      <li class="nv-h-l-i"><a href="<?php print url($link['href'], array('absolute' => true)) ?>" title="<?php print $link['title'] ?>" class="nv-h-l-a<?php print $link['always_show'] ? ' nv-h-l-a--k' : '' ?>"><?php print $link['title'] ?></a></li>
    <?php } ?>
    <li class="tr nv-h-l-i">
      <a href="#translate" title="Translate" class="nv-h-l-a nv-h-l-a--k--s tr-link">Translate</a>
      <ul class="tr-dd">
        <li><span class="notranslate tr-dd-link tr-dd-link--message">Loading...</span></li>
        <li><a href="#" class="notranslate tr-dd-link" data-ln="ht">Kreyòl Ayisyen</a></li>
        <li><a href="#" class="notranslate tr-dd-link" data-ln="pt">Portugese</a></li>
        <li><a href="#" class="notranslate tr-dd-link" data-ln="es">Español</a></li>
        <li><a href="#" class="notranslate tr-dd-link" data-ln="vi">Tiếng Việt</a></li>
        <li><a href="#" class="notranslate tr-dd-link tr-dd-link--hidden" data-ln="en">English</a></li>
      </ul>
    </li>
    <li class="nv-h-l-i">
      <label for="s-tr" title="Search" class="nv-h-l-a nv-h-l-a--k nv-h-l-a-ic" id="searchIcon">
        <svg id="Layer_2" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 40 41"><title>Search</title><path class="nv-h-l-a-i" d="M24.2.6C15.8.6 9 7.4 9 15.8c0 3.7 1.4 7.2 3.6 9.8L1.2 37c-.8.8-.8 2 0 2.8.4.4.9.6 1.4.6s1-.2 1.4-.6l11.5-11.5C18 30 21 31 24.2 31c8.4 0 15.2-6.8 15.2-15.2C39.4 7.4 32.6.6 24.2.6zm0 26.5c-6.2 0-11.2-5-11.2-11.2S18 4.6 24.2 4.6s11.2 5 11.2 11.2-5 11.3-11.2 11.3z"/></svg>
      </label>
    </li>
  </ul>
</nav>
