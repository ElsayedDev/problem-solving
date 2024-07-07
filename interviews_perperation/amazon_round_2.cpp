
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


class SolutionProductExceptSelf {


public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();

        int left = 1, right = 1;

        vector<int> res(n, 1);
        for (int i = 0; i < n; i++) {
            res[i] *= left;
            left *= nums[i];
            res[n - i - 1] *= right;
            right *= nums[n - i - 1];
        }

        return res;
    }
};

class SolutionFindDuplicate {
public:
    int findDuplicate(vector<int> &nums) {

        int n = nums.size(), v = 0;

        for (int i = 0; i < n; i++) {
            v = v ^ nums[i] ^ i;

        }
        return v;
    }
};

class SolutionTwoSum {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int div = target - nums[i];
            if (mp.count(div)) return {i, mp[div]};
            mp[nums[i]] = i;
        }

        return {};
    }
};

class SolutionIsValid {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto c: s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);


            } else {
                if (st.empty()) return false;
                if (c == ')' && st.top() != '(') return false;
                if (c == '}' && st.top() != '{') return false;
                if (c == ']' && st.top() != '[') return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

class SolutionMergeTwoLists {
public:
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
};

class SolutionIsSubtree {
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (!root) return false;
        if (isTheSame(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }


    bool isTheSame(TreeNode *root, TreeNode *subRoot) {
        if (!root && !subRoot) return true;

        if (!root || !subRoot) return false;

        if (root->val != subRoot->val) return false;

        return isTheSame(root->left, subRoot->left) && isTheSame(root->right, subRoot->right);
    }
};

class SolutionIsSameTree {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {

        if (!p && !q) return true;

        if (!p || !q) return false;

        if (p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);

    }
};

class SolutionMergeTrees {
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        root1->val += root2->val;

        if (root2->left) root1->left = mergeTrees(root1->left, root2->left);
        if (root2->right) root1->right = mergeTrees(root1->right, root2->right);

        return root1;
    }
};

class SolutionGetRow {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 0);
        res[0] = 1;

        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j > 0; j--) {
                cout << "i: " << i << " " << res[j] << " i-1: " << i - 1 << " " << res[j - 1] << endl;
                res[j] += res[j - 1];
            }
            cout << endl;
        }

        return res;
    }
};

class SolutionMaxProfit {
public:
    int maxProfit(vector<int> &prices) {
        int mn = INT_MAX, mx = 0;

        for (auto e: prices) {
            if (e < mn) mn = e;

            else {
                int diff = e - mn;
                if (diff > mx) mx = diff;
            }
        }

        return mx;
    }
};

class SolutionFindErrorNums {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n + 1, 0);
        for (auto e: nums) {
            res[e]++;
        }

        int db = 0, ms = 0;
        for (int i = 1; i < n + 1; ++i) {
            if (res[i] == 2)
                db = i;
            if (res[i] == 0)
                ms = i;
        }

        return {db, ms};
    }
};

class SolutionHasCycle {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;

        ListNode *slow = head;

        while (fast && fast->next) {

            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) return true;
        }

        return false;

    }
};

class SolutionGetIntersectionNode {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_map<ListNode *, int> mp;
        while (headA) {
            mp[headA]++;
            headA = headA->next;
        }
        while (headB) {
            if (mp[headB] > 0) return headB;
            headB = headB->next;
        }

        return nullptr;

        /*
        if (!headA || !headB) return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a != b) {
            a = !a ? headB : a->next;
            b = !b ? headA : b->next;
        }

        return a;
*/


    }
};

class SolutionIsHappy {
    int digitSquareSum(int n) {
        int sum = 0, tmp;

        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }

public:
    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = digitSquareSum(slow);
            fast = digitSquareSum(digitSquareSum(fast));
        } while (slow != fast);

        if (slow == 1)
            return true;

        return false;
    }
};

