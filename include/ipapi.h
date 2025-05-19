#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "requests.h"


#define LINK_API_IPAPI "http://ip-api.com/json/"

struct memo
{
    char *response;
    size_t s; 
};


char *json_api_response(char *ip);
