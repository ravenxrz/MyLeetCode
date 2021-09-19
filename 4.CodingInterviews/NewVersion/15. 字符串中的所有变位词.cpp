#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
		string s1 = p;
		string s2 = s;
        if (s1.size() > s2.size())
            return {};

        vector<int> ans;
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
            ans.push_back(left);
        }

        while (right < s2.size()) {
            window[s2[right] - 'a']--;
            window[s2[left] - 'a']++;
            right++;
            left++;
            if (checkAllZero(window, 26)) {
                ans.push_back(left);
            }
        }
        return ans;
    }

    bool checkAllZero(int* window, int size) {
        return all_of(window, window + size, [](auto val) { return val == 0; });
    }
};


int main()
{
	Solution sol;
	{
		for(auto val : sol.findAnagrams("cbaebabacd","abc")){
			cout << val << ' ';
		}
		cout << endl;
	}
	return 0;
}