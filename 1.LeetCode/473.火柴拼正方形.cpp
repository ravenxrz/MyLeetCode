/*
 * @lc app=leetcode.cn id=473 lang=cpp
 *
 * [473] 火柴拼正方形
 */
// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        // 排除明显不满足的情况
        if(nums.size() < 4)
            return false;

        int sum = 0;
        for (int i = 0; i < nums.size();i++){
            sum += nums[i];
        }
        if(sum % 4 != 0){   // 不能被4整除
            return false;
        }

        // 优化：对nums从大到小放置
        sort(nums.rbegin(),nums.rend());
        return back_track(nums, sum / 4, 0);
    }

    /**
     * @brief 回溯
     *
     * @param nums 边长集合
     * @param target 一条边的长度
     * @param offset 第几根火柴
     * @return true
     * @return false
     */
    bool back_track(const vector<int> &nums, int target, int offset){
        static vector<int> bucket(4, target);

        if(offset == nums.size()){ // 放完所有火柴，return true
            return true;
        }

        // 回溯算法主程序
        for (int bucket_idx = 0; bucket_idx < 4;bucket_idx++){
            if(nums[offset] <= bucket[bucket_idx]){
                // put
                // 加入剪枝，条件为：bucket不满，但是后续火柴无法放入
                bucket[bucket_idx] -= nums[offset];
                if(cut(nums,bucket,offset+1)){
                    bucket[bucket_idx] += nums[offset];
                    continue;
                }

                if(back_track(nums, target, offset + 1)){
                    return true;
                }
                // 取回
                bucket[bucket_idx] += nums[offset];
            }
            else
            {
                // 无法放入，进入下一个bucket
            }
        }
        return false;
    }

    // cut条件：存在bucket不满，但是后续火柴无法放入
    bool cut(const vector<int> &nums, const vector<int> &bucket, int start){
        for(int i = 0;i<bucket.size();i++){
            bool flag = true;
            // bucket已经为空
            if(bucket[i] == 0) continue;
            // 一旦不为空，就肯定还存在能够放置的火柴
            for(int j = start;j<nums.size();j++){
                if(bucket[i] >= nums[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                // 如果不满足，则剪
                return true;
            }

        }
        return false;
    }
};
// @lc code=end
