//
// Created by raven on 2021/4/13.
//

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == -1) {
            if (dividend == INT_MIN) return INT_MAX;
            return -dividend;
        }
        if (divisor == 1) return dividend;
        bool positive = ((dividend ^ divisor) >= 0);
        return positive ? divideCore(std::abs(dividend), std::abs(divisor)) :
               -divideCore(std::abs(dividend), std::abs(divisor));
    }
    
    int divideCore(long long dividend, long long divisor)
    {
        if (dividend < divisor) {
            return 0;
        }
        int base = 0;
        while (dividend >= (divisor << base)) {
            ++base;
        }
        return (1 << (base - 1)) + divideCore(dividend - (divisor << (base - 1)), divisor);
    }
};

