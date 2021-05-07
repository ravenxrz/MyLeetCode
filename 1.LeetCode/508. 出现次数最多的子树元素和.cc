/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
private:
  unordered_map<int,int> umap;
  int max_value{0};
  unordered_set<int> ans_set;
public:
  vector<int> findFrequentTreeSum(TreeNode* root) {
    postOrderTraverse(root);
    // set to vec
    return vector<int>(ans_set.begin(),ans_set.end());
  }
  
  // Post order traverse, return the sum value of the tree rooted with |node|
  int postOrderTraverse(TreeNode *node){
    if(node ==  nullptr)  return 0;
    int s1 = postOrderTraverse(node->left);
    int s2 = postOrderTraverse(node->right);
    int s = s1 + s2 + node->val;
    umap[s]++;
    if(max_value == umap[s]){
      ans_set.insert(s);
    }else if(max_value < umap[s]){
      ans_set.clear();
      max_value = umap[s];
      ans_set.insert(s);
    }
    return s;
  }
};

int main()
{
  TreeNode *root = new TreeNode(5);
  root->left = new TreeNode(2);
  root->right = new TreeNode(-3);
  Solution sol;
  sol.postOrderTraverse(root);
  return 0;
}
