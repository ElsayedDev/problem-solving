#include <bits/stdc++.h>
#include "common.h"
using namespace std;

class MinStack
{
public:
    MinStack()
    {
    }

    void push(int val)
    {
        if (head == nullptr)
        {
            head = new Node();
            head->val = val;
            head->min = val;
            head->next = nullptr;
        }
        else
        {
            Node *newNode = new Node();
            newNode->val = val;
            newNode->min = val < head->min ? val : head->min;
            newNode->next = head;
            head = newNode;
        };
    }

    void pop()
    {
        head = head->next;
    }

    int top()
    {
        return head->val;
    }

    int getMin()
    {
        return head->min;
    }

private:
    struct Node
    {
        int val;
        int min;
        Node *next;
    };

    Node *head;
};
