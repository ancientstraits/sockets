#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    const char* string =
        "GET /page?key=value HTTP/1.1\n"
        "actual page"
    ;
    printf("str:\n%s\n", string);

    const char* ln = strchr(string, '\n');
    printf("(char)ln: %s\n", ln);
    printf("(int)ln:  %d\n", ln);
    printf("(int)ln:  %d\n", *ln);
}