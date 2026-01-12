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
        if (A.empty())
            return B;

        if (B.empty())
            return A;

        vector<int> result;
        int i = 0, j = 0;
        while (i < A.size() && j < B.size())
        {

            if (A[i] < B[j])
            {
                result.push_back(A[i]);
                i++;
            }
            else
            {
                result.push_back(B[j]);
                j++;
            }
        }
        while (i < A.size())
        {
            result.push_back(A[i]);
            i++;
        }
        while (j < B.size())
        {
            result.push_back(B[j]);
            j++;
        }

        return result;
    }

    vector<int> twoSum(vector<int> &nums, int target)
    {
        // use 2 pointers
        int n = nums.size();
        vector<pair<int, int>> numsI;
        for (int i = 0; i < n; i++)
            numsI.push_back({nums[i], i});

        sort(numsI.begin(), numsI.end());
        int left = 0, right = n - 1;
        while (left < right)
        {
            int sum = numsI[left].first + numsI[right].first;

            if (sum == target)
            {
                return {numsI[left].second, numsI[right].second};
            }

            if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }

    int maxSubArray(vector<int> &nums)
    {
        int maxEndingHere = nums[0], maxSoFar = nums[0];

        for (size_t i = 0; i < nums.size(); i++)
        {
            maxEndingHere = max(maxEndingHere, nums[i] + maxEndingHere);
            maxSoFar = max(maxEndingHere, maxSoFar);
        }

        return maxSoFar;
    }

    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> seen;
        for (int num : nums)
        {
            if (seen.count(num))
                return true;
            seen.insert(num);
        }
        return false;
    }
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // to handle cases where k > n because rotating n times results in the same array

        auto reverseRange = [&](int start, int end)
        {
            while (start < end)
                swap(nums[start++], nums[end--]);
        };

        reverseRange(0, n - 1);
        reverseRange(0, k - 1);
        reverseRange(k, n - 1);
    }
    auto reverseRange(vector<int> &nums, int start, int end)
    {
        while (start < end)
            swap(nums[start++], nums[end--]);
    };

    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // Transpose the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++)
        {
            reverseRange(matrix[i], 0, n - 1);
        }
    }

    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        // 0 -> 0-deg , 1 -> 90-deg , 2 -> 180-deg , 3 -> 270-deg
        bool isOkRotations[4] = {true, true, true, true};
        int deg = 0, n = target.size();

        do
        {
            for (int i = 0; i < n && isOkRotations[deg]; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int matElement = mat[i][j];
                    if (deg == 0)
                        isOkRotations[deg] &= matElement == target[i][j];

                    else if (deg == 1)
                        isOkRotations[deg] &= matElement == target[j][n - 1 - i];
                    else if (deg == 2)
                        isOkRotations[deg] &=
                            matElement == target[n - 1 - i][n - 1 - j];
                    else if (deg == 3)
                        isOkRotations[deg] &= matElement == target[n - 1 - j][i];
                }
            }

            if (isOkRotations[deg])
                return true;

            deg++;
        } while (deg < 4);

        return false;
    };

    string LongestWord(string sen)
    {
        int maxLength = 0, currentLength = 0;
        string maxWord = "", currentWord = "";

        for (char c : sen)
        {
            // in-case of non-alphabetic character
            if (!isalpha(c))
            {
                currentWord = "";
                currentLength = 0;

                continue;
            }

            currentWord.push_back(c);
            currentLength++;

            if (currentLength > maxLength)
            {
                maxLength = currentLength;
                maxWord = currentWord;
            }
        }

        return maxWord;
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalGas = 0, totalCost = 0;
        int currentGas = 0, startingStation = 0;
        int n = gas.size();
        for (int i = 0; i < n; i++)
        {
            totalGas += gas[i];
            totalCost += cost[i];
            currentGas += gas[i] - cost[i];

            // If currentGas drops below 0, reset starting station and currentGas
            if (currentGas < 0)
            {
                startingStation = i + 1;
                currentGas = 0;
            }
        }

        // If total gas is less than total cost, it's impossible to complete the circuit
        if (totalGas < totalCost)
        {
            return -1;
        }

        return startingStation;
    }

    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        if (matrix.empty())
            return result;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse from left to right
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;

            // Traverse from top to bottom
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            // Traverse from right to left
            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Traverse from bottom to top
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }

    int firstUniqChar(string s)
    {
        int freq[26] = {-1};

        int n = s.length();

        for (int i = 0; i < s.length(); i++)
        {
            if (freq[s[i] - 'a'] == -1)
                freq[s[i] - 'a'] = i;

            else
            {
                freq[s[i] - 'a'] = n;
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != -1 && freq[i] != 27)
            {
                n = min(n, freq[i]);
            }
        }
    }
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> result;
        int n = matrix.size();

        int right = n - 1, left = 0, top = 0, bottom = n - 1;

        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
                result.push_back(matrix[top][i]);
            top++;

            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            if (top <= bottom)
            {
                for (int i = right; i >= left; i--)
                    result.push_back(matrix[bottom][i]);
                bottom--;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }

    string longestPalindrome(string s)
    {
        int n = s.length();

        auto expandAroundCenter = [&](int left, int right) -> pair<int, int>
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                left--;
                right++;
            }
            return {left + 1, right - 1};
        };

        int maxLength = 1;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            // Odd length palindromes
            auto [left1, right1] = expandAroundCenter(i, i);
            if (right1 - left1 + 1 > maxLength)
            {
                maxLength = right1 - left1 + 1;
                start = left1;
                end = right1;
            }

            // Even length palindromes
            auto [left2, right2] = expandAroundCenter(i, i + 1);
            if (right2 - left2 + 1 > maxLength)
            {
                maxLength = right2 - left2 + 1;
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, maxLength);
    }

    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : nums)
        {
            if (!numSet.count(num - 1))
            {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.count(currentNum + 1))
                {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }

    bool canPartition(vector<int> &nums)
    {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;

        if (totalSum % 2 != 0)
            return false;

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums)
        {
            for (int j = target; j >= num; j--)
            {
                dp[j] = dp[j] || dp[j - num];
            }

            if (dp[target])
                return true;
        }

        return dp[target];
    }

    string longestDupSubstring(string s)
    {
        int n = s.length();
        int left = 1, right = n - 1;
        string result = "";

        auto search = [&](int length) -> int
        {
            unordered_set<string> seen;
            for (int i = 0; i <= n - length; i++)
            {
                string substring = s.substr(i, length);
                if (seen.count(substring))
                    return i;
                seen.insert(substring);
            }
            return -1;
        };

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int startIdx = search(mid);

            if (startIdx != -1)
            {
                result = s.substr(startIdx, mid);
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }

    int carFleet(int target, vector<int> &position, vector<int> &speed)
    {
        auto calcTime = [&](pair<int, int> car) -> int
        {
            return (target - car.first) / car.second;
        };

        int n = position.size();
        vector<pair<int, int>> cars;

        for (int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end(), greater<pair<int, int>>());

        int fleet = 1, group = 1;

        double leadTime = calcTime(cars[0]);
        for (int i = 1; i < n; i++)
        {
            double currentTime = calcTime(cars[i]);

            if (currentTime > leadTime)
            {
                fleet++;
                leadTime = currentTime;
            }
        }

        return fleet;
    }

    bool isValid(string s)
    {
        stack<char> stk;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}};

        for (char c : s)
        {
            if (bracketMap.count(c))
            {
                if (stk.empty() || stk.top() != bracketMap[c])
                    return false;
                stk.pop();
                continue;
            }

            stk.push(c);
        }

        return stk.empty();
    }

    string removeDuplicates(string s)
    {

        stack<char> stk;
        for (char c : s)
        {
            if (!stk.empty() && stk.top() == c)
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }

        string result;
        while (!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
int main()
{
    // sol
    Solution sol;
    // repeatedNumber

    vector<int> A = {3, 4, 1, 4, 1};

    return 0;
}
