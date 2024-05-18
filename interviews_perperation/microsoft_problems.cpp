#include <bits/stdc++.h>
// #include <common.h>

using namespace std;

#define ll long long int

// Node *connect(Node *root) {
//     if (!root)
//         return NULL;
//
//     Node *head = root;
//     while (head) {
//
//         Node *curr = head;
//
//         while (curr) {
//             if (curr->left)
//                 curr->left->next = curr->right;
//             if (curr->right && curr->next)
//                 curr->right->next = curr->next->left;
//             curr = curr->next;
//         }
//
//         head = head->left;
//     }
//
//     return head;
// }
//
// void rightSideViewBFS(TreeNode *root, vector<int> &res, int level) {
//     if (!root)
//         return;
//
//     if (res.size() < level)
//         res.push_back(root->val);
//
//     rightSideViewBFS(root->right, res, level + 1);
//     rightSideViewBFS(root->left, res, level + 1);
// }
//
// vector<int> rightSideView(TreeNode *root) {
//     vector<int> res;
//     rightSideViewBFS(root, res, 1);
//
//     return res;
// }

// vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
//{
//     unordered_map<int, vector<int>> map;
//
//     // find all the parents of the nodes
//     function<void(TreeNode *)> dfs = [&](TreeNode *node)
//     {
//         if (!node)
//             return;
//         if (node->left)
//         {
//             map[node->val].push_back(node->left->val);
//             map[node->left->val].push_back(node->val);
//             dfs(node->left);
//         }
//         if (node->right)
//         {
//             map[node->val].push_back(node->right->val);
//             map[node->right->val].push_back(node->val);
//             dfs(node->right);
//         }
//     };
//
//     dfs(root);
//
//     vector<int> res;
//     queue<int> q;
//     unordered_set<int> visited;
//     q.push(target->val);
//     visited.insert(target->val);
//
//     while (!q.empty() && k >= 0)
//     {
//         int size = q.size();
//         while (size--)
//         {
//             int curr = q.front();
//             q.pop();
//             if (k == 0)
//                 res.push_back(curr);
//             for (int n : map[curr])
//             {
//                 if (visited.count(n))
//                     continue;
//                 visited.insert(n);
//                 q.push(n);
//             }
//         }
//         k--;
//     }
//
//     return res;
// }

// class Solution {
// private:
//     unordered_map<TreeNode *, int> map;
//
// public:
//     vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
//         vector<int> res;
//
//         find(root, target);
//         dfs(root, target, k, map[root], res);
//
//         return res;
//     }
//
//     int find(TreeNode *root, TreeNode *target) {
//
//         if (!root)
//             return -1;
//         if (root == target) {
//             map[root] = 0;
//             return 0;
//         }
//
//         int left = find(root->left, target);
//         if (left >= 0) {
//             map[root] = left + 1;
//             return left + 1;
//         }
//
//         int right = find(root->right, target);
//         if (right >= 0) {
//             map[root] = right + 1;
//             return right + 1;
//         }
//
//         return -1;
//     }
//
//     void dfs(TreeNode *root, TreeNode *target, int k, int length, vector<int> &res) {
//         if (!root)
//             return;
//         if (map.count(root))
//             length = map[root];
//         if (length == k)
//             res.push_back(root->val);
//         dfs(root->left, target, k, length + 1, res);
//         dfs(root->right, target, k, length + 1, res);
//     }
// };
//
// ll cookies(int k, vector<int> arr) {
//     ll res = 0;
//
//     priority_queue<ll> pq;
//
//     for (auto e: arr) {
//         if (e < k)
//             pq.push(e);
//     }
//
//     if (pq.empty())
//         return 0;
//
//     while (!pq.empty()) {
//         ll a, b;
//         a = pq.top();
//         pq.pop();
//
//         if (a >= k)
//             return res;
//
//         if (a < k && pq.size() < 1)
//             return -1;
//
//         if (pq.empty()) {
//             return ++res;
//         }
//
//         b = pq.top();
//         pq.pop();
//
//         if (a >= k || b >= k)
//             break;
//
//         ll nw = a + 2ll * b;
//         if (nw < k)
//             pq.push(nw);
//
//         res++;
//     }
//
//     return res == arr.size() ? -1 : res;
// }

// struct Node2 {
//     int val;
//     Node2 *left;
//     Node2 *right;
//
//     Node2() : val(0), left(nullptr), right(nullptr) {}
//
//     Node2(int _val) : val(_val), left(nullptr), right(nullptr) {}
//
//     Node2(int _val, Node2 *_left, Node2 *_right) : val(_val), left(_left), right(_right) {}
//
// };

