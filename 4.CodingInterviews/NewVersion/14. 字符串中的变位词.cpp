#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        int window[26];
        memset(window, 0, sizeof(window));
        int left = 0;
        int right = 0;
        while (right < s1.size()) {
            window[s1[right] - 'a']++;
            window[s2[right] - 'a']--;
            right++;
        }
        if (checkAllZero(window, 26)) {
            return true;
        }

        while (right < s2.size()) {
            window[s2[right] - 'a']--;
            window[s2[left] - 'a']++;
            right++;
            left++;
            if (checkAllZero(window, 26))
                return true;
        }
        return false;
    }

    bool checkAllZero(int* window, int size) {
        return all_of(window, window + size, [](auto val) { return val == 0; });
        // for (int i = 0; i < size; i++) {
        //     if (window[i])
        //         return false;
        // }
        // return true;
    }
};

int main() {
    Solution sol;
    {
        cout << sol.checkInclusion("dinitrophenylhydrazine",
                                   "dimethylhydrazine")
             << endl;
    }
    return 0;
}