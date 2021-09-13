#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    enum {
        GET,
        POST,
    } command;
    const char* path;
} Request;

Request parse_request(const char* str);

char* read_file(const char* file_path);
