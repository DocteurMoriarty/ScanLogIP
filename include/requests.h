#include <curl/curl.h>
#include <stdio.h>


void configure_curl_file(
    CURL *curl, 
    FILE *fp, 
    const char *LINK
);

void configure_curl(
    CURL *curl, 
    const char *LINK
);


int fetch_requests(
    CURL *curl
);