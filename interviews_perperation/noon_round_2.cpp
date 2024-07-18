
#include <bits/stdc++.h>
#include "../leetcode/common.h"

using namespace std;

#define ll long long int

void ReadDataWithSpeed() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifndef ONLINE_JUDGE

    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);

#endif
}


class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] == nums[i]) return true;
        }
        return false;
    }

    int missingNumber(vector<int> &nums) {
        int n = nums.size(), xr = 0, i = 0;

        while (i < n)
            xr = xr ^ i ^ nums[i++];

        return xr ^ i;
    }

    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        vector<int> res, arr(n, 0);

        for (auto n: nums)
            arr[n - 1] = 1;

        for (int i = 0; i < n; ++i)
            if (arr[i] == 0)
                res.push_back(i + 1);

        return res;
    }

    int singleNumber(vector<int> &nums) {
        int xr = 0;

        for (auto e: nums)
            xr = xr ^ e;

        return xr;

    }

    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        int p = 1, c = 1, temp;

        for (int i = 2; i <= n; ++i) {
            temp = c;
            c += p;
            p = temp;
        }

        return c;
    }

    int maxPorfit(vector<int> &prices) {
        int mn = INT_MAX, profit = 0;
        for (auto e: prices) {
            if (e < mn) mn = e;
            else {
                int diff = e - mn;
                if (diff > profit) profit = diff;
            }
        }

        return profit;
    }

    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);

        for (int i = 1; i <= n; ++i)
            res[i] = res[i / 2] + i % 2;

        return res;
    }

    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) return true;
        }

        return false;

    }

    ListNode *middleNode(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *prev = NULL, *next = head;

        while (head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode *head) {
        vector<int> temp;
        while (head) {
            temp.push_back(head->val);
            head = head->next;
        }

        int l = 0, r = temp.size() - 1;
        while (l <= r) {
            if (temp[l] != temp[r]) return false;
            l++;
            r--;
        }

        return true;
    }

    ListNode *removeElements(ListNode *head, int val) {
        ListNode *temp = head;

        while (temp && temp->next) {
            if (temp->next->val == val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        if (head && head->val == val) {
            head = head->next;
        }

        return head;
    }

    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *temp = head;

        while (temp && temp->next) {
            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;

    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);

            return l1;
        }

        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }

    int search(vector<int> &nums, int target) {

        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] > target) r = mid - 1;
            else l = mid + 1;

        }

        return -1;
    }

    char nextGreatestLetter(vector<char> &letters, char target) {
        vector<bool> arr(26, false);
        for (auto e: letters) {
            arr[e - 'a'] = true;
        }

        for (int i = target - 'a' + 1; i < 26; ++i) {
            if (arr[i]) return i + 'a';
        }


        return letters[0];

    }


    vector<double> averageOfLevels(TreeNode *root) {
        if (!root)
            return {};


        vector<double> res;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            double sum = 0;

            int n = q.size();
            for (int i = 0; i < n; ++i) {
                auto val = q.front();
                q.pop();
                sum += val->val;
                if (val->left) q.push(val->left);
                if (val->right) q.push(val->right);

            }
            res.push_back(sum / n);
        }

        return res;
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {

        if (!p && !q)
            return true;

        if (!p || !q)
            return false;

        if (p->val != q->val)
            return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;

        int v = targetSum - root->val;
        if (!root->left && !root->right && (v == 0)) return true;

        return hasPathSum(root->left, v) || hasPathSum(root->right, v);

    }

    int maxDepth(TreeNode *root) {
        if (!root) return 0;

        int l = 1 + maxDepth(root->left);
        int r = 1 + maxDepth(root->right);

        return max(l, r);
    }

    int mx = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return mx;
    }

    int depth(TreeNode *root) {
        if (!root) return 0;

        int l = depth(root->left), r = depth(root->right);

        mx = max(mx, l + r);

        return 1 + max(l, r);
    }

    void moveZeroes(vector<int> &nums) {
        for (int i = 0, l = 0, n = nums.size(); i < n; ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[l++]);
            }
        }
    }


    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;

        if (root) binaryTreePaths(res, root, to_string(root->val));


        return res;
    }

    void binaryTreePaths(vector<string> &res, TreeNode *root, string path) {
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }

        if (root->left) binaryTreePaths(res, root->left, path + "->" + to_string(root->left->val));
        if (root->right) binaryTreePaths(res, root->right, path + "->" + to_string(root->right->val));
    }

    bool backspaceCompare(string s, string t) {
        return getString(s) == getString(t);
    }

    string getString(string str) {
        int n = str.length(), count = 0;
        string res = "";

        for (int i = n - 1; i >= 0; --i) {
            char ch = str[i];
            if (ch == '#') count++;
            else {
                if (count > 0) count--;
                else {
                    res += ch;
                }
            }
        }
        return res;
    }

    vector<int> sortedSquares(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = nums[i] * nums[i];
        }

        std::sort(nums.begin(), nums.end());
        return nums;
    }

    vector<int> sortedSquares2(vector<int> &nums) {
        int n = nums.size(), l = 0, r = n - 1;
        vector<int> res(n, 0);
        for (int j = n - 1; j >= 0; j--) {
            if (abs(nums[r] > abs(nums[l])))
                res[j] = nums[r] * nums[r--];
            else res[j] = nums[l] * nums[l++];
        }

        return res;
    }

    bool isSubsequence(string s, string t) {

        for (auto x: t)
            if (x == s[0])
                s.erase(0, 1);

        return s.size() == 0;
    }

    int majorityElement(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        return nums[nums.size() / 2];
    }

    int lengthOfLIS(vector<int> &nums) {
        int mx = 1, n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }
            if (mx < dp[i]) mx = dp[i];
        }

        return mx;
    }

    string symbileBetweenChar(string s, char symbole) {

        string res = "";
        for (int i = 0; i < s.size(); ++i) {
            res += symbole;
            res += s[i];
        }
        res += symbole;
        return res;

    }

    string longestPalindrome(string s) {
        int n = s.length();
        if (n < 2)return s;

        string sr = symbileBetweenChar(s, '|');
        n = sr.length();

        vector<int> dp(n, 0);

        for (int i = 0; i < n; ++i) {
            int r = i + 1, l = i - 1;

            while (r < n && l >= 0 && sr[l] == sr[r]) {
                dp[i]++;
                r++;
                l--;
            }
        }

        int mx = 0, idx = 0;
        for (int i = 0; i < n; ++i) {
            if (mx < dp[i]) {
                mx = dp[i];
                idx = i;
            }
        }

        string res = "";
        for (int i = idx - mx + 1; i < idx + mx; ++i) {
            if (sr[i] != '|') res += sr[i];
        }

        return res;
    }

    bool wordBreak(string s, vector<string> &wordDict) {

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && std::find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];

    }

    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target + 1, -1);

        dp[0] = 1;

        return combinationSum4(dp, nums, target);

    }

    int combinationSum4(vector<int> &dp, vector<int> &nums, int target) {
        if (target == 0) return 1;
        if (target < 0) return 0;

        if (dp[target] != -1) return dp[target];
        int res = 0;


        for (int i = 0; i < nums.size(); ++i) {
            if (target >= nums[i]) {
                res += combinationSum4(dp, nums, target - nums[i]);
            }
        }

        dp[target] = res;

        return res;
    }

    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;

        for (int i = 2; i <= n; ++i) {
            int one = stoi(s.substr(i - 1, 1));
            int two = stoi(s.substr(i - 2, 2));

            if (one >= 1) dp[i] += dp[i - 1];
            if (two >= 10 && two <= 26) dp[i] += dp[i - 2];
        }

        return dp[n];

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (n < 2)
            return true;

        int steps_needed = 1;

        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] >= steps_needed) {
                steps_needed = 1;
            } else {
                steps_needed++;
            }
        }

        if (steps_needed > nums[0]) return false;

        return true;

    }


};


int main() {
    ReadDataWithSpeed();

    cout << Solution().longestPalindrome("abaabc") << endl;

    return 0;
}
