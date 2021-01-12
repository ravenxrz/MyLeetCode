/**
 * 从尾到头打印链表
 */
#include <stack>
#include <vector>
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
    vector<int> reversePrint(ListNode *head)
    {
//        if (head == nullptr) return {};
//
//        stack<int> stk;
//        vector<int> ans;
//        ListNode *p = head;
//        while (p != nullptr) {
//            stk.push(p->val);
//            p = p->next;
//        }
//
//        // convert stk to vector
//        while (!stk.empty()) {
//            ans.push_back(stk.top());
//            stk.pop();
//        }
//        return ans;
        vector<int> ans;
        reversePrint(head,ans);
        return ans;
    }
    
    void reversePrint(ListNode *p, vector<int> &ans)
    {
        if (p == nullptr) return;
        reversePrint(p->next,ans);
        ans.push_back(p->val);
    }
};

void print_vector(const vector<int> &vec)
{
    for (auto val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    Solution sol;
    // nullptr
    {
        print_vector(sol.reversePrint(nullptr));
    }
    
    // single node
    {
        ListNode *head = new ListNode(1);
        print_vector(sol.reversePrint(head));
//        delete head;
//        head = nullptr;
    }
    
    
    // multi node
    {
        ListNode *head = new ListNode(1);
        head->next = new ListNode(2);
        print_vector(sol.reversePrint(head));

//        delete head;
//        head = nullptr;
    }
    
    
    return 0;
}
