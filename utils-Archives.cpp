//
//  archives.cpp
//
//  Created by baifeng on 2018/4/19.
//

#include "utils-Archives.hpp"

namespace utils {

Archives::Archives() {
    
}

void Archives::setStream(std::string const& str) {
    this->mStream.str(str);
}

Archives::Stream const& Archives::getStream() const {
    return this->mStream;
}

Archives::Stream& Archives::getStream() {
    return this->mStream;
}

void Archives::Get(InputFunc const& func) {
    InputArchive archive(this->mStream);
    if (func != nullptr) {
        func(archive);
    }
}

void Archives::Set(OutputFunc const& func) {
    OutputArchive archive(this->mStream);
    if (func != nullptr) {
        func(archive);
    }
}

}
