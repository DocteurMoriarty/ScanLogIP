#include "ipapi.h"
#

char *json_api_response(char *ip){
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Erreur d'initialisation de cURL\n");
        return;
    }

    char url[256]; 
    snprintf(url, sizeof(url), "%s%s/json/", LINK_API_IPAPI, ip);

    printf(url);

    configure_curl(curl, LINK_API_IPAPI);
    fetch_requests(curl);

    curl_easy_cleanup(curl);
}