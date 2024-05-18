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

ll divs(ll n) {
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        if (n % i == 0) res++;
    }

    return res;
}

int main() {
    ReadDataWithSpeed();

    ll t;
    cin >> t;

    cout << divs(t);
    return 0;
}