#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseLeftWords(string s, int n)
    {
        // assert(s.length() >= n)
        reverse(s.begin(), s.begin() + n);
        reverse(s.begin() + n, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

int main()
{
    Solution sol;
    {
        cout << sol.reverseLeftWords("helloworld", 5) << '\n';
    }
    return 0;
}