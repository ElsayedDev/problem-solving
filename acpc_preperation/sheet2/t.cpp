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

vector<ll> divsVictor(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {

            if (n / i == i) {
                divs.push_back(i);
            } else {
                divs.push_back(i);
                divs.push_back(n / i);
            }

        }
    }

    return divs;
}


int main() {
    ReadDataWithSpeed();

    ll t;
    cin >> t;
    vector<ll> v;
    unordered_map<ll, int> mp;
    while (t--) {
        ll x;
        cin >> x;
        v.push_back(x);
        mp[x]++;
    }

    ll res = 0;
    for (auto e: v) {
        auto divs = divsVictor(e);
        if (mp[e] > 1) continue;

        for (auto ee: divs) {
            if (mp[ee] && ee != e) {
                goto last;
            }
        }

        res++;

        last:;
    }

    cout << res;

    return 0;
}