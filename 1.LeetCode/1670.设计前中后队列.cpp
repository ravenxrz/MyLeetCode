#include <cassert>
#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=1670 lang=cpp
 *
 * [1670] 设计前中后队列
 */

// @lc code=start
class FrontMiddleBackQueue {
public:
  FrontMiddleBackQueue()
      : dummy_head_(0), tail_(&dummy_head_), mid_(&dummy_head_), len_(0) {}

  void pushFront(int val) {
    len_++;
    ListNode *node = new ListNode(val);
    // Insert
    insertAfter(&dummy_head_, node);
    // Update mid and tail pointer
    update();
  }

  void pushMiddle(int val) {
    len_++;
    ListNode *node = new ListNode(val);
    if (empty()) {
      insertAfter(&dummy_head_, node);
    } else {
      if ((len_ - 1) & 1) {
        // Find the previous pointer of mid
        ListNode *prev = &dummy_head_;
        for (; prev->next != mid_; prev = prev->next)
          ;
        node->next = prev->next;
        prev->next = node;
      } else {
        insertAfter(mid_, node);
      }
    }
    update();
  }

  void pushBack(int val) {
    len_++;
    ListNode *node = new ListNode(val);
    if (empty()) {
      insertAfter(&dummy_head_, node);
    } else {
      insertAfter(tail_, node);
    }
    update();
  }

  int popFront() {
    if (empty())
      return -1;
    len_--;
    ListNode *node = dummy_head_.next;
    int ret = node->val;
    dummy_head_.next = node->next;
    delete node;
    node = nullptr;

    update();
    return ret;
  }

  int popMiddle() {
    if (empty())
      return -1;
    len_--;
    int ret = mid_->val;
    // Find previous pointer of mid
    ListNode *prev = &dummy_head_;
    for (; prev->next != mid_; prev = prev->next)
      ;
    // Delete
    prev->next = prev->next->next;
    delete mid_;

    update();
    return ret;
  }

  int popBack() {
    if (empty())
      return -1;
    len_--;
    int ret = tail_->val;
    // Find previous pointer of tail
    ListNode *prev = &dummy_head_;
    for (; prev->next != tail_; prev = prev->next)
      ;
    // Delete
    prev->next = nullptr;
    delete tail_;
    tail_ = nullptr;

    update();
    return ret;
  }

private:
  struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
  };

  bool empty() { return tail_ == &dummy_head_; }

  void insertAfter(ListNode *node, ListNode *in) {
    assert(node && in);
    in->next = node->next;
    node->next = in;
  }

  // Update the position of "mid" and "tail"
  // 每次都update，其实非常低效
  void update() {
    // Update tail
    tail_ = &dummy_head_;
    while (tail_->next) {
      tail_ = tail_->next;
    }

    // Update mid
    mid_ = &dummy_head_;
    for (int i = 0; i < (len_ + 1) / 2; i++) {
      mid_ = mid_->next;
    }
  }

  ListNode dummy_head_;
  ListNode *head_;
  ListNode *tail_;
  ListNode *mid_;
  int len_;
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
// @lc code=end

int main() {
  {
    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    q.pushMiddle(4);
    cout << q.popMiddle();
    cout << q.popMiddle();
    cout << q.popBack();
    cout << q.popFront();
    cout << endl;
  }

  {
    FrontMiddleBackQueue q;
    q.pushMiddle(1);
    q.pushMiddle(2);
    q.pushMiddle(3);
    q.pushMiddle(4);
    q.pushMiddle(5);
    cout << q.popBack();
    cout << q.popBack();
    cout << q.popBack();
    cout << q.popBack();
    cout << q.popBack();
    cout << endl;
  }

  {
    FrontMiddleBackQueue q;
    q.pushBack(1);
    q.pushBack(2);
    q.pushBack(3);
    q.pushBack(4);
    q.pushBack(5);
    cout << q.popFront();
    cout << q.popFront();
    cout << q.popFront();
    cout << q.popFront();
    cout << q.popFront();
    cout << endl;
  }
  return 0;
}