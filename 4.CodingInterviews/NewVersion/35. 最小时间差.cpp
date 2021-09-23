
#include "leetcode_base.h"

class Solution {
    static int str2int(const string& time) {
        int hour = (time[0] - '0') * 10 + (time[1] - '0');
        int minutes = (time[3] - '0') * 10 + (time[4] - '0');
        return hour * 60 + minutes;
    }

   public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times(timePoints.size(), 0);
        transform(timePoints.begin(), timePoints.end(), times.begin(),
                  [](const string& timeStr) { return str2int(timeStr); });
        sort(times.begin(), times.end());
        int min_diff = INT32_MAX;
        for (int i = 1; i < times.size(); i++) {
            min_diff = min(min_diff, times[i] - times[i - 1]);
        }
        // Diff the first one and last one
        min_diff = min(min_diff, times[0] + 1440 - times.back());

        return min_diff;
    }
};

int main() {
    Solution sol;
    vector<string> time = {"23:59", "00:00"};
    cout << sol.findMinDifference(time) << endl;

    return 0;
}