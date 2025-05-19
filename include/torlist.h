#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>

#define TOR_EXIT_LIST_URL "https://check.torproject.org/torbulkexitlist"
#define OUTPUT_FILE "tor_exit_list.txt"

void download_tor_list(void);


