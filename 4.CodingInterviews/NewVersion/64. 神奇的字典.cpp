#include "leetcode_base.h"

class MagicDictionary {
    class Trie {
        friend class MagicDictionary;

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
        bool search(Node* node, string word, int idx, bool changed) {
            if (!node)
                return false;

            /* searching reaches the end of word */
            Node* cur = node;
            if (idx == word.size()) {
                return node->is_word && changed;
            }

            /* keep searching in the children nodes */
            char c = word[idx];
            bool ret = false;
            /* c is in the children of node */
            if (node->children[c - 'a'])
                ret = search(node->children[c - 'a'], word, idx + 1, changed);
            if (ret)
                return true;

			/* if word never changed, now change it one time */
            if (!changed) {
                for (int i = 0; i < node->children.size(); i++) {
                    if (node->children[i] && i != c - 'a') {
                        ret = search(node->children[i], word, idx + 1, true);
                        if (ret)
                            return true;
                    }
                }
            }
            return false;
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

   public:
    /** Initialize your data structure here. */
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (const auto& word : dictionary) {
            trie_.insert(word);
        }
    }

    bool search(string searchWord) {
        return trie_.search(trie_.root, searchWord, 0, false);
    }

   private:
    Trie trie_;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */

int main() {
    MagicDictionary magicDictionary;
    magicDictionary.buildDict({"hello", "leetcode"});
    cout << magicDictionary.search("hello") << endl;  // 返回 False
    cout << magicDictionary.search("hhllo") << endl;  // 将第二个 'h' 替换为 'e' 可以匹配 "hello" ，所以返回 True
    cout << magicDictionary.search("hell") << endl;       // 返回 False
    cout << magicDictionary.search("leetcoded") << endl;  // 返回 False
    return 0;
}