// Ouvrir le dropdown en hover
$(document).ready(function () {
  $(".dropdown").hover(function () {
    $(this).addClass("open");
  }, function () {
    $(this).removeClass("open");
  });
});

// Activer les navlink en hover
$(document).ready(function () {
  $(".navlink").hover(function () {
    $(this).addClass("active");
  }, function () {
    $(this).removeClass("active");
  });
});

// Avoir la navbar toujours au dessus du body
$(document).ready(function(){
  $(document.body).css('padding-top', $('#topnavbar').height());
  $(window).resize(function(){
    $(document.body).css('padding-top', $('#topnavbar').height());
  });
});