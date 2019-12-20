
#ifndef __UTILS_CONFIG_H__
#define __UTILS_CONFIG_H__

#include <string>
#include <map>

namespace utils {

class CParseIniFile final {
public:
    bool ReadConfig(std::string const& source, std::map<std::string, std::string>& mContent, char const* section);
    bool AnalyseLine(std::string const& line, std::string& key, std::string& val);
    void Trim(std::string& str);
    bool IsSpace(char c);
    bool IsCommentChar(char c);
    void PrintConfig(std::map<std::string, std::string> const& mContent);
};

}

#endif
