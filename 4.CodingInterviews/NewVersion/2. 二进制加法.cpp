#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    string addBinary(string a, string b) {
        if (a == "0")
            return b;
        if (b == "0")
            return a;
        string ans(a.size() + b.size(), '0');
        int carray = 0;
        int ai = a.size() - 1;
        int bi = b.size() - 1;
        int ansi = 0;

        while (ai >= 0 && bi >= 0) {
            int val = carray + a[ai] + b[bi] - 2 * '0';
            ans[ansi++] = val % 2 + '0';
            carray = val / 2;
            ai--;
            bi--;
        }
        while (ai >= 0) {
            int val = carray + a[ai] - '0';
            ans[ansi++] = val % 2 + '0';
            carray = val / 2;
            ai--;
        }
        while (bi >= 0) {
            int val = carray + b[bi] - '0';
            ans[ansi++] = val % 2 + '0';
            carray = val / 2;
            bi--;
        }
        if (carray == 1) {
            ans[ansi++] = '1';
        }
        ans.resize(ansi);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.addBinary("1010", "1011") << endl;
    return 0;
}