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

//
//ll gcd(ll a, ll b) {
//    while (b != 0) {
//        ll a2 = a;
//        a = b;
//        b = a2 % b;
//    }
//    return a;
//}
//
//ll lcm(ll a, ll b) {
//    return a / gcd(a, b) * b;
//}


int main() {
//    ReadDataWithSpeed();

    ll t;
    cin >> t;
    while (t--) {
        ll g, l;
        cin >> g >> l;

        if (l % g == 0) cout << g << " " << l << endl;
        else cout << -1 << endl;
    }
    return 0;
}