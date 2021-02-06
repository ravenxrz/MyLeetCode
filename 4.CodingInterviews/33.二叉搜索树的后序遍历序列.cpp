class Solution {
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        return verify(postorder, 0, postorder.size() - 1);
    }

private:
    bool verify(const vector<int> &postorder, int start, int end)
    {
        if (start >= end) return true;
        int root = postorder[end];
        // left subtree check
        int i = start;
        for(;i<end;i++){
            if(postorder[i] > root)  break;
        }
        int j = i;
        // right subtree check
        for(;j<end;j++){
            if(postorder[j] < root) return false;
        }
        // recursive check
        return verify(postorder,start,i-1) &&
               verify(postorder,i,end-1);
    }
};
