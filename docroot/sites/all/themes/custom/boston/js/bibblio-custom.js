 /*polyfill for IE11*/
 Array.prototype.findIndex = Array.prototype.findIndex || function(callback) {
  if (this === null) {
    throw new TypeError('Array.prototype.findIndex called on null or undefined');
  } else if (typeof callback !== 'function') {
    throw new TypeError('callback must be a function');
  }
  var list = Object(this);
  // Makes sures is always has an positive integer as length.
  var length = list.length >>> 0;
  var thisArg = arguments[1];
  for (var i = 0; i < length; i++) {
    if ( callback.call(thisArg, list[i], i, list) ) {
      return i;
    }
  }
  return -1;
};

/*get Bibblio recs and check for image*/
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
    //findItem = randImgObj.findIndex(i => i.desc === randImgObj[num].desc); 
    findItem = randImgObj.findIndex(function (x) {
          return x.desc === randImgObj[num].desc
    });
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
var checkBadDesc = function (word){
  return new RegExp('back to top', 'i').test(word);
}

//populate HTML container element with recommendation
var populateHTML = function(bibContent){
  var listItem = '';
  var listLength = 0
  jQuery(bibContent).each(function(index,value){
      if(listLength > 2){return false}
      
      let imgInfo;
      let bibFields = value.fields;    
      let checkImg = bibFields.image;

      if(checkImg == null){
        imgInfo = getImgRand() 
      }else{
        imgInfo = getImgBibblio(bibFields)
      }

      let bibName = bibFields.name;
      let bibUrl = bibFields.url;
      let bibDesc = bibFields.description;
      if(checkBadDesc(bibDesc) === false && bibDesc !== ""){
        listItem += '<a class= "cd g--4 g--4--sl m-t500 bibblio" bibblio-title="'+bibName+'" bibblio-img-desc="'+imgInfo.desc+'" href="'+bibUrl+'"><div class="cd-ic" style="background-image:url('+ imgInfo.path +')" ><\/div><div class="cd-c"><div class="cd-t">'+bibName+'<\/div><div class="cd-d"\>'+bibDesc+'<\/div><\/div><\/a>';
        listLength++;
      }
      //console.log(checkBadDesc(bibDesc) + ':' + bibName + ':' + bibDesc);      
  });

  if(listLength > 0){
    jQuery("#bibblio-custom div.g").append(listItem);
    jQuery(".bibblio-container").show();
  }
}

// Check if page has existing recommendations.
const pageURL = window.location.pathname;
const siteLocation = 'https://www.boston.gov';
jQuery.ajax({
  method: "GET",
  crossDomain: true,
  cache : false,
  url: "https://api.bibblio.org/v1/recommendations",
  contentType: "application/json",
  headers: {
    "Authorization": "Bearer 852cf94f-5b38-4805-8b7b-a50c5a78609b"
  },
  data:{ 
    "customUniqueIdentifier": siteLocation + pageURL,
    "fields":"name,image,image,url,datePublished,description,keywords", 
    "limit":"6",
  },
  success: function (res){
    if(jQuery('body').hasClass('node-type-how-to')){
        let bibContent = res.results;
        populateHTML(bibContent);
    }
    let itemId = res._links.sourceContentItem.id;
    getItemData(itemId);
    //alert('success recommendation');
    //console.log(bibContent);
  },
  error: function (res){
    if(res.status == 404){
      ingestItem();
    }
  }
});

// Get content item data to prep for insertion.
var getItemData = function(item_id){
      jQuery.ajax({
        method: "GET",
        crossDomain: true,
        cache : false,
        url: "https://api.bibblio.org/v1/content-items/" + item_id,
        contentType: "application/json",
        headers: {
          "Authorization": "Bearer 852cf94f-5b38-4805-8b7b-a50c5a78609b"
        },
        success: function (res){
          reIngestItem(res);
        },
        error: function (res){
          console.log('Error ingesting item to Bibblio.');
        }
      });
}

// Ingest and associate with new catalogue ID. 
var ingestItem = function(){
      let getJSON_LD = jQuery('script[type="application/ld+json"]')[0].innerHTML;
      getJSON_LD = JSON.parse(getJSON_LD);
      getJSON_LD = jsonldN["@graph"][0];
      jQuery.ajax({
        method: "POST",
        crossDomain: true,
        cache : false,
        url: "https://api.bibblio.org/v1/content-items/" + res.contentItemId,
        contentType: "application/json",
        headers: {
          //live boston.gov key
          "Authorization": "Bearer 852cf94f-5b38-4805-8b7b-a50c5a78609b"
        },
        data:{
          "url": siteLocation + pageURL,
          "name": getJSON_LD.name,
          "text": getJSON_LD.description,
          "customUniqueIdentifier": res.customUniqueIdentifier,
          "image": {
                  "contentUrl": getJSON_LD.image.url
              },
          "moduleImage": {
                  "contentUrl": getJSON_LD.image.url
              },
          "catalogueId" : "ea9dbde3-dac4-4c1a-b887-55843fd8ed2f"
        },
        success: function (res){
          alert('success ingest');
        },
        error: function (res){
          alert('error ingest');
        }
      });
     
}

// Re-ingest and associate with new catalogue ID.
var reIngestItem = function(res){
      jQuery.ajax({
        method: "PUT",
        crossDomain: true,
        cache : false,
        url: "https://api.bibblio.org/v1/content-items/" + res.contentItemId,
        contentType: "application/json",
        headers: {
          //live boston.gov key
          "Authorization": "Bearer 852cf94f-5b38-4805-8b7b-a50c5a78609b"
        },
        data:{
          "url": res.url,
          "name": res.name,
          "text": res.text,
          "customUniqueIdentifier": res.customUniqueIdentifier,
          "image": {
                  "contentUrl": res.image.contentUrl
              },
          "moduleImage": {
                  "contentUrl": res.moduleImage.contentUrl
              },
          "catalogueId" : "ea9dbde3-dac4-4c1a-b887-55843fd8ed2f"
        },
        success: function (res){
          alert('success ingest');
        },
        error: function (res){
          alert('error ingest');
        }
      });
}