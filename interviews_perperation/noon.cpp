#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void ReadDataWithSpeed() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifndef ONLINE_JUDGE

    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);

#endif
}



//
//int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
//
//    int n = gas.size(), total = 0, rev = 0, res = 0;
//    for (int i = 0; i < n; ++i) {
//        total += gas[i] - cost[i];
//        rev += gas[i] - cost[i];
//        if (rev < 0) {
//            rev = 0;
//            res = i + 1;
//        }
//    }
//
//    return total < 0 ? -1 : res;
//}
//
//
//string intToRoman(int num) {
//    string m[] = {"", "M", "MM", "MMM"};
//    string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
//    string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
//    string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
//
//    return m[num / 1000] + c[(num % 1000) / 100] + x[(num % 100) / 10] + i[num % 10];
//}

//vector<vector<int>> merge(vector<vector<int>> &intervals) {
//    vector<vector<int>> ans;
//    sort(begin(intervals), end(intervals));
//    int a = intervals[0][0], b = intervals[0][1];
//    for (auto v: intervals) {
//        if (v[0] > b) {
//            ans.push_back({a, b});
//            a = v[0];
//            b = v[1];
//        } else if (v[1] > b) b = v[1];
//    }
//    ans.push_back({a, b});
//    return ans;
//}
//
//
//vector<vector<int>> threeSum(vector<int> &nums) {
//    vector<vector<int>> res;
//
//    sort(nums.begin(), nums.end());
//
//    int n = nums.size();
//    for (int i = 0; i < n; ++i) {
////        if (nums[i] > 0) break;
////
////        if (nums[i] == nums[i - 1]) continue;
//
//        int low = i + 1, high = n - 1, sum = 0;
//        while (low < high) {
//            sum = nums[i] + nums[low] + nums[high];
//
//            if (sum > 0) high--;
//            else if (sum < 0) low++;
//
//            else {
//
//                res.push_back({nums[i], nums[low], nums[high]});
//                int lOld = nums[low], hOld = nums[high];
//
//                while (low < high && nums[low] == lOld) low++;
//                while (low < high && nums[high] == hOld) high--;
//            }
//
//
//        }
//    }
//    return res;
//}
int characterReplacement(string s, int k) {
    int n = s.length(), l = 0, r = 1;
    int sc = 0, oc = 0;
    if (s[l] == s[r]) sc++;
    else oc++;
    if (sc - oc >= k)
        return 0;
}

int main() {
    ReadDataWithSpeed();
//    vector<int> v = {-1, 0, 1, 2, -1, -4};
//    auto res = threeSum(v);

    cout << characterReplacement("ABAB", 2);
}
//         return s.substr(0, 8);

//     return to_string(stoi(h) + 12) + s.substr(2, 6);
// }

// bool compareAscending(string a, string b)
// {
//     if (a.size() == b.size())
//         return a < b;
//     return a.size() < b.size();
// }

// ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
// {

//     if (!l1)
//         return l2;
//     if (!l2)
//         return l1;

//     if (l1->val <= l2->val)
//     {
//         l1->next = mergeTwoLists(l1->next, l2);
//         return l1;
//     }

//     l2->next = mergeTwoLists(l1, l2->next);
//     return l2;
// }

// vector<string> bigSorting(vector<string> unsorted)
// {
//     sort(
//         unsorted.begin(), unsorted.end(), compareAscending);
//     return unsorted;
// }

// void insertionSort1(int n, vector<int> arr)
// {
//     int i = n - 1, target = arr.back();

//     for (; i > 0, target < arr[i - 1]; i--)
//     {
//         arr[i] = arr[i - 1];
//         for (int j = 0; j < n; j++)
//             cout << arr[j] << " ";
//         cout << endl;
//     }

//     arr[i] = target;
//     for (int j = 0; j < n; j++)
//         cout << arr[j] << " ";
//     cout << endl;
// }

// void insertionSort2(int n, vector<int> arr)
// {
//     for (int i = 1; i < n; i++)
//     {
//         int j = i;
//         while (j > 0 && arr[j] < arr[j - 1])
//         {
//             swap(arr[j], arr[j - 1]);
//             j--;
//         }
//         for (int j = 0; j < n; j++)
//             cout << arr[j] << " ";
//         cout << endl;
//     }
// }

// vector<int> quickSort(vector<int> arr)
// {
//     int pivot = arr[0];
//     int l = arr.size() - 1;
//     swap(arr[0], arr[l]);

