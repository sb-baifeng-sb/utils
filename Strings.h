
#ifndef __UTILS_STRINGS_H__
#define __UTILS_STRINGS_H__

#include <string>
#include <vector>

namespace utils {

std::vector<std::string> split(const  std::string& s, const std::string& delim);
std::string& replace_str(std::string& str, std::string const& to_replaced, std::string const& newchars);

}

#endif