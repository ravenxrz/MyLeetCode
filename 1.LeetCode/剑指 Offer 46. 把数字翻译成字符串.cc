//
// Created by raven on 2021/8/3.
//

class Solution {
public:
    int translateNum(int num)
    {
        return translate(to_string(num), 0);
    }

private:
    int translate(const string &str, int start)
    {
        if (start >= str.size()) return 1;
        int cnt = 0;
        if (str[start] == '0') {
            // 如果首字母是0， 则只能按照0翻译
            cnt += translate(str, start + 1);
        } else {
            // 首字母不是0
            cnt += translate(str, start + 1);
            if (start + 1 < str.size() &&
                (str[start] == '1' || (str[start] == '2' && str[start + 1] < '6'))) {
                cnt += translate(str, start + 2);
            }
        }
        return cnt;
    }
};
