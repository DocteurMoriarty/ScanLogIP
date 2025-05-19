#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <parametre>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *param = argv[1];
    printf("Paramètre reçu : %s\n", param);

    return EXIT_SUCCESS;
}
