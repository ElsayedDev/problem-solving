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

// class Solution
// {
// public:
//     int majorityElement(const vector<int> &A)
//     {
//         int count = 0;
//         int candidate = -1;

//         for (int num : A)
//         {
//             if (count == 0)
//             {
//                 candidate = num;
//             }
//             count += (num == candidate) ? 1 : -1;
//         }

//         return candidate;
//     }

//     vector<int> getRow(int A)
//     {
//         vector<int> row(A + 1, 1);

//         for (int i = 1; i < A; i++)
//         {
//             for (int j = i; j > 0; j--)
//             {
//                 row[j] += row[j - 1];
//             }
//         }
//         return row;
//     }

//     int repeatedNumber(const vector<int> &A)
//     {
//         int slow = A[0];
//         int fast = A[0];

//         // Phase 1: Finding the intersection point in the cycle
//         do
//         {
//             slow = A[slow];
//             fast = A[A[fast]];
//         } while (slow != fast);

//         // Phase 2: Finding the entrance to the cycle
//         slow = A[0];
//         while (slow != fast)
//         {
//             slow = A[slow];
//             fast = A[fast];
//         }

//         return slow;
//     }

//     vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
//     {
//         if (A.empty())
//             return B;

//         if (B.empty())
//             return A;

//         vector<int> result;
//         int i = 0, j = 0;
//         while (i < A.size() && j < B.size())
//         {

//             if (A[i] < B[j])
//             {
//                 result.push_back(A[i]);
//                 i++;
//             }
//             else
//             {
//                 result.push_back(B[j]);
//                 j++;
//             }
//         }
//         while (i < A.size())
//         {
//             result.push_back(A[i]);
//             i++;
//         }
//         while (j < B.size())
//         {
//             result.push_back(B[j]);
//             j++;
//         }

//         return result;
//     }

//     vector<int> twoSum(vector<int> &nums, int target)
//     {
//         // use 2 pointers
//         int n = nums.size();
//         vector<pair<int, int>> numsI;
//         for (int i = 0; i < n; i++)
//             numsI.push_back({nums[i], i});

//         sort(numsI.begin(), numsI.end());
//         int left = 0, right = n - 1;
//         while (left < right)
//         {
//             int sum = numsI[left].first + numsI[right].first;

//             if (sum == target)
//             {
//                 return {numsI[left].second, numsI[right].second};
//             }

//             if (sum < target)
//                 left++;
//             else
//                 right--;
//         }

//         return {};
//     }

//     int maxSubArray(vector<int> &nums)
//     {
//         int maxEndingHere = nums[0], maxSoFar = nums[0];

//         for (size_t i = 0; i < nums.size(); i++)
//         {
//             maxEndingHere = max(maxEndingHere, nums[i] + maxEndingHere);
//             maxSoFar = max(maxEndingHere, maxSoFar);
//         }

//         return maxSoFar;
//     }

//     bool containsDuplicate(vector<int> &nums)
//     {
//         unordered_set<int> seen;
//         for (int num : nums)
//         {
//             if (seen.count(num))
//                 return true;
//             seen.insert(num);
//         }
//         return false;
//     }
//     void rotate(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         k = k % n; // to handle cases where k > n because rotating n times results in the same array

//         auto reverseRange = [&](int start, int end)
//         {
//             while (start < end)
//                 swap(nums[start++], nums[end--]);
//         };

//         reverseRange(0, n - 1);
//         reverseRange(0, k - 1);
//         reverseRange(k, n - 1);
//     }
//     auto reverseRange(vector<int> &nums, int start, int end)
//     {
//         while (start < end)
//             swap(nums[start++], nums[end--]);
//     };

//     void rotate(vector<vector<int>> &matrix)
//     {
//         int n = matrix.size();
//         // Transpose the matrix
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = i; j < n; j++)
//             {
//                 swap(matrix[i][j], matrix[j][i]);
//             }
//         }

//         // Reverse each row
//         for (int i = 0; i < n; i++)
//         {
//             reverseRange(matrix[i], 0, n - 1);
//         }
//     }

//     bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
//     {
//         // 0 -> 0-deg , 1 -> 90-deg , 2 -> 180-deg , 3 -> 270-deg
//         bool isOkRotations[4] = {true, true, true, true};
//         int deg = 0, n = target.size();