//     int i = 0;
//     int j = l - 1;
//     while (i <= j)
//     {
//         while (i <= l && arr[i] < pivot)
//         {
//             i++;
//         }
//         while (j >= 0 && arr[j] > pivot)
//         {
//             j--;
//         }
//         if (i < j)
//         {
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[l], arr[i]);
//     return arr;
// }

// vector<int> quickSort2(vector<int> arr)
// {
//     int pivot = arr[0];
//     vector<int> left;
//     vector<int> right;

//     for (int i = 1; i < arr.size(); i++)
//     {
//         if (arr[i] < pivot)
//         {
//             left.push_back(arr[i]);
//         }
//         else
//         {
//             right.push_back(arr[i]);
//         }
//     }

//     vector<int> result;
//     result.insert(result.end(), left.begin(), left.end());
//     result.push_back(pivot);
//     result.insert(result.end(), right.begin(), right.end());
//     return result;
// }
// string mergeAlternately(string word1, string word2)
// {
//     string res = "";
//     for (int i = 0, j = 0; i < word1.length() || word2.length(); i++, j++)
//     {
//         if (i != word1.length())
//             res += word1[i];
//         if (j != word2.length())
//             res += word2[j];
//     }
//     return res;
// }

// // string gcdOfStrings(string str1, string str2)
// // {
// //     if (str1 + str2 != str2 + str1)
// //         return "";
// //     return str1.substr(0, gcd(str1.size(), str2.size()));
// // }
// vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
// {
//     int maxAmong = *max_element(candies.begin(), candies.end());
//     vector<bool> res;
//     for (auto element : candies)
//         res.push_back(((element + extraCandies) >= maxAmong));
//     return res;
// }

// class Solution
// {

//     bool isVowels(char ch)
//     {
//         return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
//     }

// public:
//     string reverseVowels(string s)
//     {
//         int n = s.length();
//         for (int i = 0, j = n - 1; i < n && j >= 0; i++)
//         {
//             if (i >= j)
//                 break;
//             if (isVowels(s[i]))
//             {
//                 while (!isVowels(s[j]))
//                     j--;
//                 swap(s[i], s[j]);
//                 j--;
//             }
//         }

//         return s;
//     }
// };

// void moveZeroes(vector<int> &nums)
// {
//     int n = nums.size();
//     for (int i = 0, j = 0; i < n; i++)
//     {
//         if (nums[i] != 0)
//         {
//             swap(nums[i], nums[j]);
//             j++;
//         }
//     }

//     reverse(nums.begin(), nums.end());
// }

// int maxOperations(vector<int> &nums, int k)
// {
//     int res = 0;
//     unordered_map<int, int> mp;
//     for (auto element : nums)
//         mp[element]++;

//     for (auto element : nums)
//     {
//         int diff = element - k;
//         if (mp[abs(diff)] > 0)
//             res++, mp[abs(diff)]--, mp[element]--;
//     }
//     return res;
// }

// int maxOperations(vector<int> &nums, int k)
// {
//     unordered_map<int, int> mp;
//     int res = 0;
//     for (auto element : nums)
//     {
//         if (mp[k - element] > 0)
//         {
//             res++;
//             mp[k - element]--;
//         }
//         else
//         {
//             mp[element]++;
//         }
//     }
//     return res;
// }

// class Solution
// {
// private:
//     bool isVowels(char ch)
//     {
//         return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
//     }

// public:
//     int maxVowels(string s, int k)
//     {
//         int n = s.length(), res = 0, cnt = 0;

//         for (int i = 0; i < n; i++)
//         {
//             if (i >= k && isVowels(s[i - k]))
//                 cnt--;

//             if (isVowels(s[i]))
//                 cnt++;
//             res = max(res, cnt);
//         }
//         return res;
//     }
// };

// int longestOnes(vector<int> &nums, int k)
// {
//     int n = nums.size(), mx = 0, cnt = 0;
//     for (int i = 0, j = k; i < n; i++)
//     {
//         if (nums[i] == 1 || (nums[i] == 0 && j > 0))
//         {
//             if (nums[i] == 0)
//             {
//                 j--;
//             }
//             cnt++;
//             mx = (mx, cnt);
//         }
//         else
//         {
//             j = k - 1;
//             cnt = 1;
//         }
//     }
//     return mx;
// }

// int pivotIndex(vector<int> &nums)
// {
//     int n = nums.size(), sum = 0, leftSum = 0;
//     for (auto element : nums)
//         sum += element;

