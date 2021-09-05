//
// Created by Raven on 2021/8/28.
//

#include <bits/stdc++.h>
using namespace std;

struct Item {
  int num;
  int price;
  bool operator<(const struct Item &rhs) const { return price < rhs.price; }
};

int main() {
  int a, b, c, d, e, f, g;
  cin >> a >> b >> c >> d >> e >> f >> g;
  long long value = 0;

  vector<Item> items = {{a, e}, {b, f}, {c, g}};
  sort(items.begin(), items.end());
  while (!items.empty() && d) {
    const auto &item = items.back();
    value += min(d, item.num) * item.price;
    d -= min(d, item.num);
    items.pop_back();
  }

  cout << value;
  return 0;
}