class SolutionReverseList {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *next = head, *prev = nullptr;
        while (head) {

            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};

class SolutionPivotIndex {
public:
    int pivotIndex(vector<int> &nums) {
        int sum = 0;
        for (auto e: nums) sum += e;

        int l = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (l == sum - l - nums[i]) return i;
            l += nums[i];
        }

        return -1;
    }

    int pivotIndex_(vector<int> &nums) {
        int n = nums.size(), l = 0, r = n - 1;

        int sL = nums[0], sR = 0;
        while (l < r) {

            if (sL > sR) --r, sR += nums[r];
            else if (sL < sR) ++l, sL += nums[l];

            if (sL == sR) return l + 1;
        }

        return -1;
    }
};

class SolutionIsPalindrome {
public:
    bool isPalindrome(ListNode *head) {
        ListNode *s = head;
        ListNode *f = reverseList(head);

        while (s) {
            if (s != f) return false;
            s = s->next;
            f = f->next;
        }

        return true;
    }

    ListNode *reverseList(ListNode *head) {
        ListNode *next = head, *prev = nullptr;
        while (head) {

            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
};

class SolutionMinCostClimbingStairs {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        cost.push_back(0);
        for (int i = n - 2; i >= 0; i--) {
            cost[i] += min(cost[i + 1], cost[i + 2]);
        }

        return min(cost[0], cost[1]);
    }
};

class SolutionIsAnagram {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> arr(26, 0);
        for (int i = 0; i < s.length(); ++i) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        for (auto e: arr)
            if (e != 0) return false;

        return true;

    }
};

class SolutionCountPrimeSetBits {
public:
    int countPrimeSetBits(int left, int right) {
        int res = 0;
        for (int i = left; i <= right; i++) {
            vector<int> v = digitalToBits(i);
            res += count(v.begin(), v.end(), 1);
        }

        return res;
    }

    vector<int> digitalToBits(int n) {
        vector<int> res;
        int r;
        while (n != 0) {
            r = n % 2;
            res.push_back(r);
            n /= 2;
        }

        return res;
    }
};

//  (c < 97 || c > 122) instead of isalpha
class SolutionMostCommonWord {
public:
    string mostCommonWord(string paragraph, vector<string> &banned) {
        unordered_map<string, int> words;

        string word = "";
        for (auto c: paragraph) {
            if (c == ' ') {

                if (!count(banned.begin(), banned.end(), word))
                    words[word]++;
                word = "";
            } else {
                if (isalpha(c))
                    word += tolower(c);
            }
        }
        if (!count(banned.begin(), banned.end(), word))
            words[word]++;

        int mx = 0;
        string res = "";
        for (auto e: words)
            if (e.second > mx)
                mx = e.second,
                        res = e.first;


        return res;

    }
};

class SolutionFirstUniqChar {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < s.length(); ++i) {
            if (freq[s[i] - 'a'] == 1) return i;
        }

        return -1;


    }
};

class SolutionThirdMax {
public:
    int thirdMax(vector<int> &nums) {
        set<int> st;
        for (auto e: nums) {
            st.insert(e);
            if (st.size() > 3) st.erase(st.begin());
        }
        return st.size() == 3 ? *st.begin() : *st.rbegin();
    }
};

class SolutionAddTwoNumbers {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode head = ListNode(0), *ptr = &head;
        int r = 0;
        while (l1 || l2 || r) {

            r += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);

            ptr->next = new ListNode(r % 10);
            ptr = ptr->next;

            r /= 10;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

        }

        return ptr->next;

    }
};

class SolutionLengthOfLongestSubstring {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> ref(26, -1);

        int mx = 0, start = -1;

        for (int i = 0; i < s.length(); ++i) {

            int idx = s[i] - 'a';

            if (ref[idx] > start)
                start = ref[idx];

            ref[idx] = i;

            mx = max(mx, i - start);

        }

        return mx;
    }
};

class SolutionLongestPalindrome {
public:
    string longestPalindrome(string s) {
        // char and arr of it's indexs
        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < s.length(); ++i) {
            mp[s[i]].push_back(i);
        }

