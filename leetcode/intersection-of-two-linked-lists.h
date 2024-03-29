#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *ptrA = headA, *ptrB = headB;
        while (ptrA != ptrB)
        {
            ptrA = ptrA ? ptrA->next : headB;
            ptrB = ptrB ? ptrB->next : headA;
        }
        return ptrA;
    }
};