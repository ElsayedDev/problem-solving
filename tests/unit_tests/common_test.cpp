#include "../test_framework.h"
#include "../../leetcode/common.h"

// Test TreeNode functionality
TEST_CASE("TreeNode Creation", test_treenode_creation)
{
    TreeNode *node = new TreeNode(5);
    ASSERT_EQ(5, node->val);
    ASSERT_EQ(nullptr, node->left);
    ASSERT_EQ(nullptr, node->right);
    delete node;
}

TEST_CASE("TreeNode With Children", test_treenode_with_children)
{
    TreeNode *left = new TreeNode(3);
    TreeNode *right = new TreeNode(7);
    TreeNode *root = new TreeNode(5, left, right);

    ASSERT_EQ(5, root->val);
    ASSERT_EQ(3, root->left->val);
    ASSERT_EQ(7, root->right->val);

    delete left;
    delete right;
    delete root;
}

// Test ListNode functionality
TEST_CASE("ListNode Creation", test_listnode_creation)
{
    ListNode *node = new ListNode(42);
    ASSERT_EQ(42, node->val);
    ASSERT_EQ(nullptr, node->next);
    delete node;
}

TEST_CASE("ListNode Chain", test_listnode_chain)
{
    ListNode *third = new ListNode(3);
    ListNode *second = new ListNode(2, third);
    ListNode *first = new ListNode(1, second);

    ASSERT_EQ(1, first->val);
    ASSERT_EQ(2, first->next->val);
    ASSERT_EQ(3, first->next->next->val);
    ASSERT_EQ(nullptr, first->next->next->next);

    delete third;
    delete second;
    delete first;
}

// Test basic utilities
TEST_CASE("Long Long Definition", test_long_long_definition)
{
    ll large_number = 1000000000000LL;
    ASSERT_TRUE(large_number > 0);
    ASSERT_EQ(1000000000000LL, large_number);
}
