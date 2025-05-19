#include <curl/curl.h>
#include <stdio.h>


void configure_curl(
    CURL *curl, 
    FILE *fp, 
    const char *LINK
);


int fetch_requests(
    CURL *curl
);