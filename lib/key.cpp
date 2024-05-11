//
// Created by sinat on 5/11/2024.
//
#include <random>
#include "key.h"

uint32_t key::getWord(int i)
{
    if (i > 3)
        return -1;
    return w[i];
}

std::vector<uint8_t> key::getWordByte(int i)
{
    uint32_t word = getWord(i);
    uint8_t wb0 = word & 0x000000FF;
    uint8_t wb1 = (word & 0x0000FF00)>>8;
    uint8_t wb2 = (word & 0x00FF0000)>>16;
    uint8_t wb3 = (word & 0xFF000000)>>24;
    return std::vector<uint8_t>{wb0,wb1,wb2,wb3};
}

void key::setWord() {
    w[0] = (r_k >> 32) & 0xFFFFFFFF;
    w[1] = r_k & 0xFFFFFFFF;
    w[2] = (l_k >> 32) & 0xFFFFFFFF;
    w[3] = l_k & 0xFFFFFFFF;
}

key::key()
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<uint64_t> dis;
    l_k = dis(gen);
    r_k = dis(gen);
    setWord();
}

key::key(uint64_t l, uint64_t r)
{
    l_k = l;
    r_k = r;
    setWord();
}