//         do
//         {
//             for (int i = 0; i < n && isOkRotations[deg]; i++)
//             {
//                 for (int j = 0; j < n; j++)
//                 {
//                     int matElement = mat[i][j];
//                     if (deg == 0)
//                         isOkRotations[deg] &= matElement == target[i][j];

//                     else if (deg == 1)
//                         isOkRotations[deg] &= matElement == target[j][n - 1 - i];
//                     else if (deg == 2)
//                         isOkRotations[deg] &=
//                             matElement == target[n - 1 - i][n - 1 - j];
//                     else if (deg == 3)
//                         isOkRotations[deg] &= matElement == target[n - 1 - j][i];
//                 }
//             }

//             if (isOkRotations[deg])
//                 return true;

//             deg++;
//         } while (deg < 4);

//         return false;
//     };

//     string LongestWord(string sen)
//     {
//         int maxLength = 0, currentLength = 0;
//         string maxWord = "", currentWord = "";

//         for (char c : sen)
//         {
//             // in-case of non-alphabetic character
//             if (!isalpha(c))
//             {
//                 currentWord = "";
//                 currentLength = 0;

//                 continue;
//             }

//             currentWord.push_back(c);
//             currentLength++;

//             if (currentLength > maxLength)
//             {
//                 maxLength = currentLength;
//                 maxWord = currentWord;
//             }
//         }

//         return maxWord;
//     }

//     int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
//     {
//         int totalGas = 0, totalCost = 0;
//         int currentGas = 0, startingStation = 0;
//         int n = gas.size();
//         for (int i = 0; i < n; i++)
//         {
//             totalGas += gas[i];
//             totalCost += cost[i];
//             currentGas += gas[i] - cost[i];

//             // If currentGas drops below 0, reset starting station and currentGas
//             if (currentGas < 0)
//             {
//                 startingStation = i + 1;
//                 currentGas = 0;
//             }
//         }

//         // If total gas is less than total cost, it's impossible to complete the circuit
//         if (totalGas < totalCost)
//         {
//             return -1;
//         }

//         return startingStation;
//     }

//     vector<int> spiralOrder(vector<vector<int>> &matrix)
//     {
//         vector<int> result;
//         if (matrix.empty())
//             return result;

//         int top = 0, bottom = matrix.size() - 1;
//         int left = 0, right = matrix[0].size() - 1;

//         while (top <= bottom && left <= right)
//         {
//             // Traverse from left to right
//             for (int j = left; j <= right; j++)
//                 result.push_back(matrix[top][j]);
//             top++;

//             // Traverse from top to bottom
//             for (int i = top; i <= bottom; i++)
//                 result.push_back(matrix[i][right]);
//             right--;

//             // Traverse from right to left
//             if (top <= bottom)
//             {
//                 for (int j = right; j >= left; j--)
//                     result.push_back(matrix[bottom][j]);
//                 bottom--;
//             }

//             // Traverse from bottom to top
//             if (left <= right)
//             {
//                 for (int i = bottom; i >= top; i--)
//                     result.push_back(matrix[i][left]);
//                 left++;
//             }
//         }

//         return result;
//     }

//     int firstUniqChar(string s)
//     {
//         int freq[26] = {-1};

//         int n = s.length();

//         for (int i = 0; i < s.length(); i++)
//         {
//             if (freq[s[i] - 'a'] == -1)
//                 freq[s[i] - 'a'] = i;

//             else
//             {
//                 freq[s[i] - 'a'] = n;
//             }
//         }

//         for (int i = 0; i < 26; i++)
//         {
//             if (freq[i] != -1 && freq[i] != 27)
//             {
//                 n = min(n, freq[i]);
//             }
//         }
//     }
//     vector<int> spiralOrder(vector<vector<int>> &matrix)
//     {
//         vector<int> result;
//         int n = matrix.size();

//         int right = n - 1, left = 0, top = 0, bottom = n - 1;

//         while (left <= right && top <= bottom)
//         {
//             for (int i = left; i <= right; i++)
//                 result.push_back(matrix[top][i]);
//             top++;

//             for (int i = top; i <= bottom; i++)
//                 result.push_back(matrix[i][right]);
//             right--;

//             if (top <= bottom)
//             {
//                 for (int i = right; i >= left; i--)
//                     result.push_back(matrix[bottom][i]);
//                 bottom--;
//             }

