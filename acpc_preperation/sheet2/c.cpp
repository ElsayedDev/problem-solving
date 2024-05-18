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


vector<ll> linearSieveByTarget(ll target, ll capacity) {

    bool composite[capacity + 1];
    vector<ll> prime;

    composite[0] = composite[1] = true;

    for (ll i = 2; i <= capacity; i++) {
        if (!composite[i]) prime.push_back((i));

        for (ll j = 0; j < prime.size() && i * prime[j] <= capacity; j++) {

            composite[i * prime[j]] = true;

            if (prime.size() == target) return prime;

            if (i % prime[j] == 0) break;

        }

        if (prime.size() == target) return prime;

    }

    return prime;

}

int main() {

    ReadDataWithSpeed();

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        auto v = linearSieveByTarget(n, 1000001);
        cout << v[n - 1] << endl;
    }


    return 0;
}