//CF Gym 100753K - Upside down primes

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <bitset>
#include <vector>
using namespace std;

typedef long long int ll;
typedef vector<ll> vi; 

ll tam;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
    tam = upperbound + 1;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= tam; i++) {
        if (bs[i]) {
            for (ll j = i * i; j <= tam; j += i)
                bs[j] = 0;
            primes.push_back(i);
        }
    }
}

bool isPrime(ll n) {
    if (n <= 10000000) {
        return bs[n];
    }
    else {
        for (int i = 0; i < primes.size(); i++) {
            if (primes[i] > n) break;
            if (n % primes[i] == 0)
                return false;
        }
    }
    return true;
}

ll convertir(string str) {
    ll result = 0, pot = 1;
    for (int i = str.size() - 1; i >= 0; i--) {
        result += (str[i] - 48) * pot;
        pot *= 10;
    }
    return result;
}

int main() {
    
    string num1, num2;
    
    sieve(10000000);
    cin >> num1;
    num2 = num1;
    reverse(num2.begin(), num2.end());
    for (int i = 0; i < num2.size(); i++) {
        if (num2[i] == '3' || num2[i] == '4' || num2[i] == '7') {
            cout << "no\n";
            return 0;
        }
        else if (num2[i] == '6') {
            num2[i] = '9';
        }
        else if (num2[i] == '9') {
            num2[i] = '6';
        }
    }
    ll numero = convertir(num1);
    ll numeroAlrevez = convertir(num2);

	if (isPrime(numero) && isPrime(numeroAlrevez)) {
        cout << "yes\n";
    }
    else {
        cout << "no\n";
    }
    return 0;
}
