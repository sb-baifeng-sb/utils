
#include "Files.hpp"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

namespace utils {

FileData* readFileData(char const* fileName) {
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        return NULL;
    }
    
    FileData* data = (FileData*)malloc(sizeof(FileData));
    memset(data, 0, sizeof(FileData));
    
    fseek(fp, 0, SEEK_END);
    data->bufSize = (int)ftell(fp);
    fseek(fp, 0, SEEK_SET);
    data->buffer = (unsigned char*)malloc(data->bufSize);
    memset(data->buffer, 0, data->bufSize);
    
    fread(data->buffer, data->bufSize, 1, fp);
    fclose(fp);
    return data;
}

void freeFileData(FileData* data) {
    if (data != NULL) {
        if (data->buffer != NULL) {
            free(data->buffer);
        }
        free(data);
    }
}

}