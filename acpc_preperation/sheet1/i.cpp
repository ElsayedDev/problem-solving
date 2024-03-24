#include <bits/stdc++.h>
using namespace std;

// void ReadDataWithSpeed()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("../../input.txt", "r", stdin);
//     freopen("../../output.txt", "w", stdout);
// }

int CountingArrays(int n)
{
    set<string> st;
    while (n--)
    {
        int _;
        cin >> _;
        string s;
        // read the whole line
        getline(cin >> ws, s);

        st.insert(s);
    }

    return st.size();
}

int main(int argc, const char **argv)
{
    // ReadDataWithSpeed();

    int n;
    cin >> n;
    cout << CountingArrays(n);

    return 0;
}
