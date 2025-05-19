#include "openfile.h"


FILE *open_file(const char *filename){
    FILE *fp = fopen(filename, "wb ");
    !fp
    ?perror("Ouverture du fichier impossible !")
    :NULL;
    return fp;
}


