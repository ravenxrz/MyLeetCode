#include "leetcode_base.h"

class MapSum {
    /* trie node */
    struct Node {
        char c;
        bool is_word;
        int val;
        Node* children[26];
        Node(char _c, bool _is_word) : c(_c), is_word(_is_word) {
            memset(children, 0, sizeof(children));
        }
    };

    Node* root_{nullptr};

    void tree_insert(const string& key, int value) {
        assert(root_);
        Node* cur = root_;
        for (int i = 0; i < key.size(); i++) {
            char c = key[i];
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new Node(c, false);
            }
            cur = cur->children[c - 'a'];
        }
        cur->is_word = true;
        cur->val = value;
    }

    int tree_search(const string& prefix, const Node* node, bool cnt) {
        const Node* cur = node;
        if (!cnt) {
            /* find prefix node location */
            for (int i = 0; i < prefix.size(); i++) {
                char c = prefix[i];
                if (cur->children[c - 'a'] == nullptr)
                    return 0;
                cur = cur->children[c - 'a'];
            }
            return tree_search(prefix, cur, true);
        } else {
            int ans = 0;
            if (cur->is_word) {
                ans += cur->val;
            }
            for (int i = 0; i < 26; i++) {
                if (cur->children[i]) {
                    ans += tree_search(prefix, cur->children[i], true);
                }
            }
            return ans;
        }
    }

   public:
    /** Initialize your data structure here. */
    MapSum() : root_(new Node(-1, false)) {}

    void insert(string key, int val) { tree_insert(key, val); }

    int sum(string prefix) { return tree_search(prefix, root_, false); }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main() {
    MapSum mapSum;
    mapSum.insert("apple", 3);
    cout << mapSum.sum("ap") << endl;  // return 3 (apple = 3)
    mapSum.insert("app", 2);
    cout << mapSum.sum("ap") << endl;  // return 5 (apple + app = 3 + 2 = 5)
    return 0;
}