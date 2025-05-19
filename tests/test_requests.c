#include <criterion/criterion.h>
#include <curl/curl.h>
#include <stdio.h>

#include "requests.h"


Test(requests, configure_curl_does_not_crash) {
    CURL *curl = curl_easy_init();
    FILE *fp = fopen("/dev/null", "wb");

    cr_assert_not_null(curl, "Échec de l'initialisation de cURL");
    cr_assert_not_null(fp, "Impossible d’ouvrir /dev/null");

    configure_curl(curl, fp, "https://google.com");

    cr_assert(1, "configure_curl() a été appelée sans erreur");
    curl_easy_cleanup(curl);
    fclose(fp);
}

Test(requests, fetch_requests_real_network_call) {
    CURL *curl = curl_easy_init();
    FILE *fp = fopen("/dev/null", "wb");

    cr_assert_not_null(curl);
    cr_assert_not_null(fp);

    configure_curl(curl, fp, "https://google.com");

    int result = fetch_requests(curl);
    cr_assert_eq(result, 1, "fetch_requests doit retourner 1 même si la requête échoue");

    curl_easy_cleanup(curl);
    fclose(fp);
}
