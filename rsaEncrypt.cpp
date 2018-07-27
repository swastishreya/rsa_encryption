#include <bits/stdc++.h>
using namespace std;

#define DIGITS 150
#define CONST_K 123456789

struct User {
    int p1; 
    int p2;//p1 and p2 are two big primes
    int n; //Multiplication of two big primes
    int e; //publicKey
    int d; //privateKey
};

int modExp(int message, int n, int e){
    int ans = 1;
    message = message%n;
    while(e > 0){
        if(e%2 == 1)
            ans = (ans*message)%n;

        e = e/2;
        message = (message*message)%n;
    }
    return ans;
}

int EulerTot(int p1, int p2){
    return (p1-1)*(p2-1);
}

//n is equal to p1*p2 where p1 and p2 are equally big primes
//and n is visible to everyone.
//publicKey is picked such that gcd(n,publicKey) = 1

int privateKey(int k, int phi_n, int publicKey){
    return ((k*phi_n) + 1)/publicKey;
}

int publicKey(int n){
    return 0;
}

int generateBigPrime(int digits){
    return 0;
}

int main(){
    User Alice, Bob;

    Alice.p1 = generateBigPrime(DIGITS);
    Alice.p2 = generateBigPrime(DIGITS);
    Alice.n = Alice.p1*Alice.p2;
    Alice.e = publicKey(Alice.n);
    Alice.d = privateKey(CONST_K,EulerTot(Alice.p1,Alice.p2),Alice.e);

    Bob.p1 = generateBigPrime(DIGITS);
    Bob.p2 = generateBigPrime(DIGITS);
    Bob.n = Bob.p1*Bob.p2;
    Bob.e = publicKey(Bob.n);
    Bob.d = privateKey(CONST_K,EulerTot(Bob.p1,Bob.p2),Bob.e);

    int message, cipherText, decipheredText;

    cin >> message;
    cipherText = modExp(message,Alice.n,Alice.e);
    decipheredText = modExp(cipherText,Alice.n,Alice.d);
    cout << decipheredText << endl;

    
    // int p, m, alice, bob, sharedKeyA, sharedKeyB, encryptedKeyA, encryptedKeyB;
    // //p and m constitute the key Alice and Bob share
    // p = 3;
    // m = 17;
    // //Alice and Bob's private keys
    // alice = 38722;
    // bob = 46937;
    // //Alice and Bob share their encrypted keys
    // encryptedKeyA = modExp(p,m,alice);
    // encryptedKeyB = modExp(p,m,bob);

    // //Alice and Bob generate the shared secret key
    // sharedKeyA = modExp(encryptedKeyB,m,alice);
    // sharedKeyB = modExp(encryptedKeyA,m,bob);

    // if(sharedKeyA == sharedKeyB)
    //     cout << "Secret is safe!" << endl;


    return 0;
}
