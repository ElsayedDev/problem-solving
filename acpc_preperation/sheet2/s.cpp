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
    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,
                          97};
    ll t;
    cin >> t;
    while (t--) {
        ll q;
        cin >> q;

        if (q < 2) {
            cout << 0 << endl;
            continue;
        }


        ll prod = 2;
        int i = 1;

        for (; prod < (q / 2) && i < 25; i++) {
            prod *= primes[i];
        }

        cout << i << endl;
    }

    return 0;
}