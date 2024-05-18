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

    ll n;
    cin >> n;
    vector<ll> res;
    while (n > 1) {
        if (n <= 3) {
            res.push_back(n);
            break;
        }
        res.push_back(2);
        n -= 2;
    }
    cout << res.size() << endl;
    for (auto e: res) cout << e << " ";


    return 0;
}