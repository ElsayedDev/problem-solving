#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{

public:
    bool hasCycle(ListNode *head)
    {
        ListNode *second = head;
        ListNode *first = head;

        while (first != nullptr && first->next != nullptr)
        {
            first = head->next->next;
            second = head->next;

            if (first == second)
                return true;
        }

        return false;
    }
};