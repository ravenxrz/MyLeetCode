//
// Created by Raven on 2021/2/13.
//
#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1) return 0;
        int profit = 0;
        int start = 0;
        while (start + 1 < prices.size()) {
            if (prices[start] >= prices[start + 1]) {
                start++;
            } else {
                break;
            }
        }
        if (start == prices.size() - 1) return profit;
        // set start and end
        int end = start + 1;
        profit = prices[end] - prices[start];
        int pending = -1;
        
        for (int cur = end + 1; cur < prices.size(); cur++) {
            if (prices[cur] > prices[end]) {
                // 当前值大于 最大值
                end = cur;
                profit = prices[end] - prices[start];
            } else if (prices[cur] > prices[start]) {
                // 介于 prices[start] -- prices[end] 之间
                continue;
            } else {
                // 小于 prices[start]
                if (pending == -1) {
                    // 未设置pending
                    pending = cur;
                } else {
                    // 设置了pending
                    if (prices[cur] < prices[pending]) {
                        // 比pending还小
                        pending = cur;
                    } else {
                        // 介于 prices[pending] -- prices[start] 之间
                        if (prices[cur] - prices[pending] >= profit) {
                            // update start and
                            start = pending;
                            end = cur;
                            pending = -1;
                        }
                        // 其余case 忽略
                    }
                }
            }
        }
    }
};
