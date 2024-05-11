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
public:
    feistel(key k);
    void printSubKeys();
};
#endif //FEISTEL_CIPHER_FEISTEL_H
