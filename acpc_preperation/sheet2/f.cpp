#include <bits/stdc++.h>
// #include <common.h>

using namespace std;

#define ll long long int

//void ReadDataWithSpeed() {
//    cin.tie(nullptr)->sync_with_stdio(false);
//
//#ifndef ONLINE_JUDGE
//
//    freopen("./input.txt", "r", stdin);
//    freopen("./output.txt", "w", stdout);
//
//#endif
//}

ll mxDivs(ll n) {
    vector<ll> v;
    for (ll i = 1; i <= n; ++i) {
        if (n % (i * i) == 0) v.push_back(i);
    }

    return *max(v.begin(), v.end() - 1);
}

int main() {
//    ReadDataWithSpeed();

    ll t;
    cin >> t;
    while (t--) {
        ll l, b;
        cin >> l >> b;

        ll product = l * b;

        ll mx = mxDivs(product);

        cout << (product / (mx * mx)) << endl;

    }

    return 0;
}