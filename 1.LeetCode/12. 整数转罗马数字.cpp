#include "leetcode_base.h"

class Solution
{

    const char roman_digit[4][2] = {
        {'I', 'V'}, // one
        {'X', 'L'}, // two
        {'C', 'D'}, // three
        {'M', '-'}  // four
    };

public:
    string intToRoman(int num)
    {
        string ans;
        char buf[5];
        snprintf(buf, sizeof(buf), "%d", num);
        string num_str = buf;

        for (int i = 0; i < num_str.size(); i++)
        {
            ans.append(convertOneDigit(num_str[i], num_str.size() - i - 1));
        }
        return ans;
    }

    string convertOneDigit(char cnum, int digit_order)
    {
        if (cnum == '0')
        {
            return "";
        }
        else if (cnum < '4') // [1,3]
        {
            return string(cnum - '0', roman_digit[digit_order][0]);
        }
        else if (cnum == '4')
        {
            return string(1, roman_digit[digit_order][0]).append(1, roman_digit[digit_order][1]);
        }
        else if (cnum < '9') // [5,8]
        {
            return string(1, roman_digit[digit_order][1]) + string(cnum - '5', roman_digit[digit_order][0]);
        }
        else if (cnum == '9')
        {
            return string(1, roman_digit[digit_order][0]) + string(1, roman_digit[digit_order + 1][0]);
        }

        // Prevent compiler complaint
        return "";
    }
};

int main()
{
    Solution sol;
    for (int i = 0; i < 4000; i++)
    {
        cout << " num: " << i << " --> " << sol.intToRoman(i) << endl;
    }
    return 0;
}