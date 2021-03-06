//
//  archives.hpp
//  https://github.com/USCiLab/cereal
//  Created by baifeng on 2018/4/19.
//

#ifndef __UTILS_ARCHIVES_H__
#define __UTILS_ARCHIVES_H__

#include <stdio.h>
#include "cereal/cereal.hpp"
#include "cereal/archives/binary.hpp"
#include "cereal/types/map.hpp"
#include "cereal/types/vector.hpp"
#include "cereal/types/string.hpp"
#include "cereal/types/complex.hpp"

namespace utils {

class Archives {
public:
    typedef std::stringstream Stream;
    typedef cereal::BinaryOutputArchive OutputArchive;
    typedef cereal::BinaryInputArchive InputArchive;
    typedef std::function<void(OutputArchive& ar)> OutputFunc;
    typedef std::function<void(InputArchive& ar)> InputFunc;
public:
    Archives();
public:
    void setStream(std::string const& str);
    Stream const& getStream() const;
    Stream& getStream();
public:
    void Get(InputFunc const& func);
    void Set(OutputFunc const& func);
private:
    Stream mStream;
};

/*
    template <class Archive>
    void save( Archive & ar ) const {
        ar( data );
    }
    template <class Archive>
    void load( Archive & ar ) {
        ar( data );
    }
 */

}

#endif /* __UTILS_ARCHIVES_H__ */
