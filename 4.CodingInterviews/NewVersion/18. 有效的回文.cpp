#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool isPalindrome(string s) {
        preProcess(&s);
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }
        return true;
    }

   private:
    void preProcess(string* ps) {
        string& str = *ps;
        transform(str.begin(), str.end(), str.begin(),
                  [](char& c) { return c = tolower(c); });
        int i = 0;
        while (i < str.size()) {
            if (isdigit(str[i]) || isalpha(str[i])) {
                i++;
            } else {
                str.erase(str.begin() + i);
            }
        }
    }
};

int main() {
    Solution sol;
    cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;

    return 0;
}