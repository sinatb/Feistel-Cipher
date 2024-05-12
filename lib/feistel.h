//
// Created by sinat on 5/11/2024.
//

#ifndef FEISTEL_CIPHER_FEISTEL_H
#define FEISTEL_CIPHER_FEISTEL_H
#include "key.h"
class feistel{
private:
    key k;
    key subKeys[4];
    void generateSubKeys();
    uint64_t calcFeistelRound(key r_k, uint64_t l, uint64_t r);
public:
    feistel(key k);
    void printSubKeys();
    std::vector<uint64_t> encrypt(uint64_t lpt,uint64_t rpt);
    std::vector<uint64_t> decrypt(uint64_t lct,uint64_t rct);
};
#endif //FEISTEL_CIPHER_FEISTEL_H
