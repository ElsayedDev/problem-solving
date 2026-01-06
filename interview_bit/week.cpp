#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <chrono>

using namespace std;

class Solution
{
public:
    int majorityElement(const vector<int> &A)
    {
        int count = 0;
        int candidate = -1;

        for (int num : A)
        {
            if (count == 0)
            {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }

    vector<int> getRow(int A)
    {
        vector<int> row(A + 1, 1);

        for (int i = 1; i < A; i++)
        {
            for (int j = i; j > 0; j--)
            {
                row[j] += row[j - 1];
            }
        }
        return row;
    }

    int repeatedNumber(const vector<int> &A)
    {
        int slow = A[0];
        int fast = A[0];

        // Phase 1: Finding the intersection point in the cycle
        do
        {
            slow = A[slow];
            fast = A[A[fast]];
        } while (slow != fast);

        // Phase 2: Finding the entrance to the cycle
        slow = A[0];
        while (slow != fast)
        {
            slow = A[slow];
            fast = A[fast];
        }

        return slow;
    }

    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
    {
        }
};

int main()
{
    // sol
    Solution sol;
    // repeatedNumber

    vector<int> A = {3, 4, 1, 4, 1};

    sol.repeatedNumber(A);

    return 0;
}
