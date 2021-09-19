#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validPalindrome(string s) { return check(s, 1, 0, s.size() - 1); }

   private:
    bool check(const string& s, int cut_count, int left, int right) {
        while (left < right) {
            if (s[left] == s[right]) {
				left++;
				right--;
            } else {
                if (cut_count == 0)
                    return false;
                return check(s, cut_count - 1, left + 1, right) ||
                       check(s, cut_count - 1, left, right - 1);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.validPalindrome("aba") << endl;
    cout << sol.validPalindrome("abac") << endl;
    cout << sol.validPalindrome("abc") << endl;
    return 0;
}