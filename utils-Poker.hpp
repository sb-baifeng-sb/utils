//
// Created by baifeng on 2020/3/31.
//

#ifndef __UTILS_POKER_H__
#define __UTILS_POKER_H__

#include <stdio.h>
#include <functional>

namespace utils {

    class Poker {
    public:
        typedef unsigned char Card;
        typedef std::function<void(Card *p, int size)> CardLoader;
    public:
        enum {
            JOKER = -1
        };
    public:
        Poker();
        ~Poker();
    public:
        void Load(int size, CardLoader const &loader);
        void Shuffle();
        void Clear();
        void Debug();
    public:
        int operator[](int i) const;
        int getCount() const;
        int Get(int i) const;
    private:
        Card *mCards;
        int mCardSize;
    };

}

#endif //__UTILS_POKER_H__
