#include <bits/stdc++.h>
 
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vP(n);
    vector<int> vM(n);
    vector<int> vPE(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
 
        if (x == 1)
        {
            vP.push_back(i + 1);
        }
         if (x == 2)
        {
            vM.push_back(i + 1);
        }
         if (x == 3)
        {
            vPE.push_back(i + 1);
        }
    }
 
    while (true)
    {
        if ((vP.back() != 1) || (vM.back() != 2) || (vPE.back() != 3))
        {
            return 0;
        }
 
        cout << vP.back() << " " << vM.back() << " " << vPE.back() << endl;
 
        if (!vP.empty())
        {
            vP.pop_back();
        }
        if (!vM.empty())
        {
            vM.pop_back();
        }
        if (!vPE.empty())
        {
            vPE.pop_back();
        }
    }
}