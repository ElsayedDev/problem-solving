#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    cin.tie(nullptr)->sync_with_stdio(false);

#ifndef ONLINE_JUDGE

    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);

#endif
}

int removeDuplicates(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
        return n;

    int slow = 2, fast = 2;

    while (fast < n)
    {
        if (nums[slow - 2] != nums[fast])
        {
            nums[slow] = nums[fast];
            slow++;
        }
        fast++;
    }

    return slow;
}

void rotate(vector<int> &nums, int k)
{

    int l = nums.size();
    vector<int> temp(l);

    for (int i = 0; i < k; ++i)
    {
        temp[i + k] = (nums[l - i - 1]);
    }

    for (int i = k; i < l; ++i)
    {
        temp[i] = (nums[i - k]);
    }

    for (int i = 0; i < l; ++i)
    {
        nums[i] = temp[i];
    }
}

string longestEvenWord(string sentence)
{
    string res = "";
    string word = "";
    int max_len = 0;
    int len = 0;
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] == ' ')
        {
            if (len % 2 == 0 && len > max_len)
            {
                max_len = len;
                res = word;
            }
            word = "";
            len = 0;
        }
        else
        {
            word += sentence[i];
            len++;
        }
    }
    if (len % 2 == 0 && len > max_len)
    {
        res = word;
    }
    return res;
}
int raisingPower(vector<int> arr)
{
    int mx = 0, mx_index = 0;
    long long ex = 1e9 + 7;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        long long temp = (long long)pow(arr[i], arr[i + 1]) % ex;
        if (temp > mx)
        {
            mx = temp;
            mx_index = i;
        }
    }

    return mx_index;
}

int raisingPower(vector<int> arr)
{

    long long mx = INT_MIN, mx_index = -1;
    long long ex = 1e9;
    ex += 7;

    for (long long i = 0; i < arr.size() - 1; i++)
    {
        long long temp = (long long)pow(arr[i], arr[i + 1]) % ex;
        if (temp > mx)
        {
            mx = temp;
            mx_index = i;
        }
    }

    return mx_index + 1;
}
/*
// Write your code here


 */

int main()
{
    ReadDataWithSpeed();

    cout << longestEvenWord("len") << endl;
    return 0;
}
