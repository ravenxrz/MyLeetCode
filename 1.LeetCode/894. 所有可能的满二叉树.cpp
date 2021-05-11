class Solution {
private:
  unordered_map<int, vector<TreeNode *>> umap;

public:
  vector<TreeNode *> allPossibleFBT(int n) {
    generate(n);
    assert(umap.count(n));
    return umap[n];
  }

private:
  // Generate full binary Trees whose nodes number is n
  vector<TreeNode *> generate(int n) {
    if (n == 0)
      return {};
    if (umap.count(n))
      return umap.at(n);
    if (n == 1) {
      umap[1] = {new TreeNode(0)};
      return umap[1];
    }
    
    vector<TreeNode *> subTrees;
    for (int i = 1; i <= n - 2; i++) {
      vector<TreeNode *> leftTrees = generate(i);
      vector<TreeNode *> rightTrees = generate(n - 1 - i);
      for (TreeNode *left : leftTrees) {
        for (TreeNode *right : rightTrees) {
          auto *root = new TreeNode(0);
          root->left = left;
          root->right = right;
          subTrees.push_back(root);
        }
      }
    }
    umap[n] = std::move(subTrees); // Move into map
    return umap[n];
  }
};
