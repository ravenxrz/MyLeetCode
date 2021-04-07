#include <vector>
#include <unordered_map>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        // platform --> routines vector
        unordered_map<int, vector<int>> platform2routes_map;
        vector<bool> routes_visit(routes.size(), false);
        // build platform2routes_map
        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                if (platform2routes_map.count(routes[i][j]) == 0) {
                    platform2routes_map[routes[i][j]] = vector<int>{i};
                } else {
                    platform2routes_map[routes[i][j]].push_back(i);
                }
            }
        }
        
        if (platform2routes_map.count(source) == 0 ||
            platform2routes_map.count(target) == 0)
            return -1;
        if (source == target) return 0;
        
        
        // core
        // find source platform
        auto tmp_routes = platform2routes_map[source];
        queue<int> route_qe;
        for (auto rt : tmp_routes) {
            route_qe.push(rt);
        }
        
        // sort
        for (int i = 0; i < routes.size(); i++) {
            sort(routes[i].begin(), routes[i].end());
        }
        
        int cur_level = route_qe.size();
        int next_level = 0;
        int dist = 1;
        while (!route_qe.empty()) {
            auto rt = route_qe.front();
            route_qe.pop();
            routes_visit[rt] = true;
            cur_level--;
            if (binary_search(routes[rt].begin(), routes[rt].end(), target)) {
                return dist;
            }
            // find related platforms
            auto platforms = routes[rt];
            for (auto pt : platforms) {
                // find related routes
                auto pt2rt = platform2routes_map[pt];
                for (auto next_rt : pt2rt) {
                    if (routes_visit[next_rt]) continue;
                    // add to queue
                    route_qe.push(next_rt);
                    next_level++;
                }
            }
            if (cur_level == 0) {
                cur_level = next_level;
                next_level = 0;
                dist++;
            }
        }
        return -1;
    }
};


int main()
{
    Solution sol;
    /**
     *
     * [[7,12],[4,5,15],[6],[15,19],[9,12,13]]
        15
        12
     *
     *
     *
     *
     */
    vector<vector<int>> routes{
            {7,  12},
            {4,  5,  15},
            {6},
            {15, 19},
            {9,  12, 13}
    };
    cout << sol.numBusesToDestination(routes, 15, 12) << endl;
    return 0;
}