//             if (left <= right)
//             {
//                 for (int i = bottom; i >= top; i--)
//                     result.push_back(matrix[i][left]);
//                 left++;
//             }
//         }

//         return result;
//     }

//     string longestPalindrome(string s)
//     {
//         int n = s.length();

//         auto expandAroundCenter = [&](int left, int right) -> pair<int, int>
//         {
//             while (left >= 0 && right < n && s[left] == s[right])
//             {
//                 left--;
//                 right++;
//             }
//             return {left + 1, right - 1};
//         };

//         int maxLength = 1;
//         int start = 0, end = 0;
//         for (int i = 0; i < n; i++)
//         {
//             // Odd length palindromes
//             auto [left1, right1] = expandAroundCenter(i, i);
//             if (right1 - left1 + 1 > maxLength)
//             {
//                 maxLength = right1 - left1 + 1;
//                 start = left1;
//                 end = right1;
//             }

//             // Even length palindromes
//             auto [left2, right2] = expandAroundCenter(i, i + 1);
//             if (right2 - left2 + 1 > maxLength)
//             {
//                 maxLength = right2 - left2 + 1;
//                 start = left2;
//                 end = right2;
//             }
//         }

//         return s.substr(start, maxLength);
//     }

//     int longestConsecutive(vector<int> &nums)
//     {
//         unordered_set<int> numSet(nums.begin(), nums.end());
//         int longestStreak = 0;

//         for (int num : nums)
//         {
//             if (!numSet.count(num - 1))
//             {
//                 int currentNum = num;
//                 int currentStreak = 1;

//                 while (numSet.count(currentNum + 1))
//                 {
//                     currentNum++;
//                     currentStreak++;
//                 }

//                 longestStreak = max(longestStreak, currentStreak);
//             }
//         }

//         return longestStreak;
//     }

//     bool canPartition(vector<int> &nums)
//     {
//         int totalSum = 0;
//         for (int num : nums)
//             totalSum += num;

//         if (totalSum % 2 != 0)
//             return false;

//         int target = totalSum / 2;
//         vector<bool> dp(target + 1, false);
//         dp[0] = true;

//         for (int num : nums)
//         {
//             for (int j = target; j >= num; j--)
//             {
//                 dp[j] = dp[j] || dp[j - num];
//             }

//             if (dp[target])
//                 return true;
//         }

//         return dp[target];
//     }

//     string longestDupSubstring(string s)
//     {
//         int n = s.length();
//         int left = 1, right = n - 1;
//         string result = "";

//         auto search = [&](int length) -> int
//         {
//             unordered_set<string> seen;
//             for (int i = 0; i <= n - length; i++)
//             {
//                 string substring = s.substr(i, length);
//                 if (seen.count(substring))
//                     return i;
//                 seen.insert(substring);
//             }
//             return -1;
//         };

//         while (left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             int startIdx = search(mid);

//             if (startIdx != -1)
//             {
//                 result = s.substr(startIdx, mid);
//                 left = mid + 1;
//             }
//             else
//             {
//                 right = mid - 1;
//             }
//         }

//         return result;
//     }

//     int carFleet(int target, vector<int> &position, vector<int> &speed)
//     {
//         auto calcTime = [&](pair<int, int> car) -> int
//         {
//             return (target - car.first) / car.second;
//         };

//         int n = position.size();
//         vector<pair<int, int>> cars;

//         for (int i = 0; i < n; i++)
//             cars.push_back({position[i], speed[i]});

//         sort(cars.begin(), cars.end(), greater<pair<int, int>>());

//         int fleet = 1, group = 1;

//         double leadTime = calcTime(cars[0]);
//         for (int i = 1; i < n; i++)
//         {
//             double currentTime = calcTime(cars[i]);

//             if (currentTime > leadTime)
//             {
//                 fleet++;
//                 leadTime = currentTime;
//             }
//         }

//         return fleet;
//     }

//     bool isValid(string s)
//     {
//         stack<char> stk;
//         unordered_map<char, char> bracketMap = {
//             {')', '('},
//             {'}', '{'},
//             {']', '['}};

//         for (char c : s)
//         {
//             if (bracketMap.count(c))
//             {
//                 if (stk.empty() || stk.top() != bracketMap[c])
//                     return false;
//                 stk.pop();
//                 continue;
//             }

