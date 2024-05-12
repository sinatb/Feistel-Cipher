#include <iostream>
#include "lib/key.h"
#include "lib/feistel.h"
using namespace std;
int main()
{
    uint64_t p1,p2;
    cout << "Enter the 2 numbers you want to encrypt : " << '\n';
    cin >> p1 >> p2;
    key k;
    cout << "The random key is : " << '\n';
    k.printKey();
    cout << "The rotWord function result on the 3rd word is : " << '\n';
    cout << k.rotWord(3) << '\n';
    feistel f(k);
    cout << "The subkeys are : " << '\n';
    f.printSubKeys();
    vector<uint64_t> enc = f.encrypt(p1,p2);
    vector<uint64_t> dec = f.decrypt(enc[0],enc[1]);
    cout << "Result after encryption is :" << '\n';
    cout << enc[0] << enc[1] << '\n';
    cout << "Result after decryption is :" << '\n';
    cout << std::dec << dec[0] <<" "<< dec[1] << '\n';
}
