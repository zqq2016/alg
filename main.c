#include <stdio.h>
#include "strstr_bf/strstr_bf.h"
#include "strstr_kmp/strstr_kmp.h"


extern char *gen_next(const char *pattern);
int main() {
    char *next;
    printf("%s\n", strstr_bf("Hello, World!", "lo"));
    printf("%s\n", strstr_kmp("Hello, World!", "lo"));

    return 0;
}
