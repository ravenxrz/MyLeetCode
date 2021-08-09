#include "leetcode_base.h"

class Solution {
   public:
    int strToInt(string str) {
        size_t cursor = 0;
        bool is_nega = false;
        long long cur_val = 0;

        // Skip leading spaces
        for (; cursor < str.size() && isspace(str[cursor]); cursor++)
            ;
        if (cursor == str.size())
            return 0;
        if (str[cursor] == '+') {
            is_nega = false;
            cursor++;
        } else if (str[cursor] == '-') {
            is_nega = true;
            cursor++;
        }

        // Parse number as many as possible
        for (; cursor < str.size() && isdigit(str[cursor]); cursor++) {
            cur_val = cur_val * 10 + (str[cursor] - '0');
            if (is_nega && -cur_val <= INT32_MIN)
                return INT32_MIN;
            else if (!is_nega && cur_val >= INT32_MAX)
                return INT32_MAX;
        }
        return is_nega ? -cur_val : cur_val;
    }
};

int main()
{
	return 0;
}