//
// Created by baifeng on 2020/3/31.
//

#include "utils-Poker.hpp"
#include <assert.h>

namespace utils {

    Poker::Poker()
            : mCards(nullptr), mCardSize(0) {

    }

    Poker::~Poker() {
        this->Clear();
    }

    void Poker::Load(int size, CardLoader const &loader) {
        assert(size > 0 && "Poker::Load size can't be zero.");
        this->Clear();
        this->mCards = new Card[size];
        this->mCardSize = size;
        memset(this->mCards, 0, sizeof(Card) * size);
        if (loader != nullptr) {
            loader(this->mCards, this->mCardSize);
        }
    }

    int Poker::operator[](int i) const {
        if (i <= -1 || i >= this->mCardSize) {
            return JOKER;
        }
        return this->mCards[i];
    }

    int Poker::getCount() const {
        return this->mCardSize;
    }

    int Poker::Get(int i) const {
        return (*this)[i];
    }

    void Poker::Shuffle() {
        assert(this->mCards && this->mCardSize > 0 && "Poker::Shuffle there is no card.");
        for (int i = 0; i < this->mCardSize; ++i) {
            auto newIndex = rand() % this->mCardSize;
            if (newIndex == i) {
                continue;
            }
            auto value = this->mCards[i];
            this->mCards[i] = this->mCards[newIndex];
            this->mCards[newIndex] = value;
        }
    }

    void Poker::Clear() {
        if (mCards) {
            delete mCards;
            mCards = nullptr;
        }
        this->mCardSize = 0;
    }

    void Poker::Debug() {
        for (int i = 0; i < this->mCardSize; ++i) {
            printf("%d ", this->mCards[i]);
        }
        printf("\n");
    }

}
