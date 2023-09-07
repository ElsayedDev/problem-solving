#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode newHead(0);
        ListNode *out = &newHead;
        int r = 0;

        while (r || l1 || l2)
        {
            r += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            out->next = new ListNode(r % 10);
            out = out->next;

            r /= 10;

            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return newHead.next;
    }
};