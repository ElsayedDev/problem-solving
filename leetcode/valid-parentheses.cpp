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

    map<char, char> parentheses = {
        {'{', '}'},
        {'(', ')'},
        {'[', ']'},
    };

    bool stackSolution(string s)
    {
        stack<char> st;

        for (auto element : s)
        {
            if (element == '{' || element == '(' || element == '[')
                st.push(parentheses[element]);

            else if (st.empty())
                return false;
            else
            {
                char e = st.top();
                st.pop();
                if (e != element)
                    return false;
            }
        }

        return st.empty();
    }

public:
    bool isValid(string s)
    {

        return stackSolution(s);
    }
};

int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    cout << solution.isValid("()[]{}") << endl;

    return 0;
}
