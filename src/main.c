#include <stdio.h>
#include <stdlib.h>
#include "torlist.h"

int main(int argc, char *argv[]) {

    download_tor_list();

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <parametre>\n", argv[0]);
        return EXIT_FAILURE;
    }
    


    printf("Paramètre reçu : %s\n", argv[1]);
    return EXIT_SUCCESS;
}


