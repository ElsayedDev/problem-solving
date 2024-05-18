#include <bits/stdc++.h>
using namespace std;

class TextEditor
{

private:
    stack<string> _undo;
    string s = "";

public:
    void append(string w)
    {
        _undo.push(s);
        s += w;
    }

    void del(int k)
    {
        _undo.push(s);
        s = s.substr(0, s.size() - k);
    }

    void print(int k)
    {
        cout << s[k - 1] << endl;
    }

    void undo()
    {
        s = _undo.top();
        _undo.pop();
    }
};

int main()
{
    TextEditor txtEditor = TextEditor();

    int q;
    cin >> q;
    while (q--)
    {
        int a;
        cin >> a;

        if (a == 1)
        {
            string w;
            cin >> w;
            txtEditor.append(w);
        }

        else if (a == 2)
        {
            int k;
            cin >> k;
            txtEditor.del(k);
        }

        else if (a == 3)
        {
            int k;
            cin >> k;
            txtEditor.print(k);
        }

        else if (a == 4)
        {
            txtEditor.undo();
        }
    }
    return 0;
}
