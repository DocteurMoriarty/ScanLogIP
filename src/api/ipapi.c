#include "ipapi.h"

char *json_api_response(char *ip) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Erreur d'initialisation de cURL\n");
        return NULL;
    }

    char url[256]; 
    snprintf(url, sizeof(url), "%s%s", LINK_API_IPAPI, ip);

    printf("%s\n", url);  

    configure_curl(curl, url); 

    fetch_requests(curl); 

    curl_easy_cleanup(curl);

    return NULL;
}
