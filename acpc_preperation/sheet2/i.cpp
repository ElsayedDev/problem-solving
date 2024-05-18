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

    const int N = 1e6 + 10;

    vector<ll> prime(N + 1, 0);

    prime[1] = 1;
    for (ll i = 2; i <= N; i++) {
        if (prime[i] == 0) {
            for (ll j = 2 * i; j <= N; j = j + i) {
                prime[j] = 1;
            }
        }
    }

    ll t, n;
    cin >> t;

    while (t--) {

        cin >> n;
        ll sq = (ll) sqrt(n);


        if ((sq * sq == n) && prime[sq] == 0) cout << "YES";

        else cout << "NO";
        cout << endl;


    }

    return 0;
}