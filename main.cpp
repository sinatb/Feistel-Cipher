#include <iostream>
#include "lib/key.h"
#include "lib/feistel.h"
using namespace std;
int main() {
    key k;
    k.printKey();
    cout <<(int)k.getWordByte(3)[0]
         <<(int)k.getWordByte(3)[1]
         <<(int)k.getWordByte(3)[2]
         <<(int)k.getWordByte(3)[3]<<'\n';
    cout << k.rotWord(3) << '\n';
    feistel f(k);
    f.printSubKeys();
}
