#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int farthest_idx = 0;
        int base_idx = 0;
        int delta = 0;
        
        const int size = gas.size();
        int step = 0;
        for (int i = 0; i < size; i++) {
            if (gas[i] < cost[i]) continue;
            int rem = gas[i] - cost[i];
            int try_idx = (i + 1) % size;
            step = 0;
            while (step != size) {
                step++;
                if (rem + gas[try_idx] < cost[try_idx]) break;
                rem += (gas[try_idx] - cost[try_idx]);
                try_idx = (try_idx + 1) % size;
            }
            if (step == size) return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(gas, cost) << '\n';
    return 0;
}


int main()
{
    Solution sol;
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    cout << sol.canCompleteCircuit(gas, cost) << '\n';
    return 0;
}