        string res = "";
        for (auto e: mp) {
            int n = e.second.size();
            if (n == 1) {
                continue;
            }

            for (int i = 1; i < n; i++) {
                int idx2 = e.second[i], idx1 = e.second[i - 1];

                string s1 = s.substr(idx1, idx2 - idx1 + 1);
                string s2 = s1;
                reverse(s2.begin(), s2.end());
                if (s1 == s2 && s1.length() > res.length()) {
                    res = s1;
                }
            }
        }


        if (res == "") return s.substr(0, 1);

        return res;


    }
};

class SolutionConvert {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res = "";

        int inc = 2 * (numRows - 1);
        for (int r = 0; r < numRows; r++) {
            for (int i = r; i < s.length(); i += inc) {
                res += s[i];
                if (r > 0 && r < numRows - 1) {
                    int j = i + inc - 2 * r;
                    if (j < s.length()) res += s[j];
                }
            }
        }

        return res;
    }
};

class SolutionLongestPalindromeSubseq {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};

class SolutionMyAtoi {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        while (i < n && s[i] == ' ') i++;

        if (i == n) return 0;

        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = s[i] == '+' ? 1 : -1;
            i++;
        }

        long res = 0;
        while (i < n && isdigit(s[i])) {
            res = res * 10 + s[i] - '0';
            if (res > INT_MAX) return sign == 1 ? INT_MAX : INT_MIN;
            i++;
        }

        return sign * res;
    }
};

class SolutionOrangesRotting {
public:
    int n = 0, m = 0;

    int orangesRotting(vector<vector<int>> &grid) {
        n = grid.size();
        m = grid[0].size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 2)
                    dfs(grid, i, j, 2);
            }
        }

        int minutes = 2;

        for (auto r: grid) {
            for (auto c: r) {
                if (c == 1) return -1;
                minutes = max(minutes, c);
            }
        }

        return minutes - 2;
    }

    void dfs(vector<vector<int>> &grid, int i, int j, int minutes) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 ||
            (1 < grid[i][j] && grid[i][j] < minutes))
            return;

        grid[i][j] = minutes;

        dfs(grid, i + 1, j, minutes + 1);
        dfs(grid, i - 1, j, minutes + 1);
        dfs(grid, i, j + 1, minutes + 1);
        dfs(grid, i, j - 1, minutes + 1);
    }
};

class SolutionThreeSum {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = res.size();
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) break;

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int low = i + 1, high = n - 1, sum = 0;

            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];

                if (sum < 0) low++;
                else if (sum > 0) high--;

                else {
                    res.push_back({nums[i], nums[low], nums[high]});

                    int lOld = nums[low], hOld = nums[high];

                    while (low < high && nums[low] == lOld) low++;
                    while (low < high && nums[high] == hOld) high--;
                }
            }


        }

        return res;
    }
};

class SolutionLetterCombinations {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.size() == 0)
            return res;
        vector<string> mp = {"", "", "abc", "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (auto digit: digits) {
            vector<string> temp;
            for (auto element: res) {
                for (auto ch: mp[digit - '0']) {
                    temp.push_back(element + ch);
                }
            }
            res = temp;
        }
        return res;
    }
};

class SolutionGenerateParenthesis {
public:

    vector<string> generateParenthesis(int n) {

        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }


    void dfs(int o, int c, string s, int n, vector<string> &res) {
        if (o == c && o + c == n * 2) {
            res.push_back(s);
            return;
        }

        if (o < n) {
            dfs(o + 1, c, s + "(", n, res);

        }

        if (c < o)
            dfs(o, c + 1, s + ")", n, res);

    }
};

class SolutionFindPairs {
public:
    int findPairs(vector<int> &nums, int k) {

        unordered_map<int, int> mp;

        for (auto e: nums) {
            mp[e]++;
        }

        int res = 0;
        for (auto e: mp) {
            if (k == 0) {
                if (e.second > 1) res++;
            } else {
                if (mp.count(e.first + k)) res++;
            }
        }

        return res;

    }
};

