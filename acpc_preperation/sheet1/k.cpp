#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

double LongestSegment(int n)
{

    vector<pair<double, double>> v;
    for (int i = 0; i < n; i++)
    {
        double l, r;
        cin >> l >> r;
        v.push_back({l, r});
    }

    sort(v.begin(), v.end());

    double l = v[0].first, r = v[0].second;

    double connection = 0.0;

    for (int i = 1; i < n; i++)
    {
        connection = max(connection, sqrt(pow(l - v[i].first, 2.0) + pow(r - v[i].second, 2.0)) * 1.0);
    }

    return connection;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int n;
    cin >> n;
    cout << setprecision(14) << LongestSegment(n) << '\n';

    return 0;
}
