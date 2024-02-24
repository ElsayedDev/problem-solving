#include <bits/stdc++.h>

using namespace std;

int superDigit(string n, int k)
{
    if (n.size() == 1)
    {
        return stoi(n);
    }

    long long sum = 0;
    for (int i = 0; i < n.size(); i++)
    {
        sum += n[i] - '0';
    }

    return superDigit(to_string(sum * k), 1);
}