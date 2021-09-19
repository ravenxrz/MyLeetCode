//
// Created by raven on 5/14/21.
// leetcode 的base文件
//

#ifndef TEST_FOR_MYLEETCODE_LEETCODE_BASE_H
#define TEST_FOR_MYLEETCODE_LEETCODE_BASE_H

#ifdef __MACH__

#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#else

#include <bits/stdc++.h>

#endif

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void createTree(TreeNode** node) {
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

ListNode* createList() {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int x;
    while (cin >> x) {
        if (x == -1)
            break;
        if (head == nullptr) {
            head = new ListNode(x);
            tail = head;
        } else {
            ListNode* node = new ListNode(x);
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
}

/* 生成[start,end]之间的n个随机数 */
template <typename T>
std::vector<T> generateRandomNumbers(size_t n, int start = 0, int end = 100) {
    assert(n > 0);
    std::vector<T> nums;
    srand((unsigned)time(NULL));
    for (size_t i = 0; i < n; i++) {
        double rnum =
            (double)rand() / RAND_MAX * (end - start) + start;  // [0,1]
        nums.push_back((T)rnum);
    }
    return nums;
}

template <typename T>
void printNums(const std::vector<T>& nums) {
    for (auto& val : nums) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

#endif  // TEST_FOR_MYLEETCODE_LEETCODE_BASE_H