// template<class T>
// class Node3 {
// private:
//     T val;
//     Node3 *left;
//     Node3 *right;
//
// public:
//     static string description;
//
//     Node3() {}
//
//     Node3(T _val) : val(_val), left(nullptr), right(nullptr) {}
//
//     Node3(Node3 &i) {
//         val = i.val;
//     }
//
// public:
//     // functions
//
//     Node3 *insert(T _val) {
//
//         if (_val < val) {
//             if (left)
//                 left->insert(_val);
//             else
//                 left = new Node3(_val);
//         } else {
//             if (right)
//                 right->insert(_val);
//             else
//                 right = new Node3(_val);
//         }
//
//         return this;
//     }
//
//     void printPreOrderTraversal() {
//
//         // print preOrders from preOrders vector after calculate it
//         // by preOrderCalculator function
//         Node3 *temp = this;
//         preOrderCalculator(temp);
//         for (auto e: preOrders)
//             cout << e << " ";
//         cout << endl;
//     }
//
// private:
//     vector<T> preOrders;
//
//     void preOrderCalculator(Node3 *root) {
//         if (root) {
//             preOrders.push_back(root->val);
//             preOrderCalculator(root->left);
//             preOrderCalculator(root->right);
//         }
//     }
// };
//
// void noPrefix(vector<string> words) {
//     set<string> prefix_set;
//     set<string> word_set;
//     for (auto w: words) {
//         string check = "";
//
//         if (prefix_set.count(w)) {
//             cout << "BAD SET" << endl << w;
//             return;
//         }
//
//         for (auto l: w) {
//             check += l;
//             prefix_set.insert(check);
//
//             if (word_set.count(check)) {
//                 cout << "BAD SET" << endl << w;
//                 return;
//             }
//
//         }
//         word_set.insert(w);
//     }
//
//     cout<<("GOOD SET");
// }

int findMedian(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    return arr[arr.size() / 2];
}

int flippingMatrix(vector<vector<int>> matrix)
{
    int n2 = matrix.size();
    // if the 2 x 2

    for (int i = 0; i < n2; i++)
    {
        int mx = 0;
        int j = i + 1;

        int mx1 = max(matrix[i][i], matrix[i][j + 1]);
        int mx2 = max(matrix[i + 1][i], matrix[i + 1][j + 1]);

        mx = max(mx1, mx2);
    }
}

int palindromeIndex(string s)
{
    int n = s.size();
    int i = 0, r = n - 1;

    while (i < r)
    {
        if (s[i] != s[r])
        {
            if (s[i + 1] == s[r] && s[i + 2] == s[r - 1])
                return i;
            else
                return r;
        }
        i++;
        r--;
    }

    return -1;
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

int getTotalX(vector<int> a, vector<int> b)
{
    // lcm for a
    int lcms = 1, gcds = 0;
    for (auto x : a)
    {
        lcms = lcm(lcms, x);
    }
    for (auto x : b)
    {
        gcds = gcd(gcds, x);
    }

    int multi = 0, res = 0;
    while (multi <= gcds)
    {
        multi += lcms;

        if (gcds % multi == 0)
            res++;
    }

    return res;
}

int anagram(string s)
{
    int n = s.size();
    if (n % 2 != 0)
        return -1;

    int mid = n / 2;
    string s1 = s.substr(0, mid);
    string s2 = s.substr(mid, mid);

    unordered_map<char, int> map;
    for (auto c : s1)
    {
        map[c]++;
    }

    int res = 0;
    for (auto c : s2)
    {
        if (map.count(c) && map[c] > 0)
        {
            map[c]--;
        }
        else
        {
            res++;
        }
    }

    return res;
}

//
// int mxSquare(vector<vector<int>> matrix, int n) {
//    if (n == 1) {
//        int mx = 0;
//        for (auto f: matrix) {
//            mx = max(f[0], f[1]);
//        }
//        return mx;
//    }
//
//
//}

int main()
{

    //    cout<<"Hello";
    //
    //    string s;
    //    cin >> s;
    //
    //    int n;
    //    cin >> n;
    //
    //    while (n--) {
    //        int x;
    //        cin >> x;
    //        if (!root) root = new Node3<int>(x);
    //        else {
    //
    //            root->insert(x);
    //        }
    //    }
    //
    //    root->printPreOrderTraversal();

    return 0;
}
