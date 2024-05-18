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


int main() {
    ReadDataWithSpeed();
    ll mod = 1e9, n;
    mod += 7;
    cin >> n;
    ll res = 1;
    for (ll i = 1; i <= n; ++i) {
        res = (res * i) % mod;
    }

    cout << res;
    return 0;
}