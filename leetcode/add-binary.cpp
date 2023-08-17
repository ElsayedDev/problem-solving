#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

class Solution
{

public:
    string addBinary(string a, string b)
    {

        string result = "";

        int i = a.length() - 1, j = b.length() - 1, carry = 0;

        while (i >= 0 || j >= 0)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            result += to_string(sum % 2);
            carry = sum / 2;
        }
        if (carry != 0)
            result += to_string(carry);

        reverse(result.begin(), result.end());

        return result;
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();
    cout << solution.addBinary("11", "1");

    return 0;
}
