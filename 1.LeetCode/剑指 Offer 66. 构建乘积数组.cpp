#include "leetcode_base.h"


class Solution {
   public:
    vector<int> constructArr(vector<int>& a) {
        if (a.empty())
            return {};
        vector<int> b(a.size(), 1);
        // Product from left to right
        int product = 1;
        for (size_t i = 0; i < a.size(); i++) {
            b[i] = product;
            product *= a[i];
        }
        // Product from right to left
        product = 1;
        for (int i = a.size() - 1; i >= 0; i--) {
            b[i] *= product;
            product *= a[i];
        }
        return b;
    }
};