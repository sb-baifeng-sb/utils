
#ifndef __UTILS_FILES_H__
#define __UTILS_FILES_H__

namespace utils {

typedef struct {
    unsigned char* buffer;
    int bufSize;
} FileData;

FileData* readFileData(char const* fileName);
void freeFileData(FileData* data);

}

#endif
