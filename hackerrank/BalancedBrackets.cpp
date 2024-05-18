#include <bits/stdc++.h>
using namespace std;

bool isPair(char l, char r)
{
    return (l == '(' && r == ')') || (l == '{' && r == '}') || (l == '[' && r == ']');
}

string isBalanced(string s)
{
    stack<char> st;
    for (auto c : s)
    {
        if (c == '(' || c == '{' || c == '[')
            st.push(c);
        else
        {
            if (st.empty() || !isPair(st.top(), c))
                return "NO";
            st.pop();
        }
    }
    int a;
    switch (a)
    {
    case 4:
        /* code */
        break;
    case 2:
        /* code */
        break;

    default:
        break;
    }
    return st.empty() ? "YES" : "NO";
}
