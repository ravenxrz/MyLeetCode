//
// Created by raven on 5/14/21.
// leetcode 的base文件
//

#ifndef TEST_FOR_MYLEETCODE_LEETCODE_BASE_H
#define TEST_FOR_MYLEETCODE_LEETCODE_BASE_H

#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void createTree(TreeNode **node)
{
    int x;
    cin >> x;
    if (x == -1)
    {
        *node = nullptr;
        return;
    }
    *node = new TreeNode(x);
    createTree(&(*node)->left);
    createTree(&(*node)->right);
}

ListNode *createList()
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int x;
    while (cin >> x)
    {
        if (x == -1)
            break;
        if (head == nullptr)
        {
            head = new ListNode(x);
            tail = head;
        }
        else
        {
            ListNode *node = new ListNode(x);
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

#endif // TEST_FOR_MYLEETCODE_LEETCODE_BASE_H