//     for (int i = 0; i < n; i++)
//     {
//         if (leftSum == sum - leftSum - nums[i])
//             return i;
//         leftSum += nums[i];
//     }
//     return -1;
// }

// bool uniqueOccurrences(vector<int> &arr)
// {
//     unordered_map<int, int> mp;
//     unordered_set<int> st;
//     for (auto element : arr)
//         mp[element]++;

//     for (auto element : mp)
//         st.insert(element.second);

//     return st.size() == mp.size();
// }

// bool closeStrings(string word1, string word2)
// {
//     vector<int> fr1(26, 0), fr2(26, 0);
//     set<int> st1, st2;
//     for (auto element : word1)
//         fr1[element - 'a']++, st1.insert(element);
//     for (auto element : word2)
//         fr2[element - 'a']++, st2.insert(element);

//     sort(fr1.begin(), fr1.end());
//     sort(fr2.begin(), fr2.end());

//     return fr1 == fr2 && st1 == st2;
// }
// int equalPairs(vector<vector<int>> &grid)
// {
//     int res = 0;
//     unordered_map<int, int> mp;
//     for (auto element : grid)
//     {
//         for (int i = 0; i < element.size(); i++)
//         {
//             res += mp[element[i] - i];
//             mp[element[i] - i]++;
//         }
//     }
//     return res;
// }

// string ss(string s)
// {
//     stack<char> st;
//     for (auto element : s)
//         st.push(element);

//     string res = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         int n = res.size();
//         if (st.top() == '*')
//         {
//             st.pop();
//             if (n > 0)
//                 res = res.substr(0, n - 1);
//         }
//         else
//         {
//             res += st.top();
//             st.pop();
//         }
//     }
//     return res;
// }

// string removeStars(string s)
// {

//     string res = "";
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (s[i] == '*')
//         {
//             if (res.size() > 0)
//                 res.pop_back();
//         }
//         else
//         {
//             res += s[i];
//         }
//     }
// }
// int uniquePaths(int m, int n)
// {

//     vector<vector<int>> dp(m, vector<int>(n, 1));
//     for (int i = 1; i < m; i++)
//     {
//         for (int j = 1; j < n; j++)
//         {
//             dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//         }
//     }
//     return dp[m - 1][n - 1];
// }
// int longestCommonSubsequence(string text1, string text2)
// {
//     int sum = 0;
//     int n = text1.length(), m = text2.length();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (text1[i - 1] == text2[j - 1])
//             {
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             }
//             else
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//             }
//             sum = max(sum, dp[i][j]);
//         }
//     }

//     return sum;
// }

// int maxProfit(vector<int> &prices, int fee)
// {
//     int n = prices.size();
//     vector<vector<int>> dp(n, vector<int>(2, 0));
//     dp[0][0] = -prices[0];

//     for (int i = 1; i < n; i++)
//     {
//         dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
//         dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
//     }

//     return dp[n - 1][1];
// }
// int maxProfit(vector<int> &prices, int fee)
// {
//     int n = prices.size(), profit = 0, buy = prices[0];

//     for (auto element : prices)
//     {
//         profit = max(profit, element - buy - fee);
//         buy = min(buy, element - profit);
//     }
//     return profit;
// }
// int singleNumber(vector<int> &nums)
// {
//     int res = 0;
//     for (auto element : nums)
//         res ^= element;
//     return res;
// }

// vector<int> countBits(int n)
// {
//     vector<int> res(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//         res[i] = res[i & (i - 1)] + 1;
//     return res;
// }

// ListNode *deleteMiddle(ListNode *head)
// {
//     if (!head || !head->next)
//         return NULL;
//     ListNode *slow = head, *fast = head, *prev = NULL;
//     while (fast && fast->next)
//     {
//         prev = slow;
//         slow = slow->next;
//         fast = fast->next->next;
//     }
//     prev->next = slow->next;
//     return head;
// }

// ListNode *oddEvenList(ListNode *head)
// {
//     if (!head || !head->next)
//         return head;
//     ListNode *odd = head, *even = head->next, *evenHead = even;
//     while (even && even->next)
//     {
//         odd->next = even->next;
//         odd = odd->next;
//         even->next = odd->next;
//         even = even->next;
//     }
//     odd->next = evenHead;
//     return head;
// }

// class Solution
// {

