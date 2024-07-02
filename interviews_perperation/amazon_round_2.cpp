
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

// [1]
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


class SolutionNumberOfSteps {
public:
    int numberOfSteps(int num) {
        int res = 0;
        vector<int> bits = digitalToBits(num);

        for (auto e: bits) {
            if (e == 1)
                res += 2;
            else
                res++;
        }

        return res - 1;
    }

    vector<int> digitalToBits(int n) {
        vector<int> res;
        int r;
        while (n != 0) {
            r = n % 2;
            res.push_back(r);
            n /= 2;
        }
        if (res == 0) return 0;
        return res;
    }
};

int main() {
    ReadDataWithSpeed();

    vector<int> v = {
            1, 1, 2
    };

//    auto res = SolutionIsAnagram().isAnagram("ahmed", "amhed");

    vector<string> baned = {"hit"};
    cout << SolutionMostCommonWord().mostCommonWord(
            "Bob hit a ball, the hit BALL flew far after it was hit.", baned);


    return 0;
}
