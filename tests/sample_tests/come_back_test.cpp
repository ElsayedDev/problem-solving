#include "../test_framework.h"
#include <iostream>
#include <vector>
#include <queue>

// Copy the relevant parts from come_back.cpp to avoid include issues
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
    std::queue<int> q;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
    }

    int pop()
    {
        int value = q.back();
        q.pop();
        return value;
    }

    int top()
    {
        return q.back();
    }

    bool empty()
    {
        return q.empty();
    }
};

// Test the reverseBits function
TEST_CASE("Reverse Bits - Simple Case", test_reverse_bits_simple)
{
    Solution solution;
    // Test with a simple pattern: 1010 (10 in decimal)
    // In 32-bit: 00000000000000000000000000001010
    // Reversed:  01010000000000000000000000000000 (1342177280 in decimal)
    int input = 10;
    int expected = 1342177280;
    int result = solution.reverseBits(input);
    ASSERT_EQ(expected, result);
}

TEST_CASE("Reverse Bits - Zero", test_reverse_bits_zero)
{
    Solution solution;
    int result = solution.reverseBits(0);
    ASSERT_EQ(0, result);
}

TEST_CASE("Reverse Bits - All Ones Lower", test_reverse_bits_all_ones_lower)
{
    Solution solution;
    // Test with 0xFF (255 in decimal, 8 lower bits set)
    // In 32-bit: 00000000000000000000000011111111
    // Reversed:  11111111000000000000000000000000 (-16777216 in decimal)
    int input = 255;
    int expected = -16777216; // This is the signed interpretation
    int result = solution.reverseBits(input);
    ASSERT_EQ(expected, result);
}

// Test MyStack class
TEST_CASE("MyStack - Push and Top", test_mystack_push_top)
{
    MyStack stack;
    stack.push(10);
    ASSERT_EQ(10, stack.top());

    stack.push(20);
    ASSERT_EQ(20, stack.top());

    stack.push(30);
    ASSERT_EQ(30, stack.top());
}

TEST_CASE("MyStack - Push and Pop", test_mystack_push_pop)
{
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    ASSERT_EQ(30, stack.pop());
    ASSERT_EQ(20, stack.pop());
    ASSERT_EQ(10, stack.pop());
}

TEST_CASE("MyStack - Empty Check", test_mystack_empty)
{
    MyStack stack;
    ASSERT_TRUE(stack.empty());

    stack.push(42);
    ASSERT_FALSE(stack.empty());

    stack.pop();
    ASSERT_TRUE(stack.empty());
}

TEST_CASE("MyStack - LIFO Behavior", test_mystack_lifo)
{
    MyStack stack;

    // Push multiple elements
    for (int i = 1; i <= 5; i++)
    {
        stack.push(i * 10);
    }

    // Pop them and verify LIFO order
    for (int i = 5; i >= 1; i--)
    {
        ASSERT_EQ(i * 10, stack.pop());
    }

    ASSERT_TRUE(stack.empty());
}
