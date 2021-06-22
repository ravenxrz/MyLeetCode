#include "leetcode_base.h"

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        if (root == nullptr)
            return {};

        vector<vector<int>> ans(1, vector<int>());
        queue<Node *> qe;
        qe.push(root);
        int curLevelNum = 1;
        int nextLevelNum = 0;

        while (!qe.empty())
        {
            Node *curNode = qe.front();
            qe.pop();
            // Do insert op
            curLevelNum--;
            ans.back().push_back(curNode->val);
            nextLevelNum += curNode->children.size();
            for (Node *node : curNode->children)
            {
                qe.push(node);
            }
            // Has this level been traversed?
            if (curLevelNum == 0)
            {
                curLevelNum = nextLevelNum;
                nextLevelNum = 0;
                ans.push_back(vector<int>());
            }
        }
        // Pop the last redundant vector
        ans.pop_back();
        return ans;
    }
};
// @lc code=end

int main()
{
    return 0;
}