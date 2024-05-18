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

    ll t;
    cin >> t;

    if (t == 0) cout << 1;
    else if (t % 4 == 1) cout << 8;
    else if (t % 4 == 2)cout << 4;
    else if (t % 4 == 3)cout << 2;
    else if (t % 4 == 0)cout << 6;

    return 0;
}