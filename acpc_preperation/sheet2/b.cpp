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


ll largestPrime(ll n) {
    vector<ll> res;

    for (ll i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
        res.push_back(n);

    return *max(res.begin(), res.end() - 1);
}

int main() {
//    ReadDataWithSpeed();

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll res = largestPrime(n);

        cout << res << endl;
    }

    return 0;
}