#include <bits/stdc++.h>
using namespace std;

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

#define ll long long int

struct element
{
    ll a;
    ll b;
    ll eq;
};

int main()
{
    ReadDataWithSpeed();

    ll n,
        f;
    cin >> n >> f;

    element arr[n];

    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i].a >> arr[i].b;
        arr[i].eq = min(arr[i].a, arr[i].b);
    }

    ll ans = 0;
    ll i = 0;
    // sort array by eq
    sort(arr, arr + n, [](element a, element b)
         { return; });

    if (f == 0)
    {
        f = -1;
    }

    while ((f != 0) && i < n)
    {

        cout << arr[i].a << " " << arr[i].b << " " << arr[i].eq << endl;
        if ((arr[i].a * arr[i].b * arr[i].eq) > 0)
        {
            ans += arr[i].b;
            f--;
        }

        i++;
    }

    cout << ans;
}
