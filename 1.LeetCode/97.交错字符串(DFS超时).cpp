#include "leetcode_base.h"

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() + s2.length() != s3.length())
        {
            return false;
        }
        return CheckInterleave(s3, 0, s1, 0, s2, 0);
    }

private:
    bool CheckInterleave(const string &s3, int i3, const string &s1, int i1, const string &s2, int i2)
    {
       if (i3 == s3.size())
            return true;

        // Do check
        if (i1 < s1.size() && s3[i3] == s1[i1])
        {
            bool s2Check = false;
            if (i2 < s2.size() && s3[i3] == s2[i2])
            {
                s2Check = true;
            }
            return CheckInterleave(s3, i3 + 1, s1, i1 + 1, s2, i2) ||
                   (s2Check && CheckInterleave(s3, i3 + 1, s1, i1, s2, i2 + 1));
        }
        else if (i2 < s2.size() && s3[i3] == s2[i2])
        {
            return CheckInterleave(s3, i3 + 1, s1, i1, s2, i2 + 1);
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << sol.isInterleave("", "", "") << endl;
    cout << sol.isInterleave("abababababababababababababababababababababababababababababababababababababababababababababababababbb",
                             "babababababababababababababababababababababababababababababababababababababababababababababababaaaba",
                             "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababbb") << endl;
    return 0;
}