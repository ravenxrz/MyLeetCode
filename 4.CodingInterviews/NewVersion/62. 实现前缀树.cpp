#include "leetcode_base.h"

/**
 * @brief 没有实现释放nodes的算法
 * 
 */
class Trie {
   private:
    struct Node {
        char c;
        bool is_word;
        vector<Node*> children;
        Node(char _c, bool _is_word)
            : c(_c), is_word(_is_word), children(26, nullptr) {}
    };
    Node* root;

   public:
    /** Initialize your data structure here. */
    Trie() : root(new Node(0, false)) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new Node(c, false);
            }
            cur = cur->children[c - 'a'];
        }
        cur->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (cur->children[c - 'a'] == nullptr)
                return false;
            cur = cur->children[c - 'a'];
        }
		return cur->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for (int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if (cur->children[c - 'a'] == nullptr)
                return false;
            cur = cur->children[c - 'a'];
        }
		return cur;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
	Trie trie;
	trie.insert("apple");
	cout << trie.search("apple") << endl;
	cout << trie.startsWith("app") << endl;
    return 0;
}