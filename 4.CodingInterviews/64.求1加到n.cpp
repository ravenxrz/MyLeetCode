//
// Created by Raven on 2021/2/13.
//

class Solution {
public:
    int sumNums(int n)
    {
        int sum = 0;
        bool flag = n > 0 && (sum = sumNums(n - 1) + n);
        return sum;
    }
};
