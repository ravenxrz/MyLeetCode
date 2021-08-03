//
// Created by raven on 2021/8/2.
//

class Solution {
private:
    static bool compare(int x, int y){
        char buf1[21];
        char buf2[21];
        snprintf(buf1,sizeof(buf1),"%d%d",x,y);
        snprintf(buf2,sizeof(buf2),"%d%d",y,x);
        return strcmp(buf1,buf2) < 0;
    }
public:
    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(),nums.end(), compare);
        // 连接 nums 中的各个数字
        string ans;
        for(int val : nums){
            ans.append(to_string(val));
        }
        return ans;
    }
};
