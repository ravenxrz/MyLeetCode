#include <bits/stdc++.h>
#include <functional>

using namespace std;


class Solution {
public:
    vector<int> shortestSeq(vector<int> &big, vector<int> &small)
    {
        if (big.size() < small.size()) return {};
        
        unordered_map<int, int> need, window;
        for (auto val : small) need[val]++;
        
        // window
        int left = 0, right = 0;
        int min_win_len = 0xffffff;
        int min_start = 0;
        int valid_num = 0;
        
        
        // init left
        while (left < big.size()) {
            if (need.count(big[left])) break;
            ++left;
        }
        right = left;
        
        // next: apply slide window algorithm to solve this problem
        while (right < big.size()) {
            int cur_value = big[right];
            right++;
            
            // window expand
            if (need.count(cur_value) != 0) {
                window[cur_value]++;
                if (window[cur_value] == need[cur_value])
                    valid_num++;
            }
            
            // window shrink: if we have reached the sub-array which contains all values of small
            // shrink util we have deleted one element in "need" and "left" stops at the second element
            while (valid_num == need.size()) {
                if (right - left < min_win_len) {
                    min_win_len = right - left;
                    min_start = left;
                }
                int left_value = big[left];
                left++;
                if (need.count(left_value) != 0) {
                    if (window[left_value] == need[left_value]) {
                        valid_num--;
                    }
                    window[left_value]--;
                }
            }
            while (left < right && need.count(big[left]) == 0) left++;
        }
        // 如果最小窗口大小未更新过
        if (min_win_len == 0xffffff) return {};
        return {min_start, min_start + min_win_len - 1};
    }
};

int main()
{
    /**
[842, 336, 777, 112, 789, 801, 922, 874, 634, 121, 390, 614, 179, 565, 740, 672, 624, 130, 555, 714, 9, 950, 887, 375, 312, 862, 304, 121, 360, 579, 937, 148, 614, 885, 836, 842, 505, 187, 210, 536, 763, 880, 652, 64, 272, 675, 33, 341, 101, 673, 995, 485, 16, 434, 540, 284, 567, 821, 994, 174, 634, 597, 919, 547, 340, 2, 512, 433, 323, 895, 965, 225, 702, 387, 632, 898, 297, 351, 936, 431, 468, 694, 287, 671, 190, 496, 80, 110, 491, 365, 504, 681, 672, 825, 277, 138, 778, 851, 732, 176]
[950, 885, 702, 101, 312, 652, 555, 936, 842, 33, 634, 851, 174, 210, 287, 672, 994, 614, 732, 919, 504, 778, 340, 694, 880, 110, 777, 836, 365, 375, 536, 547, 887, 272, 995, 121, 225, 112, 740, 567, 898, 390, 579, 505, 351, 937, 825, 323, 874, 138, 512, 671, 297, 179, 277, 304]
     */
    Solution sol;
    vector<int> big{842, 336, 777, 112, 789, 801, 922, 874, 634, 121, 390, 614, 179, 565, 740, 672, 624, 130, 555, 714,
                    9, 950, 887, 375, 312, 862, 304, 121, 360, 579, 937, 148, 614, 885, 836, 842, 505, 187, 210, 536,
                    763, 880, 652, 64, 272, 675, 33, 341, 101, 673, 995, 485, 16, 434, 540, 284, 567, 821, 994, 174,
                    634, 597, 919, 547, 340, 2, 512, 433, 323, 895, 965, 225, 702, 387, 632, 898, 297, 351, 936, 431,
                    468, 694, 287, 671, 190, 496, 80, 110, 491, 365, 504, 681, 672, 825, 277, 138, 778, 851, 732, 176};
    vector<int> small{950, 885, 702, 101, 312, 652, 555, 936, 842, 33, 634, 851, 174, 210, 287, 672, 994, 614, 732, 919,
                      504, 778, 340, 694, 880, 110, 777, 836, 365, 375, 536, 547, 887, 272, 995, 121, 225, 112, 740,
                      567, 898, 390, 579, 505, 351, 937, 825, 323, 874, 138, 512, 671, 297, 179, 277, 304};
    sol.shortestSeq(big, small);
    return 0;
}
