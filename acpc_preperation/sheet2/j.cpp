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

ll numDivs(ll n) {
    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        if (n % i == 0)
            res++;
    }
    return res;
}

unordered_map<ll, ll> EasyNumberChallenge(ll i, ll j, ll k) {
    unordered_map<ll, ll> mp;
    for (ll a = 1; a <= i; ++a) {
        for (ll b = 1; b <= j; ++b) {
            for (ll c = 1; c <= k; ++c) {
                mp[a * b * c]++;
            }
        }
    }
    return mp;
}

int main() {
    ReadDataWithSpeed();

    ll a, b, c, sum = 0;
    cin >> a >> b >> c;

    // number , counter
    unordered_map<ll, ll> mp = EasyNumberChallenge(a, b, c);

    for (auto e: mp)
//        cout << e.first << " " << e.second << endl;
        sum+= numDivs(e.first) * e.second;

    cout << sum;
    return 0;
}