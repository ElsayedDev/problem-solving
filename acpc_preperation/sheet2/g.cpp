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


void kFactorization(ll n, ll k) {
    vector<ll> res;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
        res.push_back(n);

    if (res.size() < k) {
        cout << -1;
        return;
    }

    ll sum = 1, i = 0;

    for (ll re: res) {
        if (i < k - 1) {
            cout << re << " ";
            i++;
        } else {
            sum *= re;
        }
    }

    cout << sum;
}

int main() {

    ReadDataWithSpeed();

    ll n, k;
    cin >> n >> k;

    kFactorization(n, k);
    return 0;
}