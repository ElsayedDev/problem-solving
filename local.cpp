#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

class Solution1
{
private:
    string leftShifting(int n, string s)
    {
        return s.substr(1, n) + s.substr(0, 1);
    }

public:
    int checkShifting(int n, string s, string temp)
    {
        if (s == temp)
            return 0;

        string left = s;

        int leftCounter = 0;

        while (left != temp)
        {
            left = leftShifting(n, left);

            leftCounter++;
        }

        if (leftCounter > n / 2)
            return n - leftCounter;
        return leftCounter;
    }
};

class Solution2
{

    void check(int n, string s, string temp, int *i, int *k)
    {

        for (; *i < n; *i += 1)
            if (s[*i] != temp[*i])
                break;

        for (*k = *i; *k < n; *k += 1)
            if (s[*k] == temp[*i])
                break;
    }

public:
    ll checkShifting(int n, string s, string temp)
    {
        int i = 0, k;

        // while (i < n)

        check(n, s, temp, &i, &k);

        check(n, s, temp, &i, &k);

        cout << i << " " << k << endl;

        return 0;
    }
};

int main()
{
    ReadDataWithSpeed();

    int n;
    string s, temp;
    cin >> n >> s >> temp;
    Solution2 solution = Solution2();

    cout
        << solution.checkShifting(n, s, temp);

    return 0;
}