// public:
//     bool leafSimilar(TreeNode *root1, TreeNode *root2)
//     {
//         vector<int> leaf1, leaf2;
//         dfs(root1, leaf1);
//         dfs(root2, leaf2);
//         return leaf1 == leaf2;
//     }
//     void dfs(TreeNode *root, vector<int> &leaf)
//     {
//         if (!root)
//             return;
//         if (!root->left && !root->right)
//             leaf.push_back(root->val);
//         dfs(root->left, leaf);
//         dfs(root->right, leaf);
//     }
// };

// class Solution
// {
// public:
//     int goodNodes(TreeNode *root)
//     {
//         return dfs(root, root->val);
//     }
//     int dfs(TreeNode *root, int mx)
//     {
//         if (!root)
//             return 0;
//         int res = root->val >= mx;
//         mx = max(mx, root->val);
//         return res + dfs(root->left, mx) + dfs(root->right, mx);
//     }
// };

// class Solution
// {
// public:
//     int pathSum(TreeNode *root, int targetSum)
//     {
//         if (!root)
//             return 0;
//         return dfs(root, targetSum) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
//     }
//     int dfs(TreeNode *root, int target)
//     {

//         if (!root)
//             return 0;
//         return (root->val == target) + dfs(root->left, target - root->val) + dfs(root->right, target - root->val);
//     }
// };

// class Solution
// {

//     int res = 0;

// public:
//     int longestZigZag(TreeNode *root)
//     {
//         dfs(root, true, 0);
//         dfs(root, false, 0);
//         return res;
//     }
//     void dfs(TreeNode *root, bool isLeft, int len)
//     {
//         if (!root)
//             return;
//         res = max(res, len);
//         if (isLeft)
//         {
//             dfs(root->left, false, len + 1);
//             dfs(root->right, true, 1);
//         }
//         else
//         {
//             dfs(root->right, true, len + 1);
//             dfs(root->left, false, 1);
//         }
//     }
// };

// TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
// {
//     if (!root)
//         return NULL;
//     if (p->val > root->val && q->val > root->val)
//         return lowestCommonAncestor(root->right, p, q);
//     if (p->val < root->val && q->val < root->val)
//         return lowestCommonAncestor(root->left, p, q);
//     return root;
// }

// string decodeString(string s)
// {
//     string res = "";
//     stack<int> count;
//     stack<string> st;
//     int i = 0, n = s.size();
//     while (i < n)
//     {
//         if (isdigit(s[i]))
//         {
//             int num = 0;
//             while (isdigit(s[i]))
//             {
//                 num = num * 10 + (s[i] - '0');
//                 i++;
//             }
//             count.push(num);
//         }
//         else if (s[i] == '[')
//         {
//             st.push(res);
//             res = "";
//             i++;
//         }
//         else if (s[i] == ']')
//         {
//             string temp = st.top();
//             st.pop();
//             int times = count.top();
//             count.pop();
//             for (int j = 0; j < times; j++)
//                 temp += res;
//             res = temp;
//             i++;
//         }
//         else
//         {
//             res += s[i];
//             i++;
//         }
//     }
// }

// class Solution
// {
//     unordered_map<int, int> mp;

// public:
//     int maxLevelSum(TreeNode *root)
//     {
//         dfs(root, 1);
//         int mx = INT_MIN, res = 0;
//         for (auto element : mp)
//         {
//             if (element.second > mx)
//             {
//                 mx = element.second;
//                 res = element.first;
//             }
//         }
//         return res;
//     }

//     void dfs(TreeNode *root, int level)
//     {
//         if (!root)
//             return;
//         mp[level] += root->val;

//         dfs(root->left, level + 1);
//         dfs(root->right, level + 1);
//     }
// };

// class Solution
// {
// public:
//     TreeNode *deleteNode(TreeNode *root, int key)
//     {
//         if (!root)
//             return NULL;
//         if (root->val > key)
//             root->left = deleteNode(root->left, key);
//         else if (root->val < key)
//             root->right = deleteNode(root->right, key);
//         else
//         {
//             if (!root->left)
//                 return root->right;
//             if (!root->right)
//                 return root->left;

//             TreeNode *temp = root->right;
//             while (temp->left)
//                 temp = temp->left;
//             root->val = temp->val;
//             root->right = deleteNode(root->right, temp->val);
//         }
//         return root;
//     }
// };

// class Solution
// {

