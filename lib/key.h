//
// Created by sinat on 5/11/2024.
//

#ifndef FEISTEL_CIPHER_KEY_H
#define FEISTEL_CIPHER_KEY_H

#include <cstdint>
#include "iostream"
#include "vector"
class key{
private:
    uint64_t l_k;
    uint64_t r_k;
    uint32_t w[4];
    void setWord();
    uint32_t getWord(int i);
    std::vector<uint8_t> getWordByte(int i);
public:
    key(uint64_t l, uint64_t r);
    key();
};
#endif //FEISTEL_CIPHER_KEY_H
