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

/*
 *
 * first divisor (a) of x is the first common between l & g
 * so:
 * g = a * l
 *
 * g + l = x
 *
 * l ( a + 1 ) = x
 *
 *
 * */
int main() {
    ReadDataWithSpeed();

    ll t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << 1 << " " << (x - 1) << endl;
    }
    return 0;
}