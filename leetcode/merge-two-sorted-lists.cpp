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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // if list1 happen to be NULL
        // we will simply return list2.
        if (list1 == NULL)
        {
            return list2;
        }

        // if list2 happen to be NULL
        // we will simply return list1.
        if (list2 == NULL)
        {
            return list1;
        }

        // if value pointend by list1 pointer is less than equal to value pointed by list2 pointer
        // we wall call recursively list1 -> next and whole list2 list.
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        // we will call recursive list1 whole list and list2 -> next
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
int main()
{
    ReadDataWithSpeed();

    Solution solution = Solution();

    // make ListNode of [1,2,4]
    ListNode ln1 = ListNode(1);
    ListNode ln2 = ListNode();

    ListNode *sol = (solution.mergeTwoLists(&ln1, &ln2));

    while (sol != nullptr)
    {
        cout << sol->val << endl;
        sol = sol->next;
    }

    return 0;
}
