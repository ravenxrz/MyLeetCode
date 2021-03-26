//
// Created by Raven on 2021/3/26.
//
/**
 * 前缀和
 */
class Solution {
    int start_idx = -1;
    int max_len = 0;
public:
    vector<string> findLongestSubarray(vector<string> &array)
    {
        unordered_map<int, int> hash_map;
        int sum = 0;
        for (int i = 0; i < array.size(); ++i) {
            sum += (isdigit(array[i][0]) ? 1 : -1);
            if (sum == 0) {
                if (max_len < i + 1) {
                    max_len = i + 1;
                    start_idx = 0;
                }
            }
            if (hash_map.count(sum)) {
                if (max_len < i - hash_map[sum]) {
                    max_len = i - hash_map[sum];
                    start_idx = hash_map[sum] + 1;
                }
            } else {
                hash_map[sum] = i;
            }
        }
        
        if (max_len == 0) return {};
        return vector<string>(array.begin() + start_idx, array.begin() + start_idx + max_len);
    }
};


/**
 * O(n^2) 的解法，会超时
 */
class Solution {
    int start_idx = -1;
    int max_len = 0;
public:
    vector<string> findLongestSubarray(vector<string> &array)
    {
        vector<int> record;
        calc(array, 0, record);
        if (max_len == 0) return {};
        return vector<string>(array.begin() + start_idx, array.begin() + start_idx + max_len);
    }
    
    void calc(vector<string> &array, int idx, vector<int> &record)
    {
        if (idx >= array.size()) return;
        int delta = isdigit(array[idx][0]) ? 1 : -1;
        for (int i = 0; i < record.size(); ++i) {
            record[i] += delta;
            if (record[i] == 0) {
                if (idx - i + 1 > max_len) {
                    max_len = idx - i + 1;
                    start_idx = i;
                }
            }
        }
        record.push_back(delta);
        calc(array, idx + 1, record);
    }
};
