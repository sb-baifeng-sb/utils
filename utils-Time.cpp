
#include "utils-Time.hpp"
#include <chrono>
#include <stdlib.h>

namespace utils {

Date stamp_to_date(int stampTime) {
    time_t tick = (time_t)stampTime;
    struct tm tm;
    char s[100];
    Date date;
    
    //tick = time(NULL);
    tm = *localtime(&tick);
    strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", &tm);
    //printf("%d: %s\n", (int)tick, s);
    
    date.Year = atoi(s);
    date.Mon = atoi(s+5);
    date.Day = atoi(s+8);
    date.Hour = atoi(s+11);
    date.Min = atoi(s+14);
    date.Second = atoi(s+17);
    
    return date;
}

std::time_t getTimeStamp() {
    std::chrono::time_point<std::chrono::system_clock,std::chrono::milliseconds> tp = std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now());
    //auto tmp = std::chrono::duration_cast<std::chrono::milliseconds>(tp.time_since_epoch());
    //std::time_t timestamp = tmp.count();
    std::time_t timestamp = std::chrono::system_clock::to_time_t(tp);
    return timestamp;
}

}