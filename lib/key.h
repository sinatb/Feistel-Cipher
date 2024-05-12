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
    uint64_t k;
    uint16_t w[4];
    void setWord();

public:
    key(uint64_t k);
    key();
    uint16_t getWord(int i);
    std::vector<uint8_t> getWordByte(int i);
    uint16_t rotWord(int i);
    key generateSubKey();
    uint64_t getKey();
    void printKey();
};
#endif //FEISTEL_CIPHER_KEY_H
