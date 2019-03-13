 var bibblioImgObj = [
    {   'desc' : 'skyline',
        'path' : 'sites/default/files/styles/rep_wide_2000x700custom_boston_desktop_2x/public/hero-image-03-2019/boston-skyline.jpg'
    },{
        'desc' : 'boston_common',
        'path' : 'sites/default/files/styles/resp_wide_2000x460custom_boston_desktop_1x/public/photo-image-09-2018/dsc_0134_1.jpg'
    },{
        'desc' : 'state_house',
        'path' : 'sites/default/files/styles/featured_item_thumbnail/public/statehouse.jpg'
    },{
        'desc' : 'nh-roslindale',
        'path' : 'sites/default/files/styles/grid_card_image/public/roslindale.jpg'
    },{
        'desc' : 'nh-jamaica_plain',
        'path' : 'sites/default/files/styles/grid_card_image/public/jamaicaplain4.jpg'
    },{
        'desc' : 'nh-back_bay',
        'path' : 'sites/default/files/styles/grid_card_image/public/backbay5.jpg'
    }
]
var getImg = function () {
    num = Math.floor(Math.random() * (bibblioImgObj.length - 1));
    findItem = bibblioImgObj.findIndex(i => i.desc === bibblioImgObj[num].desc); 
    //console.log(findItem +' : '+bibblioImgObj[findItem].path);
    pathVal = bibblioImgObj[findItem];
    bibblioImgObj.splice(findItem,1);
    return pathVal;
}
var getHTML = function(bibContent){
  var listItem = '';
  jQuery(bibContent).each(function(index,value){
      let bibFields = value.fields;
      let imgInfo = getImg();
      let bibName = bibFields.name;
      let bibUrl = bibFields.url;
      let bibDesc = bibFields.description; 
      listItem += '<a class= "cd g--4 g--4--sl m-t500 bibblio" bibblio-title="'+bibName+'" bibblio-img-desc="'+imgInfo.desc+'" href="'+bibUrl+'"><div class="cd-ic" style="background-image:url(https://boston.gov/'+imgInfo.path+')" ><\/div><div class="cd-c"><div class="cd-t">'+bibName+'<\/div><div class="cd-d"\>'+bibDesc+'<\/div><\/div><\/a>';
      
  });
  jQuery('#bibblio-custom div.g').append(listItem);
}
const pageURL = window.location.pathname;
//const siteLocation = 'https://boston.gov';
const siteLocation = 'https://bostonuat.prod.acquia-sites.com';
jQuery.ajax({
  method: "GET",
  url: "https://api.bibblio.org/v1/recommendations",
  contentType: "application/json",
  headers: {
    //live
    //"Authorization": "Bearer 6364c775-5133-4a32-a80e-a2116bac884b"
    //testing
      "Authorization": "Bearer 0966dd72-5068-462f-8c15-9967ad9a975f"
  },
  data:{ 
    "customUniqueIdentifier": siteLocation + pageURL,
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