#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  Solution(vector<int> &nums) : origin(nums), eg(std::random_device()()) {}

  /** Resets the array to its original configuration and return it. */
  vector<int> reset() { return origin; }

  /** Returns a random shuffling of the array. */
  vector<int> shuffle() {
    vector<int> aux = origin;
    const int len = aux.size();
    for (int i = 0; i < len; i++) {
      // generate a random idx that is between [i,end)
      std::uniform_int_distribution<int> distri(i, len - 1);
      int idx = distri(eg);
      swap(aux[idx], aux[i]);
    }
    return aux;
  }

  const vector<int> origin;
  std::default_random_engine eg;
};