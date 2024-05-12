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

std::vector<uint64_t> feistel::encrypt(uint64_t lpt,uint64_t rpt)
{
    uint64_t r1 = calcFeistelRound(subKeys[0],lpt,rpt);
    uint64_t r2 = calcFeistelRound(subKeys[1],rpt,r1);
    uint64_t r3 = calcFeistelRound(subKeys[2],r1,r2);
    uint64_t r4 = calcFeistelRound(subKeys[3],r2,r3);
    return {r4,r3};
}
std::vector<uint64_t> feistel::decrypt(uint64_t lct, uint64_t rct)
{
    uint64_t r1 = calcFeistelRound(subKeys[3],lct,rct);
    uint64_t r2 = calcFeistelRound(subKeys[2],rct,r1);
    uint64_t r3 = calcFeistelRound(subKeys[1],r1,r2);
    uint64_t r4 = calcFeistelRound(subKeys[0],r2,r3);
    return {r4,r3};
}
uint64_t feistel::calcFeistelRound(key r_k, uint64_t l, uint64_t r)
{
    uint64_t r_k_u = r_k.getKey();
    uint64_t tmp = r ^ r_k_u;
    return tmp ^ l;
}

