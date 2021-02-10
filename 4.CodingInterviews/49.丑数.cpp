//
// Created by Raven on 2021/2/10.
//
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iostream>

using namespace std;


class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int> uglies{1, 2, 3, 4, 5};
        if (n <= 5) return uglies[n - 1];
        int i2 = 2, i3 = 1, i5 = 1;
        while (uglies.size() !=n) {
            int v2 = 2 * uglies[i2];
            int v3 = 3 * uglies[i3];
            int v5 = 5 * uglies[i5];
            int min_value = min({v2, v3, v5});
            uglies.push_back(min_value);
            if (v2 == min_value) {
                i2++;
            }
            if (v3 == min_value) {
                i3++;
            }
            if (v5 == min_value) {
                i5++;
            }
        }
        return uglies.back();
    }
};


int main()
{
    Solution sol;
    {
        cout << sol.nthUglyNumber(7);
    }
    return 0;
}
