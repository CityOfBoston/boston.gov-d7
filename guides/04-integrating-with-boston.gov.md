# Integrating with Boston.gov

Boston.gov integrates (or will integrate) with many services across the City. Here is a run down of the methods for integrating with the website.

## Ingesting APIs

Depending on the level of complexity, a restful API can be used to integrate with Boston.gov. Currently, the CityScore module connects to an API to display data on the [CityScore](https://www.boston.gov/cityscore) page.

Some things to keep in mind when building against an API. 

 1. Try to use existing modules when possible. We currently utilize a Salesforce module to bring data in for MetroList. 
 1. Use migrations if possible to store data locally when the data doesn't change frequently and isn't likey to grow exponentially. This allows us to use Views within the sites.
 
## Providing APIs

Boston.gov provides some APIs of it's data. Currently, the following APIs are available:

### Upcoming Events

The next five upcoming events can be retrieved in JSON format from `/api/v1/upcoming-events`. 

### Public Notices

All upcoming public notices can be retrieved from `/api/v1/public-notices`. This is rendered in JSON format.

### Blank Layouts

Blank layouts that can be used by external applications exist at `/api/v1/layouts`. Currently, only `/api/v1/layouts/search` is available, but more will be added.

The blank layouts should be used by external applications to provide wrapper HTML. This will also provide the necessary updates to navigation as things change at Boston.gov.

In the search example, we include the necessary `<%= yield %>` tag that is used by our Rails based search application.
