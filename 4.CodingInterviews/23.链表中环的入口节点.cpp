#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head)
    {
        // empty check
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != slow && fast != NULL) {
            // fast move two steps
            fast = fast->next;
            if (fast == NULL) return NULL;
            fast = fast->next;
            slow = slow->next;
        }
        // no cycle
        if (fast == NULL) return NULL;
        // reset slow ptr
        slow = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main()
{
    return 0;
}