class Solution {
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        vector<int> inorder = postorder;
        sort(inorder.begin(), inorder.end());
        return verify(postorder, inorder);
    }
    
    bool verify(const vector<int> &post_order, const vector<int> &in_order)
    {
        if (in_order.empty() && post_order.empty()) return true;
        if (in_order.size() != post_order.size()) return false;
        
        int pivot = post_order.back();
        int pos = 0;
        for (; pos < in_order.size(); pos++) {
            if (in_order[pos] == pivot) break;
        }
        if (pos == in_order.size()) return false;
        
        // Find the first position of which array element is in the "right hand side" of in_order relative to pivot
        int end = 0;
        const vector<int> &lhs = vector<int>(in_order.begin(), in_order.begin() + pos);
        const vector<int> &rhs = vector<int>(in_order.begin() + pos + 1, in_order.end());
        while (end < post_order.size() - 1) {
            if (find(lhs.begin(), lhs.end(), post_order[end]) == lhs.end()) {
                break;
            }
            end++;
        }
        return verify(vector<int>(post_order.begin(), post_order.begin() + end), lhs) &&
               verify(vector<int>(post_order.begin() + end, post_order.end() - 1), rhs);
    }
};

