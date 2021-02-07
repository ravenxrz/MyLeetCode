#include <string>
#include <queue>
#include <iostream>
#include <vector>

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
 * ;
 */
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "[";
        queue<TreeNode *> qe;
        qe.push(root);
        char buf[100];
        
        while (!qe.empty()) {
            TreeNode *cur = qe.front();
            qe.pop();
            if (cur == NULL) {
                ans.append(",null");
                continue;
            } else {
                sprintf(buf, "%d", cur->val);
                ans.append(string(",") + buf);
            }
            qe.push(cur->left);
            qe.push(cur->right);
        }
        
        ans.append("]");
        ans = ans.erase(1, 1);
        return ans;
    }
    
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<TreeNode *> nodes;
        const string null_str = "null";
        const string end_str = "]";
        string num_str;
        int start = 0;
        size_t node_idx = 0;
        size_t leaf_count = 0;
        
        while (start < data.size() && (data[start] == ' ' || data[start] == '[')) start++;
        while ((num_str = nextNumberString(data, start)) != end_str) {
            // 生成节点
            TreeNode *tmpNode = NULL;
            if (num_str != null_str) {
                int value = strtol(num_str.c_str(), NULL, 10);
                tmpNode = new TreeNode(value);
            }
            if (nodes.empty()) {  // root node
                if (tmpNode == NULL) return NULL;
                nodes.push_back(tmpNode);
            } else {          // 其他节点
                if (leaf_count == 0) {
                    nodes[node_idx]->left = tmpNode;
                    leaf_count = 1;
                } else {
                    nodes[node_idx]->right = tmpNode;
                    leaf_count = 0;
                    node_idx++;
                }
                if (tmpNode == NULL) continue;
                nodes.push_back(tmpNode);
            }
        }
        return nodes[0];
    }

private:
    // 从start起（包含start)的下一个字符。其中]为结束符
    string nextNumberString(const string &data, int &start)
    {
        if (start >= data.size() || data[start] == ']') return "]";
        int tmp = start;
        int end = tmp;
        while (end < data.size() && data[end] != ',' && data[end] != ']') {
            end++;
        }
        start = end + 1;
        return data.substr(tmp, end - tmp);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));



int main()
{
    
    Codec codec;
    
    {
        string data = "[null]";
        TreeNode *node = codec.deserialize(data);
    }
    
    {
        string data = "[1,null,3,4,5]";
        TreeNode *node = codec.deserialize(data);
        cout << codec.serialize(node);
    }

//
//    {
//        TreeNode *root = NULL;
//        cout << codec.serialize(root) << endl;
//    }
//
//    {
//        TreeNode *root = new TreeNode(1);
//        cout << codec.serialize(root) << endl;
//    }
//
//    {
//        TreeNode *root = new TreeNode(1);
//        root->left = new TreeNode(2);
//        cout << codec.serialize(root) << endl;
//    }
//
//    {
//        TreeNode *root = new TreeNode(1);
//        root->left = new TreeNode(2);
//        root->right = new TreeNode(3);
//        cout << codec.serialize(root) << endl;
//    }
    
    return 0;
}
