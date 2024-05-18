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

    ll a, b;
    cin >> a >> b;
    ll mn = min(a, b), res = 1;

    for (int i = 1; i <= mn; ++i)
        res *= i;

    cout << res;


    return 0;
}