//             stk.push(c);
//         }

//         return stk.empty();
//     }

//     string removeDuplicates(string s)
//     {

//         stack<char> stk;
//         for (char c : s)
//         {
//             if (!stk.empty() && stk.top() == c)
//             {
//                 stk.pop();
//             }
//             else
//             {
//                 stk.push(c);
//             }
//         }

//         string result;
//         while (!stk.empty())
//         {
//             result.push_back(stk.top());
//             stk.pop();
//         }
//         reverse(result.begin(), result.end());

//         return result;
//     }
// };

// class BST
// {
// private:
//     struct Node
//     {
//         int data;
//         Node *left;
//         Node *right;

//         Node(int val) : data(val), left(nullptr), right(nullptr) {}
//     };

//     Node *root;

// public:
//     BST() : root(nullptr) {}

//     void insert(int val)
//     {
//         Node *node = new Node(val);

//         if (root == nullptr)
//         {
//             root = node;
//             return;
//         }

//         Node *current = root;
//         Node *parent = nullptr;
//         while (current != nullptr)
//         {
//             parent = current;
//             if (val < current->data)
//             {
//                 current = current->left;
//             }
//             else
//             {
//                 current = current->right;
//             }
//         }

//         if (val < parent->data)
//         {
//             parent->left = node;
//         }
//         else
//         {
//             parent->right = node;
//         }
//     }
// };

// class Graph
// {
// private:
//     unordered_map<int, vector<int>> adjList;

// public:
//     void addVertex(int v)
//     {
//         adjList[v] = vector<int>();
//     }

//     void addEdge(int u, int v)
//     {
//         adjList[u].push_back(v);
//         adjList[v].push_back(u); // For undirected graph
//     }
// };

// int findFac(int number)
// {
//     if (number == 2)
//         return 2;

//     if (number == 1)
//         return 1;

//     return findFac(number - 1) * number;
// }

// class SortAlgo
// {

//     vector<int> bubbleSort(vector<int> &v)
//     {
//         int n = v.size();
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < n - 1; j++)
//             {
//                 if (v[j] > v[j + 1])
//                 {
//                     swap(v[j], v[j + 1]);
//                 }
//             }
//         }
//     };

//     void selectionSort(vector<int> &v)
//     {
//         int n = v.size();
//         for (int i = 0; i < n; i++)
//         {
//             int smallestIndex = i;

//             for (int j = i; j < n; j++)
//             {
//                 if (v[j] < v[smallestIndex])
//                     smallestIndex = j;
//             }

//             swap(v[i], v[smallestIndex]);
//         }
//     };

//     void insertionSort(vector<int> &v)
//     {
//         int n = v.size();
//         for (int i = 1; i < n; i++)
//         {
//             int j = i - 1, temp = v[i];

//             while (j >= 0 && v[j] > temp)
//             {
//                 v[j + 1] = v[j];
//                 j--;
//             }

//             v[j + 1] = temp;
//         }
//     }

//     void mergeSort(vector<int> &v, int left, int right)
//     {
//         if (left >= right)
//             return;

//         int mid = left + (right - left) / 2;
//         mergeSort(v, left, mid);
//         mergeSort(v, mid + 1, right);

//         merge(v, left, mid, right);
//     }
//     void merge(vector<int> &v, int left, int mid, int right)
//     {
//         int n1 = mid - left + 1;
//         int n2 = right - mid;

//         vector<int> L(n1);
//         vector<int> R(n2);

//         for (int i = 0; i < n1; i++)
//             L[i] = v[left + i];
//         for (int j = 0; j < n2; j++)
//             R[j] = v[mid + 1 + j];

//         int i = 0, j = 0, k = left;
//         while (i < n1 && j < n2)
//         {
//             if (L[i] <= R[j])
//             {
//                 v[k] = L[i];
//                 i++;
//             }
//             else
//             {
//                 v[k] = R[j];
//                 j++;
//             }
//             k++;
//         }

//         while (i < n1)
//         {
//             v[k] = L[i];
//             i++;
//             k++;
//         }

//         while (j < n2)
//         {
//             v[k] = R[j];
//             j++;
//             k++;
//         }
//     }
// };

// class BFS
// {
// public:
//     void bfs(unordered_map<int, vector<int>> &graph, int start)
//     {
//         unordered_set<int> visited;
//         queue<int> q;

