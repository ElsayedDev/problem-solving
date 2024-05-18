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

const int capacity = 1e5;

bool composite[capacity + 1];

void linearSieve(ll n) {
    vector<ll> prime;

    composite[0] = composite[1] = true;

    for (ll i = 2; i <= n; i++) {
        if (!composite[i])
            prime.push_back((i));

        for (ll j = 0; j < prime.size() && i * prime[j] <= n; j++) {

            composite[i * prime[j]] = true;

            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {

    ReadDataWithSpeed();

    linearSieve(capacity);

    ll n, m;
    cin >> n >> m;
    ll mn = INT_MAX;

    vector<vector<ll>> matrix(n, vector<ll>(m));

    for (int i = 0; i < n; ++i) {
        ll counter = -1;
        for (int j = 0; j < m; ++j) {
            // 1. insert the data
            ll x;
            cin >> x;
            matrix[i][j] = x;

            if (x <= 1) {
                if (counter == -1) counter = 0;
                counter += (2 - matrix[i][j]);
            }
            // 2. check on rows
            if (!composite[matrix[i][j]]) {
                for (ll k = matrix[i][j]; k < capacity; ++k) {
                    if (composite[k]) {
                        if (counter == -1) counter = 0;
                        counter += (k - matrix[i][j]);
                        break;
                    }
                }
            }
        }
        if (counter == -1) {
            cout << 0;


            return 0;
        } else
            mn = min(mn, counter);
    }

    if (mn == INT_MAX) {
        cout << 0;
        return 0;
    }

    // check columns
    for (int i = 0; i < m; ++i) {
        ll counter = -1;
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] <= 1) {
                if (counter == -1) counter = 0;
                counter += (2 - matrix[i][j]);
                continue;
            }

            if (!composite[matrix[j][i]]) {
                for (ll k = matrix[j][i]; k < capacity; ++k) {
                    if (composite[k]) {
                        if (counter == -1) counter = 0;
                        counter += (k - matrix[j][i]);
                        break;
                    }
                }
            }
        }

        if (counter == -1) {
            cout << 0;
            return 0;
        } else
            mn = min(mn, counter);
    }


    cout << mn;

    return 0;
}