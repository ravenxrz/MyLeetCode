//
// Created by raven on 2021/7/21.
//

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int num = 0;
        while (n) {
            num++;
            n = (n & (n - 1));
        }
        return num;
    }
};

int main()
{
    return 0;
}