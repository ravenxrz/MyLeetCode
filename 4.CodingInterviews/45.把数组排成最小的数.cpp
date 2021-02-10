#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
public:
    string minNumber(vector<int> &nums)
    {
        if (nums.empty()) return "";
        
        char buf[100];
        if (nums.size() == 1) {
            sprintf(buf, "%d", nums[0]);
            return buf;
        }
        // 排序
        sort(nums.begin(), nums.end(), Solution::compare);
        // 拼接
        string result;
        for (int val : nums) {
            sprintf(buf, "%d", val);
            result.append(buf);
        }
        return result;
    }

private:
    static bool compare(int x, int y)
    {
        // convert to string
        static char buf[100];
        static string x_str;
        static string y_str;
        x_str.clear();
        y_str.clear();
        sprintf(buf, "%d%d", x,y);
        x_str = buf;
        sprintf(buf, "%d%d", y,x);
        y_str = buf;
        return x_str < y_str;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{10, 2};
        cout << sol.minNumber(nums) << '\n';
    }
    {
        vector<int> nums{3, 30, 34, 5, 9};
        cout << sol.minNumber(nums) << '\n';
    }
    {
        vector<int> nums{12,121} ;
        cout << sol.minNumber(nums) << '\n';
    }
    {
        vector<int> nums{121,12} ;
        cout << sol.minNumber(nums) << '\n';
    }
    {
        vector<int> nums{9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519};
        cout << sol.minNumber(nums) << '\n';
    }
    return 0;
}