//         q.push(start);
//         visited.insert(start);

//         while (!q.empty())
//         {
//             int node = q.front();
//             q.pop();

//             for (auto element : graph[node])
//             {

//                 if (!visited.count(node))
//                 {
//                     q.push(element);
//                     visited.insert(element);

//                     // TODO: logic here
//                 }
//             }
//         }
//     }
//     void bfs(vector<int> tree)
//     {
//         queue<int> q;
//         q.push(0);

//         while (!q.empty())
//         {
//             int nodeIndex = q.front();
//             q.pop();

//             int leftChildIndex = 2 * nodeIndex + 1;
//             int rightChildIndex = 2 * nodeIndex + 2;

//             if (leftChildIndex < tree.size())
//                 q.push(leftChildIndex);

//             if (rightChildIndex < tree.size())
//                 q.push(rightChildIndex);
//         }
//     }

//     // bfs using recursion
//     void bfsRecursive(unordered_map<int, vector<int>> &graph, queue<int> &q, unordered_set<int> &visited)
//     {
//         if (q.empty())
//             return;
//         int node = q.front();
//         q.pop();
//         for (auto element : graph[node])
//         {

//             if (!visited.count(node))
//             {
//                 q.push(element);
//                 visited.insert(element);
//             }
//         }
//         bfsRecursive(graph, q, visited);
//     }
//     // DFS

//     void DFS()
//     {
//         // inorder:     l -> root -> r
//         // preorder:    root -> l -> r
//         // postorder:   l -> r -> root
//     }

//     void DFSInorder(TreeNode *root, vector<int> result)
//     {
//         if (!root)
//             return;

//         DFSInorder(root->left, result);
//         result.push_back(root->val);
//         DFSInorder(root->right, result);
//     }
//     void DFSPreorder(TreeNode *root, vector<int> result)
//     {
//         if (!root)
//             return;

//         result.push_back(root->val);
//         DFSInorder(root->left, result);
//         DFSInorder(root->right, result);
//     }
//     void DFSPostorder(TreeNode *root, vector<int> result)
//     {
//         if (!root)
//             return;

//         DFSInorder(root->left, result);
//         DFSInorder(root->right, result);
//         result.push_back(root->val);
//     }
// };

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;

//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// class Solution
// {
//     vector<TreeNode *> rAncestors, lAncestors;
//     TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
//     {
//         dfs(root, rAncestors);
//         dfs(root, lAncestors);

//         int minLength = min(rAncestors.size(), lAncestors.size());
//         TreeNode *lca = nullptr;

//         for (int i = 0; i < minLength; i++)
//         {
//             if (rAncestors[i] == lAncestors[i])
//                 lca = rAncestors[i];
//             else
//                 break;
//         }

//         return lca;
//     };

//     void dfs(TreeNode *root, vector<TreeNode *> &v)
//     {
//         if (!root)
//             return;

//         v.push_back(root);

//         dfs(root->left, v);
//         dfs(root->right, v);
//     };

//     unordered_set<int> visited;
//     TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
//     {
//         if (preorder.empty() || inorder.empty())
//             return nullptr;

//         if (visited.count(preorder[0]))
//             return nullptr;

//         visited.insert(preorder[0]);

//         TreeNode *root = new TreeNode(preorder[0]);

//         preorder.erase(preorder.begin());
//         inorder.erase(find(inorder.begin(), inorder.end(), root->val));

//         TreeNode *left = buildTree(preorder, inorder);
//         TreeNode *right = buildTree(preorder, inorder);

//         return root;
//     }

//     bool checkInclusion(string s1, string s2)
//     {
//         int s1Size = s1.size(), s2Size = s2.size();
//         if (s1Size > s2Size)
//             return false;

//         int freq1[26] = {0}, freq2[26] = {0};

//         for (auto c : s1)
//             freq1[c - 'a']++;

//         for (int i = 0; i < s1Size; i++)
//             freq2[s2[i] - 'a']++;

//         auto matches = [&]() -> bool
//         {
//             for (int i = 0; i < 26; i++)
//                 if (freq1[i] != freq2[i])
//                     return false;
//             return true;
//         };

//         if (matches())
//             return true;