// public:
//     bool canVisitAllRooms(vector<vector<int>> &rooms)
//     {
//         int n = rooms.size();
//         vector<bool> visited(n, false);
//         dfs(rooms, 0, visited);
//         for (auto element : visited)
//         {
//             if (!element)
//                 return false;
//         }
//         return true;
//     }
//     void dfs(vector<vector<int>> &rooms, int i, vector<bool> &visited)
//     {
//         if (visited[i])
//             return;
//         visited[i] = true;
//         for (auto element : rooms[i])
//             dfs(rooms, element, visited);
//     }
// };
//class Solution {
//public:
//    int sumOfEncryptedInt(vector<int> &nums) {
//
//        // if nums[i] is more than 10 convert it to make digits ex: 1235 -> 5555
//        for (int i = 0; i < nums.size(); i++) {
//            if (nums[i] > 10) {
//                nums[i] = convertNumberToMaxSameDigits(nums[i]);
//            }
//        }
//
//        // print nums
//        for (auto element: nums)
//            cout << element << " ";
//        cout << endl;
//
//        // int sum = 0;
//        // for (auto element : nums)
//        //     sum += element;
//        // return sum;
//    }
//
//    int convertNumberToMaxSameDigits(int n) {
//        int number = mxDigits(n), res = 0, fact = 1;
//
//        while (n / 10 > 0) {
//            res = res + number * fact;
//            fact = fact * 10;
//            n = n / 10;
//        }
//        return res + number * fact;
//    }
//
//    int mxDigits(int n) {
//        int largest = 0;
//
//        while (n) {
//            int r = n % 10;
//
//            // Find the largest digit
//            largest = max(r, largest);
//
//            n = n / 10;
//        }
//        return largest;
//    }
//};
// 1 / 10
/*
    if (root!=NULL ) return 0;

        if (target == root->val) return 1;

        if (root->left ==NULL && root->right ==NULL) return 0;


        return  dfs(root->left,target-root->val) + dfs(root->right,target-root->val);
 */
//
//int findKthLargest(vector<int> &nums, int k) {
//    // partial_sort(nums.begin(), nums.begin() + k, nums.end(), greater<int>());
//    // return nums[k - 1];
//
//    priority_queue<int, vector<int>, greater<int>> pq;
//    for (auto element: nums) {
//        pq.push(element);
//        if (pq.size() > k)
//            pq.pop();
//    }
//    // for (auto element : pq)
//    //     cout << element << " ";
//    // cout << endl;
//    // print pq
//    // while (!pq.empty())
//    // {
//    //     cout << pq.top() << " ";
//    //     pq.pop();
//    // }
//    // cout << endl;
//
//    return pq.top();
//
//    // sort(nums.begin(), nums.end());
//
//    // print nums
//    // for (auto element : nums)
//    //     cout << element << " ";
//    // cout << endl;
//
//    // return nums[nums.size() - k];
//}

// struct TrieNode
// {
//     bool isEnd;
//     TrieNode *children[26];
//     TrieNode() : isEnd(false)
//     {
//         for (int i = 0; i < 26; i++)
//             children[i] = NULL;
//     }
// };

// class Trie
// {

//     TrieNode *root;

// public:
//     Trie()
//     {
//         root = new TrieNode();
//     }

//     void insert(string word)
//     {
//         TrieNode *node = root;
//         for (auto ch : word)
//         {
//             if (!node->children[ch - 'a'])
//                 node->children[ch - 'a'] = new TrieNode();
//             node = node->children[ch - 'a'];
//         }
//         node->isEnd = true;
//     }

//     bool search(string word)
//     {
//         TrieNode *node = root;
//         for (auto ch : word)
//         {
//             if (!node->children[ch - 'a'])
//                 return false;
//             node = node->children[ch - 'a'];
//         }
//         return node->isEnd;
//     }

//     bool startsWith(string prefix)
//     {
//         TrieNode *node = root;
//         for (auto ch : prefix)
//         {
//             if (!node->children[ch - 'a'])
//                 return false;
//             node = node->children[ch - 'a'];
//         }
//         return true;
//     }
// };

