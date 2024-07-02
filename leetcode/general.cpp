#include <bits/stdc++.h>
#include "common.h"

using namespace std;

#define ll long long int

void ReadDataWithSpeed() {
    cin.tie(nullptr)->sync_with_stdio(false);

#ifndef ONLINE_JUDGE

    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);

#endif
}

class SolutionDiameterOfBinaryTree {
public:
    int mx = 0;

    int diameterOfBinaryTree(TreeNode *root) {
        depth(root);
        return mx;
    }

    int depth(TreeNode *root) {
        if (!root)
            return 0;

        int leftLength = depth(root->left);
        int rightLength = depth(root->right);

        mx = max(mx, (leftLength + rightLength));

        return max(leftLength, rightLength) + 1;
    }
};

class SolutionRemoveNthFromEnd {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *first = dummy;
        ListNode *second = dummy;

        for (int i = 1; i <= n + 1; i++) {
            first = first->next;
        }

        while (first != nullptr) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;

        return dummy->next;
    }
};

class SolutionSwapPairs {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        while (dummy->next) {
            int temp = dummy->val;
            dummy->val = dummy->next->val;
            dummy->next->val = temp;

            dummy = dummy->next;
        }

        return dummy;
    }
};

class SolutionNextPermutation {
public:
    void nextPermutation(vector<int> &nums) {
    }
};

class SolutionSearchRange {
public:
    vector<int> searchRange(vector<int> &nums, int target) {

        vector<int> res = {-1, -1};

        if (nums.size() == 0) {
            return res;
        }

        res[0] = bSearch(nums, target, -1);

        res[1] = bSearch(nums, target, 1);

        return res;
    }

    int bSearch(vector<int> &nums, int target, int condition) {

        int first = 0, last = nums.size() - 1, flag = -1;

        while (first <= last) {
            int mid = (first + last) / 2;

            if (nums[mid] == target) {

                flag = mid;
                if (condition == 1) {
                    first = mid + 1;
                } else {
                    last = mid - 1;
                }

                continue;
            }

            if (nums[mid] < target) {
                first = mid + 1;
            } else {
                last = mid - 1;
            }
        }

        return flag;
    }
};

class SolutionCombinationSum {
    vector<vector<int>> res;
    vector<int> temp;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, 0);

        return res;
    }

    void backtrack(vector<int> &candidates, int target, int start) {
        if (target < 0) {
            return;
        }

        if (target == 0) {
            res.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            temp.pop_back();
        }
    }
};

class SolutionPermute {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

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
        vector<vector<int>> temp(n, vector<int>(n, 0));

        int sqr = n * n;

        for (int i = 0; i < sqr; ++i) {
            pair<int, int> index = getVectorIndex(i, n);
            pair<int, int> newIndex = {index.second, n - 1 - index.first};
            temp[newIndex.first][newIndex.second] = matrix[index.first][index.second];
        }

        matrix = temp;
    }

    /*
        int index = 1
        n = 3
        n x n > matrix

        1 => 3 > index * n = 3
        2 => 6 > index * n = 6
        3 => 9 > index * n = 9
        4 => 2 > index * n => 12 => 12 % (n*n + 1) = 2
        5 => 5 > index * n => 15 => 15 % (n*n + 1) = 5
        6 => 8 > index * n => 18 => 18 % (n*n + 1) = 8
        7 => 1 > index * n => 21 => 21 % (n*n + 1) = 1
        8 => 4 > index * n => 24 => 24 % (n*n + 1) = 4
        9 => 7 > index * n => 27 => 27 % (n*n + 1) = 7



     */
    pair<int, int> getVectorIndex(int index, int n) {

        int row = index / n;
        int col = index % n;

        return {row, col};
    }
};


class SolutionSpiralOrder {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int row = matrix.size();
        int col = matrix[0].size();

        int top = 0, bottom = row - 1, left = 0, right = col - 1;

        
    }
};

int main() {
    ReadDataWithSpeed();



    return 0;
}
