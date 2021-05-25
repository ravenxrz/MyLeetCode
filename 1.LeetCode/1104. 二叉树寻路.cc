//
// Created by raven on 5/25/21.
//
class Solution {
  static const int n = 21;
  int level_start[n]; // The start node id of one level of the tree
  int level_num[n];   // The node number of one level of the tree

public:
  vector<int> pathInZigZagTree(int label) {
    // Initialization of "level_start" and "level_num"
    level_start[1] = 1;
    level_num[1] = 1;
    for (int i = 2; i < n; i++) {
      level_start[i] = 2 * level_start[i - 1];
      level_num[i] = 2 * level_start[i] - 1;
    }
    vector<int> ans;
    
    // Find the height where "label" located
    int h = 1;
    int tmp = 2;
    while (true) {
      if (tmp >= (label + 1)) {
        break;
      }
      h++;
      tmp <<= 1;
    }
    // Calculate the answer
    for (int i = h; i > 0; i--) {
      ans.push_back(label);
      if (i & 1) { // odd level
        label = label / 2;
        label = num_revert(i-1, label);
      } else {
        label = num_revert(i, label);
        label = label / 2;
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }

private:
  int num_revert(int level, int id) {
    return level_start[level] + (level_num[level] - id);
  }
};
