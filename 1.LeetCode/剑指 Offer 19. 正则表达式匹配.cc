//
// Created by Raven on 2021/7/21.
//
class Solution {
public:
  bool isMatch(string s, string p) { return tryMatch(s, p, 0, 0); }

private:
  bool tryMatch(const string &s, const string &p, int si, int pi) {
    if (si == s.size() && pi == p.size())
      return true;
    else if (si == s.size() && pi != p.size()) {
      // Return true if the remaining of "s" is composed of "x*"
      for (; pi < p.size(); pi += 2) {
        if (pi + 1 >= p.size())
          return false;
        if (p[pi + 1] != '*')
          return false;
      }
      return true;
    } else if (si != s.size() && pi == p.size())
      return false;
    else {
      // si < s.size() && pi < p.size() -1
      if (pi + 1 < p.size() && p[pi + 1] == '*') {
        if (p[pi] == '.' || p[pi] == s[si]) {
          return tryMatch(s, p, si, pi + 2) || tryMatch(s, p, si + 1, pi + 2) ||
                 tryMatch(s, p, si + 1, pi);
        } else {
          return tryMatch(s, p, si, pi + 2);
        }
      } else {
        if (p[pi] == '.' || p[pi] == s[si]) {
          return tryMatch(s, p, si + 1, pi + 1);
        } else {
          return false;
        }
      }
    }
  }
};
