
class Solution {
public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    // Use two tmp vectors to save the values of two trees respectively
    vector<int> tree1, tree2;
    traverse_save(root1, tree1);
    traverse_save(root2, tree2);
    // Use merge sort.
    vector<int> ans(tree1.size() + tree2.size(), 0);
    int i = 0;
    int j = 0;
    int idx = 0;
    while (i < tree1.size() && j < tree2.size()) {
      if (tree1[i] <= tree2[j]) {
        ans[idx++] = tree1[i++];
      } else {
        ans[idx++] = tree2[j++];
      }
    }
    // Insert remaining values of tree1 or tree2 into "ans"
    while (i < tree1.size()) {
      ans[idx++] = tree1[i++];
    }
    while (j < tree2.size()) {
      ans[idx++] = tree2[j++];
    }
    return ans;
  }

private:
  void traverse_save(TreeNode *node, vector<int> &vec) {
    if (node == nullptr)
      return;
    traverse_save(node->left, vec);
    vec.push_back(node->val);
    traverse_save(node->right, vec);
  }
};

int main(int argc, char **argv) { return 0; }
