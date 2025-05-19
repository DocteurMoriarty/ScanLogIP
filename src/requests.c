#include "requests.h"

void configure_curl_file(CURL *curl, FILE *fp, const char *LINK){
    curl_easy_setopt(curl, CURLOPT_URL, LINK);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
}

void configure_curl(CURL *curl, const char *LINK){
    curl_easy_setopt(curl, CURLOPT_URL, LINK);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);
}


int fetch_requests(CURL *curl){
    CURLcode response = curl_easy_perform(curl);
    if (response != CURLE_OK)
        fprintf(
            stderr,"Erreur cURL: %s\n", 
            curl_easy_strerror(response)
        );
    return 1;
}

