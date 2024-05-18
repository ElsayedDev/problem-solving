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

pair<int, int> divs(int a) {
    int s = 0, n = 0;
    for (int i = 1; i <= a; ++i) {
        if (a % i == 0) {
            s += i;
            n++;
        }
    }
    return {n, s};
}

vector<int> common(int a, int b, int k) {
    vector<int> res;

    for (int i = a; i <= b; ++i) {
        if (i % k == 0) res.push_back(i);
    }


    return res;
}

int main() {
    ReadDataWithSpeed();

    ll t;
    cin >> t;
    while (t--) {

        int a, b, k;
        cin >> a >> b >> k;

        auto v = common(a, b, k);


        int f = 0, s = 0;

        for (auto element: v) {
            pair<int, int> pairs = divs(element);
            f += pairs.first;
            s += pairs.second;
        }

        cout << f << " " << s << endl;

    }
    return 0;
}