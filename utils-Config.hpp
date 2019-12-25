
#ifndef __UTILS_CONFIG_H__
#define __UTILS_CONFIG_H__

#include <sstream>
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

class INILoader {
public:
    typedef std::map<std::string, std::string> Config;
    typedef std::map<std::string, Config> ConfigMap;
public:
    virtual ~INILoader() {}
public:
    class Session {
    public:
        explicit Session(Config const& conf):mConfig(conf) {}
    public:
        template <class Type>
        static Type stringToNum(std::string const& str) {
            std::istringstream iss(str);
            Type num = 0;
            iss >> num;
            return num;
        }
    public:
        int getInt(std::string const& name) const {
            auto& v = this->getString(name);
            if (v.length() == 0) {
                return 0;
            }
            return stringToNum<int>(v);
        }
        std::string const& getString(std::string const& name) const {
            auto iter = this->mConfig.find(name);
            if (iter != this->mConfig.end()) {
                return iter->second;
            }
            return mValue;
        }
        double getDouble(std::string const& name) const {
            auto& v = this->getString(name);
            if (v.length() == 0) {
                return 0.0f;
            }
            return stringToNum<double>(v);
        }
    protected:
        std::string mValue;
        Config const& mConfig;
    };
    typedef std::map<std::string, Session> SessionMap;
    typedef std::string const& ssc;
public:
    Session const& getSession(ssc name) const;
public:
    void load(std::string const& source, ssc s1);
    void load(std::string const& source, ssc s1, ssc s2) {
        this->load(source, s1);
        this->load(source, s2);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3, ssc s4) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
        this->load(source, s4);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3, ssc s4, ssc s5) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
        this->load(source, s4);
        this->load(source, s5);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3, ssc s4, ssc s5, ssc s6) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
        this->load(source, s4);
        this->load(source, s5);
        this->load(source, s6);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3, ssc s4, ssc s5, ssc s6, ssc s7) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
        this->load(source, s4);
        this->load(source, s5);
        this->load(source, s6);
        this->load(source, s7);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3, ssc s4, ssc s5, ssc s6, ssc s7, ssc s8) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
        this->load(source, s4);
        this->load(source, s5);
        this->load(source, s6);
        this->load(source, s7);
        this->load(source, s8);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3, ssc s4, ssc s5, ssc s6, ssc s7, ssc s8, ssc s9) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
        this->load(source, s4);
        this->load(source, s5);
        this->load(source, s6);
        this->load(source, s7);
        this->load(source, s8);
        this->load(source, s9);
    }
    void load(std::string const& source, ssc s1, ssc s2, ssc s3, ssc s4, ssc s5, ssc s6, ssc s7, ssc s8, ssc s9, ssc s10) {
        this->load(source, s1);
        this->load(source, s2);
        this->load(source, s3);
        this->load(source, s4);
        this->load(source, s5);
        this->load(source, s6);
        this->load(source, s7);
        this->load(source, s8);
        this->load(source, s9);
        this->load(source, s10);
    }
protected:
    ConfigMap mConfigs;
    SessionMap mSessions;
};

}

#endif
