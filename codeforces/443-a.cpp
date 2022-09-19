#include <bits/stdc++.h>

using namespace std;
int main()
{
    set<char> se;

    for (int i = 0;; i++)
    {
        char c;
        cin >> c;
        if (c == 125)
        {
            break;
        }
        
        switch (c)
        {

        case '{':
        case '}':
        case ',':
        case ' ':

            break;

        default:

            se.insert(c);

        }
    }
    cout << se.size();
}
