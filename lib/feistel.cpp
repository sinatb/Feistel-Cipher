//
// Created by sinat on 5/11/2024.
//
#include "feistel.h"

feistel::feistel(key k)
{
    feistel::k = k;
    generateSubKeys();
}

void feistel::generateSubKeys()
{
    subKeys[0] = k.generateSubKey();
    subKeys[1] = subKeys[0].generateSubKey();
    subKeys[2] = subKeys[1].generateSubKey();
    subKeys[3] = subKeys[2].generateSubKey();
}

void feistel::printSubKeys()
{
    for (auto sk : subKeys) {
        sk.printKey();
    }
}