class SolutionUpdateMatrix {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int n = mat.size(), m = mat[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] != 0) {
                    int up = i > 0 ? mat[i - 1][j] : INT_MAX;
                    int left = j > 0 ? mat[i][j - 1] : INT_MAX;
                    mat[i][j] = min(up, left) + 1;
                }
            }
        }

        return mat;
    }
};

class SolutionPermute {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do {
            res.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));


        return res;
    }
};

class SolutionRotate {
public:
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

class SolutionGroupAnagrams {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> mp;
        for (auto s: strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }

        vector<vector<string>> res;
        for (auto e: mp) {
            res.push_back(e.second);
        }

        return res;
    }
};

class SolutionSubarraySum {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (auto e: nums) {
            sum += e;
            res += mp[sum - k];
            mp[sum]++;
        }

        return res;
    }
};

class SolutionMerge {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int a = intervals[0][0], b = intervals[0][1];

        for (auto e: intervals) {

            if (e[0] > b) {
                res.push_back({a, b});
                a = e[0];
                b = e[1];
                continue;
            }

            b = max(b, e[1]);
        }

        res.push_back({a, b});
        return res;
    }
};

class SolutionSpiralOrder {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        vector<int> res;
        int n = matrix.size(), m = matrix[0].size();
        int top = 0, bottom = n - 1, left = 0, right = m - 1;

        while (top <= bottom && left <= right) {

            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            right--;

            if (top <= bottom) {

                for (int i = right; i >= left; i--) {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }


        }

        return res;
    }
};

class SolutionGenerateMatrix {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int top = 0, bottom = n - 1, left = 0, right = n - 1, val = 1;

        while (top <= bottom && left <= right) {
            for (int i = left; i <= right; i++) {
                res[top][i] = val++;
            }
            top++;

            for (int i = top; i <= bottom; i++) {
                res[i][right] = val++;
            }
            right--;

            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    res[bottom][i] = val++;
                }
                bottom--;
            }

            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    res[i][left] = val++;
                }
                left++;
            }
        }

        return res;
    }
};

class SolutionUniquePaths {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];

    }
};

class SolutionUniquePathsWithObstacles {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            if (obstacleGrid[i][0] == 1) break;
            dp[i][0] = 1;
        }

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i] == 1) break;
            dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};

class SolutionMinPathSum {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1][n - 1];
    }
};

class SolutionFrequencySort {
public:
    string frequencySort(string s) {

        unordered_map<char, int> mp;
        for (auto c: s) {
            mp[c]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            return mp[a] == mp[b] ? a > b : mp[a] > mp[b];
        });

        return s;
    }
};

class SolutionCompress {
public:
    int compress(vector<char> &chars) {
        int n = chars.size(), i = 0, j = 0;
        while (i < n) {
            int cnt = 0;
            while (j < n && chars[i] == chars[j]) {
                j++;
                cnt++;
            }
            chars[i++] = chars[i];
            if (cnt > 1) {
                for (auto c: to_string(cnt)) {
                    chars[i++] = c;
                }
            }
        }

        return i;

    }
};


class SolutionFindAnagrams {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> mp(26, 0);
        for (auto c: p) {
            mp[c - 'a']++;
        }

        int n = s.length(), m = p.length();
        int l = 0, r = 0, cnt = m;

        while (r < n) {
            if (mp[s[r++] - 'a']-- > 0) cnt--;

            if (cnt == 0) res.push_back(l);

            if (r - l == m && mp[s[l++] - 'a']++ >= 0) cnt++;
        }

        return res;
    }
};


class SolutionFindUnsortedSubarray {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && sorted[i] == nums[i]) i++;
        while (j > i && sorted[j] == nums[j]) j--;

        return i + j - 1;
    }
};


