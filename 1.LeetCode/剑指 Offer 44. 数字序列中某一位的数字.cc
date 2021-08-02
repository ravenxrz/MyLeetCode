//
// Created by raven on 2021/8/2.
//

class Solution {
public:
    int findNthDigit(int n)
    {
        long long num = static_cast<long long>(n) + 1;
        if (num <= 10) {
            return num - 1;
        }
        num -= 10;
        long long prev_n = num;
        int digit = 2;
        long long base = 90;
        int start = 10;
        while (num > 0) {
            prev_n = num;
            num -= (base * digit);
            base = base * 10;
            start = start * 10;
            digit++;
        }
        start = start / 10;
        digit--;
        num = prev_n;
        num--;
        int step_over_num = num / digit;
        int remain = num % digit;
        int target_num = start + step_over_num;
        return to_string(target_num)[remain] - '0';
    }
};
