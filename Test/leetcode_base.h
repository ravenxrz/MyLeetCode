//
// Created by raven on 5/14/21.
// leetcode 的base文件
//

#ifndef TEST_FOR_MYLEETCODE_LEETCODE_BASE_H
#define TEST_FOR_MYLEETCODE_LEETCODE_BASE_H

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void createTree(TreeNode **node) {
  int x;
  cin >> x;
  if (x == -1) {
    *node = nullptr;
    return;
  }
  *node = new TreeNode(x);
  createTree(&(*node)->left);
  createTree(&(*node)->right);
}

#endif // TEST_FOR_MYLEETCODE_LEETCODE_BASE_H
