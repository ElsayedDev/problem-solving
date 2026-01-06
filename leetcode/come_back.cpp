#include "common.h"
#include "../tests/test_framework.h"

using namespace std;

class Solution
{
public:
    int reverseBits(int n)
    {
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            result <<= 1;
            result |= (n & 1);
            n >>= 1;
        }
        return result;
    }
};

class MyStack
{
private:
    queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int value = q.front();
        q.pop();
        return value;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

int main()
{
    MyStack stack = MyStack();

    // Test MyStack functionality
    stack.push(1);
    stack.push(2);
    stack.push(3);
    ASSERT_EQ(stack.top(), 3);
    ASSERT_EQ(stack.pop(), 3);
    ASSERT_EQ(stack.pop(), 2);
    ASSERT_EQ(stack.pop(), 1);
    ASSERT_TRUE(stack.empty());

    return 0;
}