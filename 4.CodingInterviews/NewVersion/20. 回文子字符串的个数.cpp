#include <bits/stdc++.h>
using namespace std;

class Solution {
    int cnt;

   public:
    int countSubstrings(string s) {
        cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            calc(s, i, i);
            if (i + 1 < s.size() && s[i] == s[i + 1]) {
                calc(s, i, i + 1);
            }
        }
		return cnt;
    }

   private:
    void calc(const string& s, int left, int right) {
        cnt++;
        if (left - 1 < 0 || right + 1 >= s.size() ||
            s[left - 1] != s[right + 1])
            return;
        calc(s, left - 1, right + 1);
    }
};

int main() {
	Solution sol;
	cout << sol.countSubstrings("aaa") << endl;
    return 0;
}