//         for (int i = s1Size; i < s2Size; i++)
//         {
//             freq2[s2[i] - 'a']++;
//             freq2[s2[i - s1Size] - 'a']--;
//             if (matches())
//                 return true;
//         }

//         return false;
//     }

//     string minWindow(string s, string t)
//     {
//         int m = s.size(), n = t.size();
//         if (m < n)
//             return "";

//         int need[26] = {0}, window[26] = {0};

//         for (char c : t)
//             need[c - 'a']++;

//         int left = 0, right = 0;
//         int valid = 0;
//         int start = 0, minLength = INT_MAX;
//         while (right < m)
//         {
//             char c = s[right];
//             right++;

//             if (need[c - 'a'] > 0)
//             {
//                 window[c - 'a']++;
//                 if (window[c - 'a'] == need[c - 'a'])
//                     valid++;
//             }

//             while (valid == n)
//             {
//                 if (right - left < minLength)
//                 {
//                     start = left;
//                     minLength = right - left;
//                 }

//                 char d = s[left];
//                 left++;

//                 if (need[d - 'a'] > 0)
//                 {
//                     if (window[d - 'a'] == need[d - 'a'])
//                         valid--;
//                     window[d - 'a']--;
//                 }
//             }
//         }
//         return minLength == INT_MAX ? "" : s.substr(start, minLength);
//     }
// };
// class KthLargest
// {
// private:
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int k;

// public:
//     KthLargest(int k, vector<int> &nums)
//     {
//         this->k = k;
//         for (int val : nums)
//         {
//             pq.push(val);
//             if (pq.size() > k)
//             {
//                 pq.pop();
//             }
//         }
//     }

//     int add(int val)
//     {
//         pq.push(val);
//         if (pq.size() > k)
//         {
//             pq.pop();
//         }
//         return pq.top();
//     }
// };

// // class Solution
// // {
// // public:
// //     int numIslands(vector<vector<char>> &grid)
// //     {
// //         if (grid.empty())
// //             return 0;

// //         int m = grid.size(), n = grid[0].size(), lands = 0;
// //         set<pair<int, int>> visited;

// //         function<void(int, int)> bfs =
// //             [&](int r, int c)
// //         {
// //             queue<pair<int, int>> q;
// //             q.push({r, c});
// //             visited.insert({r, c});

// //             vector<pair<int, int>> directions = {
// //                 {1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// //             while (!q.empty())
// //             {
// //                 auto [row, col] = q.front();
// //                 q.pop();

// //                 for (auto [dr, dc] : directions)
// //                 {
// //                     int newRow = row + dr;
// //                     int newCol = col + dc;

// //                     if (newRow >= 0 && newRow < m &&
// //                         newCol >= 0 && newCol < n &&
// //                         grid[newRow][newCol] == '1' &&
// //                         !visited.count({newRow, newCol}))
// //                     {
// //                         q.push({newRow, newCol});
// //                         visited.insert({newRow, newCol});
// //                     }
// //                 }
// //             }
// //         };

// //         for (int i = 0; i < m; i++)
// //         {
// //             for (int j = 0; j < n; j++)
// //             {
// //                 if (grid[i][j] == '1' && !visited.count({i, j}))
// //                 {
// //                     lands++;
// //                     bfs(i, j);
// //                 }
// //             }
// //         }

// //         return lands;
// //     }
// // };

struct SinglyLinkedListNode
{
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int x) : data(x), next(nullptr) {}
};

SinglyLinkedListNode *removeKthNodeFromEnd(SinglyLinkedListNode *head, int k)
{
    if (!head || k <= 0)
        return head;

    SinglyLinkedListNode dummy(0);
    dummy.next = head;

    SinglyLinkedListNode *fast = &dummy;
    SinglyLinkedListNode *slow = &dummy;

    // move fast k steps
    for (int i = 0; i < k; i++)
    {
        if (!fast->next)
            return head; // k > length
        fast = fast->next;
    }

    // move both until fast reaches last node
    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // remove slow->next
    slow->next = slow->next->next;
    return dummy.next;
}

//  test removeKthNodeFromEnd

int main()
{
    SinglyLinkedListNode *head = new SinglyLinkedListNode(5);
    head->next = new SinglyLinkedListNode(1);

    int k = 1;
    head = removeKthNodeFromEnd(head, k);

    // print list
    SinglyLinkedListNode *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}