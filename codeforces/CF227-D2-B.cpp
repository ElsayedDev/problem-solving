#include <bits/stdc++.h>

#define SPEED                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ll long long int

using namespace std;

// void first_algo(int n, int m, int arr[], int queries[])
// {
//     int f = 0, r = 0;
//     // forward search
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             f++;
//             if (arr[j] == queries[i])
//             {
//                 break;
//             }
//         }
//     }

//     // reverse search
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = n - 1; j >= 0; j--)
//         {
//             r++;
//             if (arr[j] == queries[i])
//             {
//                 break;
//             }
//         }
//     }

//     cout << f << " " << r << endl;
// }

void second_algo(ll n, ll m, ll arr[], ll queries[])
{
    ll f = 0, r = 0;

    for (ll i = 0; i < m; i++)
    {
        bool found_f = false, found_r = false;
        for (ll j = 0; j < n; j++)
        {
            ll forward_value = arr[j];
            ll reverse_value = arr[n - j - 1];

            if (!found_f && (forward_value == queries[i]))
            {
                f += j + 1;
                found_f = true;
            }
            if (!found_r && (reverse_value == queries[i]))
            {
                r += n - j - 1;
                found_r = true;
            }
            if (found_f && found_r)
            {
                break;
            }
        }
    }

    cout << f << " " << r << endl;
}

// void third_algo(ll n, ll m, ll arr[], vector<ll> queries)
// {
//     int f = 0, r = 0;

//     vector<ll> f_q = queries;
//     vector<ll> r_q = queries;

//     for (ll j = 0; j < n && (!f_q.empty() || !r_q.empty()); j++)
//     {
//         ll forward_value = arr[j];
//         ll reverse_value = arr[n - j - 1];

//         for (auto it = f_q.begin(); it != f_q.end();)
//         {
//             if (*it == forward_value)
//             {
//                 f += j + 1;
//                 it = f_q.erase(it);
//             }
//             else
//             {
//                 it++;
//             }
//         }

//         for (auto it = r_q.begin(); it != r_q.end();)
//         {
//             if (*it == forward_value)
//             {
//                 r += n - j;
//                 it = r_q.erase(it);
//             }
//             else
//             {
//                 it++;
//             }
//         }
//     }

//     cout << f << " " << r << endl;
// }

int main()
{
    SPEED

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    ll n, m;
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; i++)
        cin >> arr[i];

    cin >> m;

    ll queries[m];
    for (ll i = 0; i < m; i++)
        cin >> queries[i];

    // first_algo(n, m, arr, queries);

    second_algo(n, m, arr, queries);

    // vector<ll> queries(m);
    // for (ll i = 0; i < m; i++)
    //     cin >> queries[i];

    // third_algo(n, m, arr, queries);
}
