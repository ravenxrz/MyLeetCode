#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    typedef unsigned long long ull;
public:
    int maxProduct(TreeNode *root)
    {
        ans = 0;
        postorder_sum(root);
        ull case1 = 0;
        ull case2 = 0;
        const ull sum = hash_map[root];
        for (auto kv : hash_map) {
            if (kv.first) {
                ull base = sum - hash_map[kv.first];
                if(kv.first->left)
                    case1 = (hash_map[kv.first->left] * (base + hash_map[kv.first] - hash_map[kv.first->left]));
                if(kv.first->right)
                    case2 = (hash_map[kv.first->right] * (base + hash_map[kv.first] - hash_map[kv.first->right]));
            }
            ans = max({ans, case1, case2});
            case1 = 0;
            case2 = 0;
        }
        return ans % mod;
    }

private:
    ull postorder_sum(TreeNode *node)
    {
        if (node == nullptr) return 0;
        ull left_sum = postorder_sum(node->left);
        ull right_sum = postorder_sum(node->right);
        ull total = left_sum + right_sum + node->val;
        hash_map[node] = total;
        return total;
    }

private:
    unordered_map<TreeNode *, ull> hash_map;
    ull ans;
    static constexpr ull mod = 1e9 + 7;
};


int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(4);
    TreeNode *base4 = root->right->right;
    base4->left = new TreeNode(5);
    base4->right = new TreeNode(6);
    Solution sol;
    cout << sol.maxProduct(root) << '\n';
    return 0;
}
