#include <bits/stdc++.h>
// #include <common.h>

using namespace std;

#define ll long long int

void ReadDataWithSpeed() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifndef ONLINE_JUDGE

    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);

#endif
}

bool isPrime(ll n) {
    if (n <= 1) return false;

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}


int main() {
    ReadDataWithSpeed();
    ll n;
    cin >> n;
    ll lastPrime;

    for (ll i = n; i >= 2; --i) {
        if (isPrime(i)) {
            lastPrime = i;
            break;
        }
    }

    if (lastPrime == n) {
        cout << 1 << endl << lastPrime;
        return 0;
    }

    n -= lastPrime;

    if (n == 2) {
        cout << 2 << endl << 2 << ' ' << lastPrime;
        return 0;
    }

    for (ll i = 2; i <= n; ++i) {
        if (isPrime(i) && isPrime(n - i)) {
            cout << 3 << endl << i << ' ' <<(n - i)<< ' ' << lastPrime;
            return 0;

        }
    }


    return 0;
}