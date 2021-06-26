class NestedInteger {
public:
  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
  struct Item {
    vector<NestedInteger>::const_iterator cur;
    vector<NestedInteger>::const_iterator end;
    Item(const vector<NestedInteger>::const_iterator &begin,
         const vector<NestedInteger>::const_iterator &anEnd)
        : cur(begin), end(anEnd) {}
  };

  stack<Item> stk;

public:
  NestedIterator(vector<NestedInteger> &nestedList) {
    stk.emplace(nestedList.begin(), nestedList.end());
  }

  int next() {
    assert(hasNext());
    int val = stk.top().cur->getInteger();
    stk.top().cur++;
    return val;
  }

  bool hasNext() {
    while (!stk.empty()) {
      Item &item = stk.top();
      if (item.cur == item.end) {
        stk.pop();
        continue;
      }
      if (item.cur->isInteger()) {
        return true;
      }
      const vector<NestedInteger> &list = item.cur->getList();
      item.cur++;
      stk.emplace(list.begin(), list.end());
    }
    return false;
  }
};
