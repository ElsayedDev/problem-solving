#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void ReadDataWithSpeed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
}

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{

public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        head->next = deleteDuplicates(head->next);

        return head->val == head->next->val ? head->next : head;
    }
};

int main()
{
    ReadDataWithSpeed();

    // make ListNode of [1,2,4]
    ListNode ln1 = ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(5)))))));

    Solution solution = Solution();

    ListNode *sol = (solution.deleteDuplicates(&ln1));

    while (sol != nullptr)
    {
        cout << sol->val << endl;
        sol = sol->next;
    }

    return 0;
}
