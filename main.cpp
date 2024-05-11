#include <iostream>
#include "lib/key.h"
using namespace std;
int main() {
    key k;
    cout <<std::hex<<k.getWord(0)<<k.getWord(1)<<k.getWord(2)<<k.getWord(3)<<'\n';
    cout <<(int)k.getWordByte(3)[0]
         <<(int)k.getWordByte(3)[1]
         <<(int)k.getWordByte(3)[2]
         <<(int)k.getWordByte(3)[3]<<'\n';
    cout << k.rotWord(3) << '\n';
}