class SolutionMinDistance {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            dp[i][0] = i;
        }

        for (int i = 1; i <= m; i++) {
            dp[0][i] = i;
        }


        // print dp
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int replace = dp[i - 1][j - 1] + 1;
                    int insert = dp[i][j - 1] + 1;
                    int remove = dp[i - 1][j] + 1;
                    dp[i][j] = min({replace, insert, remove});
                }
            }

        }


        return dp[n][m];

    }


};

class SolutionSetZeroes {
public:
    void setZeroes(vector<vector<int>> &matrix) {

        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRow = false;

        for (int i = 0; i < rows; ++i) {
            if (matrix[i][0] == 0) firstRow = true;
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    if (i > 0) matrix[i][0] = 0;
                    else firstRow = true;
                }
            }
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0)
            for (int i = 0; i < rows; ++i) matrix[i][0] = 0;

        if (firstRow)
            for (int j = 0; j < cols; ++j) matrix[0][j] = 0;

    }

};


class SolutionSortColors {
public:
    void sortColors(vector<int> &nums) {
        int n = nums.size();
        int low = 0, high = n - 1, mid = 0;

        while (mid <= high) {
            if (nums[mid] == 0) swap(nums[low++], nums[mid++]);
            else if (nums[mid] == 1) mid++;
            else swap(nums[mid], nums[high--]);
        }
    }
};

class SolutionSubsets {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, 0, temp, res);
        return res;

    }

    void dfs(vector<int> &nums, int idx, vector<int> &temp, vector<vector<int>> &res) {
        res.push_back(temp);
        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            dfs(nums, i + 1, temp, res);
            temp.pop_back();
        }
    }
};


vector<string> split(string s, char c) {
    vector<string> res;
    string temp = "";

    for (auto ch: s) {
        if (ch == c) {
            res.push_back(temp);
            temp = "";
        } else {
            temp += ch;
        }


    }
    res.push_back(temp);
    return res;
}


bool isDigit(char c) {
    return c >= '0' && c <= '9';
}


vector<string> sortOrders(vector<string> orderList) {
    // prime orders first
    // the prime orders has a string lowercase en
    // non-prime has int space

    // sperate the prime and non prime for each case
    /*   vector<string> nonPrime, prime;

       for(auto order : orderList){
           vector<string> id = split(order,  ' ');

           // safe case
           if (id.size() <2) continue;

           if (isDigit (id[1][0])){
               nonPrime.push_back(order);

           }else {
               prime.push_back(order);
           }

       }*/


    sort(orderList.begin(), orderList.end(), [](string a, string b) {
        // sort only if the sub ' ' is not digit otherwise keep the order
        vector<string> id1 = split(a, ' ');
        vector<string> id2 = split(b, ' ');

        if (isDigit(id1[1][0]) && isDigit(id2[1][0])) return false;
        if (isDigit(id1[1][0])) return false;
        if (isDigit(id2[1][0])) return true;

//        if (id1[1] == id2[1]) return id1[0] < id2[0];
//        return id1[1] < id2[1];
        int i = a.find(' '), j = b.find(' ');
//        // if the substrings are equal then compare the whole string
//        if (a.substr(i) == b.substr(j)) return a < b;
//        return a.substr(i) < b.substr(j);
        if (a.substr(i) == b.substr(j)) return a.substr(0, i) < b.substr(0, j);
        return a.substr(i) < b.substr(j);

// if has multi common sub string compare until the end
        if (a.substr(i) == b.substr(j)) return a < b;
        return a.substr(i) < b.substr(j);
    });


    return orderList;
}

long numberOfWays(string book) {
    // tow pointers problem
    // take first 2 elements then go forward with the third index

    long res = 0, bookSize = book.size(), a = 0, b = 1, c = 3;

    while (a < bookSize) {
        if (book[a] != book[b] && book[b] != book[c]) {
            res++;
        }

        // move the pointers




    }

    return res;


}



int main() {
    ReadDataWithSpeed();

    cout << numberOfWays("10111");


    return 0;
}
