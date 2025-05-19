#include "requests.h"
#include "openfile.h"

#include "torlist.h"



void download_tor_list() {
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Erreur d'initialisation de cURL\n");
        return;
    }

    FILE *fp = open_file(OUTPUT_FILE);
    if (!fp) {
        curl_easy_cleanup(curl);
        return;
    }

    configure_curl_file(curl, fp, TOR_EXIT_LIST_URL);
    fetch_requests(curl);

    fclose(fp);

    curl_easy_cleanup(curl);
}