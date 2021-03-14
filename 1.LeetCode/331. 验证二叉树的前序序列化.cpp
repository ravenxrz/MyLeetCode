/**
 * 解法1
 */
class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        int idx = 0;
        bool ret = doCheck(preorder, idx);
        return ret && idx == preorder.size();
    }

private:
    bool doCheck(const string &preorder, int &idx)
    {
        if (idx >= preorder.size()) {
            return true;
        }
        
        if (preorder[idx] == '#') {
            moveToNextIdx(preorder, idx);
            return true;
        }
        
        moveToNextIdx(preorder, idx);
        // left tree
        doCheck(preorder, idx);
        if (idx >= preorder.size()) return false;
        // right tree
        doCheck(preorder, idx);
        return true;
    }
    
    void moveToNextIdx(const string &preorder, int &idx)
    {
        while (idx < preorder.size() && preorder[idx] != ',') idx++;
        if (idx != preorder.size()) idx++;
    }
};

/**
 * 解法2：使用stack
 */
class Solution {
public:
    bool isValidSerialization(string preorder)
    {
        if (preorder.empty()) return true;
        if(preorder[0] == '#'){
            return preorder.size() == 1;
        }
        // prepare
        stack<int> stk;
        int idx = 0;
        stk.push(2);
        moveToNextIdx(preorder, idx);
        
        while (idx < preorder.size()) {
            if (stk.empty()) return false;
            stk.top()--;
            if (stk.top() == 0) stk.pop();
            if (preorder[idx] != '#') {
                stk.push(2);
            }
            moveToNextIdx(preorder, idx);
        }
        return stk.empty();
    }

private:
    // 调整idx到下一个组
    void moveToNextIdx(const string &preorder, int &idx)
    {
        while (idx < preorder.size() && preorder[idx] != ',') idx++;
        if (idx != preorder.size()) {
            ++idx;
        }
    }
};

