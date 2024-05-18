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

vector<ll> linearSieveVector(ll n) {

    bool composite[n];
    vector<ll> primes;

    composite[0] = composite[1] = true;

    for (ll i = 2; i <= n; i++) {
        if (!composite[i]) primes.push_back((i));

        for (ll j = 0; j < primes.size() && i * primes[j] <= n; j++) {

            composite[i * primes[j]] = true;

            if (i % primes[j] == 0) break;

        }
    }

    return primes;
}

int main() {

//    ReadDataWithSpeed();

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        auto v = linearSieveVector(n);

        ll sum = 0;
        for (auto e: v)
            sum += e;


        cout << sum << endl;

    }


    return 0;
}