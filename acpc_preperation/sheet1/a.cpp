#include <bits/stdc++.h>
using namespace std;

 void ReadDataWithSpeed()
 {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);

     freopen("../../input.txt", "r", stdin);
     freopen("../../output.txt", "w", stdout);
 }

bool vanishing_pitch(int v, int t, int s, int d)
{

    return v * s < d || v * t > d;
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int v, t, s, d;
    cin >> v >> t >> s >> d;
    vanishing_pitch(v, t, s, d) ? cout << "Yes" : cout << "No";

    return 0;
}
