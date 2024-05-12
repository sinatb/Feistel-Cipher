//
// Created by sinat on 5/11/2024.
//
#include <random>
#include "key.h"

uint16_t key::getWord(int i)
{
    if (i > 3)
        return -1;
    return w[i];
}

std::vector<uint8_t> key::getWordByte(int i)
{
    uint8_t wb0 = (w[i] >> 12) & 0xF;
    uint8_t wb1 = (w[i] >> 8) & 0xF;
    uint8_t wb2 = (w[i] >> 4) & 0xF;
    uint8_t wb3 = w[i] & 0xF;
    return {wb0,wb1,wb2,wb3};
}

void key::setWord() {
    w[0] = (k >> 48) & 0xFFFF;
    w[1] = (k >> 32) & 0xFFFF;
    w[2] = (k >> 16) & 0xFFFF;
    w[3] = k & 0xFFFF;
}

key::key()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis;
    k = dis(gen);
    setWord();
}

key::key(uint64_t k)
{
    key::k = k;
    setWord();
}

uint16_t key::rotWord(int i)
{
    auto v = getWordByte(i);
    if (v.empty())
        return -1;
    return (v[1]<<12 | v[2]<<8 | v[3]<<4 | v[0]);
}

key key::generateSubKey()
{
    uint16_t rotw3 = rotWord(3);
    uint64_t w4 = w[0] ^ rotw3;
    uint64_t w5 = w[1] ^ w4;
    uint64_t w6 = w[2] ^ w5;
    uint64_t w7 = w[3] ^ w6;
    uint64_t n_k = (w4 << 48) | (w5 << 32) | (w6 << 16) | w7;
    return key(n_k);
}

void key::printKey()
{
    std::cout<< std::hex <<
    w[0]<<
    w[1]<<
    w[2]<<
    w[3]<<'\n';
}

uint64_t key::getKey()
{
    return k;
}