/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */

// @lc code=start
class Solution {
public:
    /**
     * 采用镜像法计算格雷编码
     * @param n
     * @return
     */
    vector<int> grayCode(int n) {
        if(n == 0)
            return {0};
        
        vector<int> code(pow(2,n),0);
        for(int i = 1;i<=n;i++){
            // total delta
            int td = pow(2,i-1);
            for(int delta = 0; delta < td; delta++){
                int pos = td + delta;
                int mirror_pos = td-delta-1;
                code[pos] = code[mirror_pos] + td;
            }
        }
        return code;
    }
};
// @lc code=end

