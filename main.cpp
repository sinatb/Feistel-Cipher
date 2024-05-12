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
    //k.generateSubKey().printKey();
    feistel f(k);
    f.printSubKeys();
    vector<uint64_t> enc = f.encrypt(54,32);
    vector<uint64_t> dec = f.decrypt(enc[0],enc[1]);
    cout << enc[0] << enc[1] << '\n';
    cout << dec[0] <<" "<< dec[1] << '\n';
}
