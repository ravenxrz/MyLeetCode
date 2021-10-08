#include "leetcode_base.h"

class Solution {
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
        bool search(string word, string* prefix) {
            Node* cur = root;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                if (cur->children[c - 'a'] == nullptr)
                    return false;
                cur = cur->children[c - 'a'];
                prefix->push_back(c);
				if(cur->is_word) return true;
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

   public:
    string replaceWords(vector<string>& dictionary, string sentence) {
		/* init trie tree */
        Trie trie;
        for (const auto& word : dictionary) {
            trie.insert(word);
        }

        vector<string> words = splitWordsBySpace(sentence);

        string ans;
        string prefix;
        for (const auto& word : words) {
            prefix.clear();
            if (trie.search(word, &prefix)) {
                ans.append(prefix).append(" ");
            } else {
                ans.append(word).append(" ");
            }
        }
        ans.pop_back();
        return ans;
    }

private:
    vector<string> splitWordsBySpace(const string& sentence) {
        vector<string> ans;
		string tmp = sentence;
		int i = 0;
		while(i < sentence.size()){
			int start = i;
			while(i < sentence.size() && !isspace(sentence[i])) i++;
			ans.push_back(sentence.substr(start, i - start));
			i++;
		}
        return ans;
    }
};

int main()
{
	Solution sol;
	vector<string> dict = {"cat","bat","rat"};
	string words = "the cattle was rattled by the battery";
	cout << sol.replaceWords(dict, words) << endl;
	return 0;
}