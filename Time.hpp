
#ifndef __UTILS_TIME_H__
#define __UTILS_TIME_H__

#include <ctime>

namespace utils {

typedef struct {
    unsigned int Year;
    unsigned int Mon;
    unsigned int Day;
    unsigned int Hour;
    unsigned int Min;
    unsigned int Second;
} Date;

Date stamp_to_date(int stampTime); // 时间戳转日期
std::time_t getTimeStamp(); // 获取时间戳

}

#endif