#include "clean.h"

void free_memory(void **ptr){
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL;
    }
}