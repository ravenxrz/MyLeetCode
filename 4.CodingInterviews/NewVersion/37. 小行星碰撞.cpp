#include "leetcode_base.h"

class Solution {
   public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0)
                stk.push(asteroids[i]);
            else {
                while (!stk.empty() && -asteroids[i] > stk.top()) {
                    stk.pop();
                }
                if (stk.empty()) {
                    ans.push_back(asteroids[i]);
                } else {
                    if (stk.top() == -asteroids[i]) {
                        stk.pop();
                    }
                }
            }
        }
        // append ans
        int start = ans.size();
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        reverse(ans.begin() + start, ans.end());
        return ans;
    }
};

/*  暴力破解 */
// class Solution {
//    public:
//     vector<int> asteroidCollision(vector<int>& asteroids) {
//         bool exploit = true;
//         while (exploit) {
//             int idx = 0;
//             exploit = false;
//             while (idx + 1 < asteroids.size()) {
//                 if (asteroids[idx] > 0 && asteroids[idx + 1] < 0) {
//                     exploit = true;
//                     if (asteroids[idx] > -asteroids[idx + 1]) {
//                         asteroids.erase(asteroids.begin() + idx + 1);
//                     } else if (asteroids[idx] < -asteroids[idx + 1]) {
//                         asteroids.erase(asteroids.begin() + idx);
//                     } else {
//                         asteroids.erase(asteroids.begin() + idx,
//                                         asteroids.begin() + idx + 2);
//                     }
//                 } else {
//                     idx++;
//                 }
//             }
//         }
//         return asteroids;
//     }
// };

int main() {
    Solution sol;
    {
        vector<int> as = {5, 10, -5};
        for (auto val : sol.asteroidCollision(as)) {
            cout << val << ' ';
        }
        cout << endl;
    }
    {
        vector<int> as = {8, -8};
        for (auto val : sol.asteroidCollision(as)) {
            cout << val << ' ';
        }
        cout << endl;
    }
    {
        vector<int> as = {10, 2, -5};
        for (auto val : sol.asteroidCollision(as)) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}