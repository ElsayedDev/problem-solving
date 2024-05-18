#include <bits/stdc++.h>
// #include <common.h>

using namespace std;

#define ll long long int

bool isPrime(ll n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool isAlmostPrime(ll n)
{
    int primes = 0;

    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            primes++;
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }

    if (n > 1)
        primes++;

    if (primes == 2)
        return true;

    return false;
}

ll gcd(ll a, ll b)
{
    while (b != 0)
    {
        ll a2 = a;
        a = b;
        b = a2 % b;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

ll fastPower(ll b, ll p)
{
    ll ans = 1;
    while (p)
    {
        if (p % 2)
            ans *= b;
        b = b * b;
        p /= 2;
    }
    return ans;
}

ll modularExpo(ll x, ll n, ll m)
{
    ll res = 0;

    while (n > 0)
    {
        if (x % 2 == 1)
            res = (res * x) % m;

        x = ((x % m) * (x % m)) % m;

        n /= 2;
    }
}

ll divs(ll n)
{
    ll res = 0;
    for (ll i = 1; i <= n; ++i)
    {
        if (n % i == 0)
            res++;
    }

    return res;
}

vector<ll> divsVictor(ll n)
{
    vector<ll> divs;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {

            if (n / i == i)
            {
                divs.push_back(i);
            }
            else
            {
                divs.push_back(i);
                divs.push_back(n / i);
            }
        }
    }

    return divs;
}

vector<bool> sieve(int n)
{

    vector<bool> composite(n);

    composite[0] = composite[1] = true;

    for (int i = 2; i * i <= n; i++)
    {
        if (!composite[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                composite[j] = true;
            }
        }
    }

    return composite;
}

void linearSieve(ll n)
{

    bool composite[n];
    vector<ll> primes;

    composite[0] = composite[1] = true;

    for (ll i = 2; i <= n; i++)
    {
        if (!composite[i])
            primes.push_back((i));

        for (ll j = 0; j < primes.size() && i * primes[j] <= n; j++)
        {

            composite[i * primes[j]] = true;

            if (i % primes[j] == 0)
                break;
        }
    }
}

vector<ll> linearSieveVector(ll n)
{

    bool composite[n];
    vector<ll> primes;

    composite[0] = composite[1] = true;

    for (ll i = 2; i <= n; i++)
    {
        if (!composite[i])
            primes.push_back((i));

        for (ll j = 0; j < primes.size() && i * primes[j] <= n; j++)
        {

            composite[i * primes[j]] = true;

            if (i % primes[j] == 0)
                break;
        }
    }

    return primes;
}

vector<ll> linearSieveByTarget(ll target, ll capacity)
{

    bool composite[capacity + 1];
    vector<ll> prime;

    composite[0] = composite[1] = true;

    for (ll i = 2; i <= capacity; i++)
    {
        if (!composite[i])
            prime.push_back((i));

        for (ll j = 0; j < prime.size() && i * prime[j] <= capacity; j++)
        {

            composite[i * prime[j]] = true;

            if (prime.size() == target)
                return prime;

            if (i % prime[j] == 0)
                break;
        }

        if (prime.size() == target)
            return prime;
    }

    return prime;
}

int main()
{

    return 0;
}