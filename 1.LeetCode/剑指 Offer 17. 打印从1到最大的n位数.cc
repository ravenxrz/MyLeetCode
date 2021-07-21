//
// Created by raven on 2021/7/21.
//

class Solution {
public:
    vector<int> printNumbers(int n)
    {
        assert(n < 10);
        // Generate the maximum number of which the sum digit number is n
        int limit = 0;
        while (n) {
            limit = limit * 10 + 9;
            n--;
        }
        // Generate all numbers
        vector<int> ans;
        ans.reserve(limit);
        for (int i = 1; i <= limit; i++) {
            ans.push_back(i);
        }
        return ans;
    }
};
