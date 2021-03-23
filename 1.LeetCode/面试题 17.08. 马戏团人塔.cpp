//
// Created by Raven on 2021/3/23.
//


#include <bits/stdc++.h>

using namespace std;

class Solution {
    struct hw {
        int h;
        int w;
        
        hw(int h, int w) : h(h), w(w) {}
    };

public:
    int bestSeqAtIndex(vector<int> &height, vector<int> &weight)
    {
        if (height.empty()) return 0;
        
        vector<hw> hw_arr;
        hw_arr.reserve(height.size());
        for (int i = 0; i < height.size(); ++i) {
            hw_arr.emplace_back(height[i], weight[i]);
        }
        sort(hw_arr.begin(), hw_arr.end(), [](const hw &lhr, const hw &rhs) {
            if (lhr.h == rhs.h) return lhr.w > rhs.w;
            return lhr.h < rhs.h;
        });
        
        // LCS
        // non binary search
//        int max_value = 0;
//        vector<int> dp(height.size(), 1);
//        for (int i = 1; i < hw_arr.size(); ++i) {
//            for (int j = i - 1; j >= 0; --j) {
//                if (hw_arr[i].w > hw_arr[j].w) {
//                    dp[i] = max(dp[i], dp[j] + 1);
//                    max_value = max(dp[i], max_value);
//                }
//            }
//        }
        vector<int> nums = {hw_arr[0].w};
        size_t max_len = 1;
        for (int i = 1; i < hw_arr.size(); ++i) {
            if (hw_arr[i].w > nums.back()) {
                nums.push_back(hw_arr[i].w);
            } else {
                *lower_bound(nums.begin(), nums.end(), hw_arr[i].w) = hw_arr[i].w;
            }
            max_len = max(max_len, nums.size());
        }
        return max_len;
    }
};

class Solution {
    struct hw {
        int h;
        int w;
        
        hw(int h, int w) : h(h), w(w) {}
    };
    
    unordered_map<string, int> memo;
    
    string key(int n1, int n2)
    {
        return to_string(n1) + "," + to_string(n2);
    }
    
    int dfs(int h, int w, vector<hw> &hw_arr, int next_idx)
    {
        if (memo.count(key(h, w))) return memo[key(h, w)];
        
        // 这里可以优化为二分查找
        while (next_idx < hw_arr.size() && h == hw_arr[next_idx].h) ++next_idx;
        
        int max_height = 1;
        for (int i = next_idx; i < hw_arr.size(); ++i) {
            if (w < hw_arr[i].w) {
                max_height = max(max_height, 1 + dfs(hw_arr[i].h, hw_arr[i].w, hw_arr, i + 1));
            }
        }
        memo[key(h, w)] = max_height;
        return max_height;
    }


public:
    int bestSeqAtIndex(vector<int> &height, vector<int> &weight)
    {
        vector<hw> hw_arr;
        hw_arr.reserve(height.size());
        for (int i = 0; i < height.size(); ++i) {
            hw_arr.emplace_back(height[i], weight[i]);
        }
        sort(hw_arr.begin(), hw_arr.end(), [](const hw &lhr, const hw &rhs) {
            if (lhr.h == rhs.h) return lhr.w < rhs.w;
            return lhr.h < rhs.h;
        });
        
        int max_height = 0;
        for (int i = 0; i < height.size(); ++i) {
            max_height = max(max_height, dfs(hw_arr[i].h, hw_arr[i].w, hw_arr, i + 1));
        }
        return max_height;
    }
};