//class Solution
//{
//
//public:
//    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
//    {
//        sort(products.begin(), products.end());
//        vector<vector<string>> res;
//        for (int i = 1; i <= searchWord.size(); i++)
//        {
//            string temp = searchWord.substr(0, i);
//            vector<string> tempRes;
//            for (auto element : products)
//            {
//                if (element.substr(0, i) == temp)
//                {
//                    tempRes.push_back(element);
//                    if (tempRes.size() == 3)
//                        break;
//                }
//            }
//            res.push_back(tempRes);
//        }
//        return res;
//    }
//};
//
//class Solution
//{
//public:
//    int eraseOverlapIntervals(vector<vector<int>> &intervals)
//    {
//        int res = 0;
//        if (intervals.size() == 0)
//            return 0;
//
//        sort(
//            intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
//            { return a[1] < b[1]; });
//
//        vector<int> prev = intervals[0];
//
//        for (auto e : intervals)
//        {
//            if (prev[1] > e[0])
//                res++;
//
//            else
//                prev = e;
//        }
//
//        return res;
//    }
//};
//
//struct SinglyLinkedListNode
//{
//    int data;
//    SinglyLinkedListNode *next;
//};
//
//SinglyLinkedListNode *mergeLists(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
//{
//    if (!head1)
//        return head2;
//    if (!head2)
//        return head1;
//
//    if (head1->data < head2->data)
//    {
//        head1->next = mergeLists(head1->next, head2);
//        return head1;
//    }
//    else
//    {
//        head2->next = mergeLists(head1, head2->next);
//        return head2;
//    }
//}
//
//string reverseWords(string s)
//{
//    int n = s.size();
//    int i = 0;
//    for (int j = 0; j < n; j++)
//    {
//        if (s[j] == ' ')
//        {
//            reverse(s.begin() + i, s.begin() + j);
//            i = j + 1;
//        }
//    }
//    reverse(s.begin() + i, s.end());
//    return s;
//}
//
//bool increasingTriplet(vector<int> &nums)
//{
//
//    for (int i = 0, j = 1, k = 2; k < nums.size();)
//    {
//        if (nums[i] < nums[j] && nums[j] < nums[k])
//            return true;
//
//        else if (nums[i] < nums[j])
//            k++;
//
//        else
//        {
//            i++, j++, k++;
//        }
//    }
//
//    return false;
//}
//class Solution
//{
//public:
//    vector<string> letterCombinations(string digits)
//    {
//        vector<string> res;
//        if (digits.size() == 0)
//            return res;
//        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//        res.push_back("");
//        for (auto digit : digits)
//        {
//            vector<string> temp;
//            for (auto element : res)
//            {
//                for (auto ch : mp[digit - '0'])
//                {
//                    temp.push_back(element + ch);
//                }
//            }
//            res = temp;
//        }
//        return res;
//    }
//};
//
//class Solution
//{
//public:
//    vector<double> averageOfLevels(TreeNode *root)
//    {
//        if (!root)
//            return {};
//
//        vector<double> res;
//        queue<TreeNode *> q;
//        q.push(root);
//
//        while (!q.empty())
//        {
//            int n = q.size();
//            double sum = 0;
//            for (int i = 0; i < n; i++)
//            {
//                TreeNode *node = q.front();
//                q.pop();
//                sum += node->val;
//                if (node->left)
//                    q.push(node->left);
//                if (node->right)
//                    q.push(node->right);
//            }
//            res.push_back(sum / n);
//        }
//        return res;
//    }
//};
//
//class Solution
//{
//    unordered_set<int> st;
//
//public:
//    bool findTarget(TreeNode *root, int k)
//    {
//        if (!root)
//            return false;
//        if (st.count(k - root->val))
//            return true;
//        st.insert(root->val);
//        return findTarget(root->left, k) || findTarget(root->right, k);
//    }
//};
//
//struct DoublyLinkedListNode
//{
//    int data;
//    DoublyLinkedListNode *next;
//    DoublyLinkedListNode *prev;
//};
//
//DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *list, int data)
//{
//    DoublyLinkedListNode *newElement = new DoublyLinkedListNode();
//
//    newElement->data = data;
//    newElement->next = NULL;
//    newElement->prev = NULL;
//
//    if (!list)
//        return newElement;
//
//    if (data < list->data)
//    {
//        newElement->next = list;
//        list->prev = newElement;
//        return newElement;
//    }
//
//    DoublyLinkedListNode *temp = list;
//    while (temp->next && temp->next->data < data)
//        temp = temp->next;
//
//    newElement->next = temp->next;
//    if (temp->next)
//        temp->next->prev = newElement;
//    temp->next = newElement;
//    newElement->prev = temp;
//
//    return list;
//}
//
//int main()
//{
//    // Solution sol = Solution();
//    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 5, 5, 5, 6};
//    // sol.sumOfEncryptedInt(nums);
//    int x = findKthLargest(nums, 4);
//    cout << x << endl;
//
//    string s = "abc";
//
//    set<int> st;
//    st.insert(1);
//    int lastOne = *st.end();
//    st.erase(st.end());
//    return 0;
//}
