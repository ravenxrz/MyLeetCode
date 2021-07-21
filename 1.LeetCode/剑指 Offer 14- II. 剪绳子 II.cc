//
// Created by raven on 2021/7/21.
//

class Solution {
public:
    int cuttingRope(int n)
    {
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        long ret = 1;
        while(n > 4){
            ret = (ret * 3) % 1000000007;
            n-=3;
        }
        return (ret * n) % 1000000007;
    }
};
