 var imgBase = 'https://boston.gov/';
 var randImgObj = [
    {   'desc' : 'skyline',
        'path' : imgBase + 'sites/default/files/styles/rep_wide_2000x700custom_boston_desktop_2x/public/hero-image-03-2019/boston-skyline.jpg'
    },{
        'desc' : 'boston_common',
        'path' : imgBase + 'sites/default/files/styles/resp_wide_2000x460custom_boston_desktop_1x/public/photo-image-09-2018/dsc_0134_1.jpg'
    },{
        'desc' : 'state_house',
        'path' : imgBase + 'sites/default/files/styles/featured_item_thumbnail/public/statehouse.jpg'
    },{
        'desc' : 'nh-roslindale',
        'path' : imgBase + 'sites/default/files/styles/grid_card_image/public/roslindale.jpg'
    },{
        'desc' : 'nh-jamaica_plain',
        'path' : imgBase + 'sites/default/files/styles/grid_card_image/public/jamaicaplain4.jpg'
    },{
        'desc' : 'nh-back_bay',
        'path' : imgBase + 'sites/default/files/styles/grid_card_image/public/backbay5.jpg'
    }
]
var getImgRand = function () {
    num = Math.floor(Math.random() * (randImgObj.length - 1));
    findItem = randImgObj.findIndex(i => i.desc === randImgObj[num].desc); 
    //console.log(findItem +' : '+bibblioImgObj[findItem].path);
    pathVal = randImgObj[findItem];
    randImgObj.splice(findItem,1);
    return  pathVal;
}
var getImgBibblio = function (infoData) {
    let imgObj = {
        'desc' : infoData.description,
        'path' : infoData.image.contentUrl
        }
    return imgObj;
}
var getHTML = function(bibContent){
  var listItem = '';
  jQuery(bibContent).each(function(index,value){
      let bibFields = value.fields;
      let imgInfo;
      let checkImg = bibFields.image;
      //console.log(bibFields);
      if(checkImg == null){
        imgInfo = getImgRand() 
      }else{
        imgInfo = getImgBibblio(bibFields)
      }
      let bibName = bibFields.name;
      let bibUrl = bibFields.url;
      let bibDesc = bibFields.description; 
      listItem += '<a class= "cd g--4 g--4--sl m-t500 bibblio" bibblio-title="'+bibName+'" bibblio-img-desc="'+imgInfo.desc+'" href="'+bibUrl+'"><div class="cd-ic" style="background-image:url('+ imgInfo.path +')" ><\/div><div class="cd-c"><div class="cd-t">'+bibName+'<\/div><div class="cd-d"\>'+bibDesc+'<\/div><\/div><\/a>';
      
  });
  jQuery('#bibblio-custom div.g').append(listItem);
}
const pageURL = window.location.pathname;
const siteLocation = 'https://www.boston.gov';
jQuery.ajax({
  method: "GET",
  url: "https://api.bibblio.org/v1/recommendations",
  contentType: "application/json",
  headers: {
    //live
    "Authorization": "Bearer 852cf94f-5b38-4805-8b7b-a50c5a78609b"
    //testing
    //"Authorization": "Bearer 0966dd72-5068-462f-8c15-9967ad9a975f"
  },
  data:{ 
    "customUniqueIdentifier": siteLocation + pageURL,
    "fields":"name,image,image,url,datePublished,description", 
    "limit":"3",
  },
  success: function (res){
    let bibContent = res.results;
    getHTML(bibContent);
  },
  error: function (res){
    jQuery(".bibblio-container").hide();
  }
});       