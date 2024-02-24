#include <bits/stdc++.h>

using namespace std;

int truckTour(vector<vector<int>> petrolpumps)
{

    long long int n = petrolpumps.size();
    long long int start = 0;
    long long int petrol = 0;
    long long int distance = 0;
    for (long long int i = 0; i < n; i++)
    {
        petrol += petrolpumps[i][0];
        distance += petrolpumps[i][1];
        if (petrol < distance)
        {
            start = i + 1;
            petrol = 0;
            distance = 0;
        }
    }
    return start;
}