#include "leetcode_base.h"

class MyCalendar {
   public:
    MyCalendar() {}

    bool book(int start, int end) {
        Node node(start, end);
        auto iter = range_tree.lower_bound(node);
        if (iter != range_tree.end()) {
            if (isOverlap(*iter, node))
                return false;
            if (iter != range_tree.begin()) {
                iter--;
                if (isOverlap(*iter, node))
                    return false;
            }
        } else {
            /* range tree is empty or no node's left value is large-equal than
             * start */
            if (!range_tree.empty()) {
                if (isOverlap(*range_tree.rbegin(), node)) {
                    return false;
                }
            }
        }
		range_tree.insert(node);
		return true;
    }

   private:
    struct Node {
        int left;
        int right;
        bool operator<(const Node& rhs) const { return left < rhs.left; }
        Node(int l, int r) : left(l), right(r) {}
    };
    set<Node> range_tree;

    bool isOverlap(const Node& lhs, const Node& rhs) {
		return !(rhs.right <= lhs.left) && !(lhs.right <= rhs.left);
	}
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main() {
	MyCalendar  calendar;
	cout << calendar.book(10,20) << endl;
	cout << calendar.book(15,20) << endl;
    return 0;
}
