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

bool isAlmostPrime(ll n) {
    int primes = 0;

    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            primes++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    if (n > 1) primes++;

    if (primes == 2) return true;

    return false;
}

int main() {
    ReadDataWithSpeed();

    ll n, res = 0;
    cin >> n;
    n++;
    while (n--)
        if (isAlmostPrime(n)) res++;

    cout << res;

    return 0;
}
