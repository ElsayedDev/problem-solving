#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// int findMinTrips(vector<int> packageweight)
// {
//     long long int n = packageweight.size();
//     // count each package weight
//     unordered_map<int, int> count;
//     for (int i = 0; i < n; i++)
//     {
//         count[packageweight[i]]++;
//     }

//     int trips = 0;
//     for (auto it : count)
//     {
//         if (it.second == 1 || (it.second % 2 == 1 && it.second % 3 == 1))
//             return -1;

//         else if (it.second % 3 == 0)
//         {

//             trips += (it.second / 3);

//             if (it.second % 3 == 2)
//                 trips++;

//             // cout << it.first << " " << it.second << " trips: " << trips << endl;
//         }
//         else if (it.second % 2 == 0)
//         {
//             // cout << it.first << " " << it.second << " trips: " << trips << endl;
//             trips += (it.second / 2);
//         }

//         else
//         {
//             return -1;
//         }
//     }

//     return trips;
// };

vector<string> findRecurringNames(vector<string> realNames, vector<string> allNames)
{
    vector<string> realNamesTemp = realNames;

    // sort the litters in realNames
    for (int i = 0; i < realNamesTemp.size(); i++)
    {
        sort(realNamesTemp[i].begin(), realNamesTemp[i].end());
    }

    vector<string> result;

    // print realNames
    for (int i = 0; i < realNames.size(); i++)
    {
        // sort allNames and check if the realNames equal one of it

        int counter = 0;
        for (int j = 0; j < allNames.size(); j++)
        {
            sort(allNames[j].begin(), allNames[j].end());
            if (realNamesTemp[i] == allNames[j])
            {
                counter++;
            }
        }

        if (counter > 1)
        {
            result.push_back(realNames[i]);
        }
    }
    sort(result.begin(), result.end());
    return result;
};

int main(int argc, char const *argv[])
{
    // cout << findMinTrips({1, 8, 5, 8, 5, 1, 1});

    // cout << 3 % 2 << endl;

    findRecurringNames({"alice", "bob", "terry"}, {});

    return 0;
};
