#include "leetcode_base.h"

class Solution {
    struct Node {
        char c;
        bool is_word;
        vector<Node*> children;
        Node(char _c, bool _is_word)
            : c(_c), is_word(_is_word), children(26, nullptr) {}
    };

	/*
    // aux variable
    Node* root_;
    unordered_set<string> word_set;

    void buildTree(const string& word) {
        assert(!word.empty() && root_);
        Node* cur = root_;
        string tmp_word;
        string cut_word;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (!cur->children[c - 'a']) {
                cur->children[c - 'a'] = new Node(c, false);
            }
            cur = cur->children[c - 'a'];
            tmp_word.push_back(c);
            if (cur->is_word) {
                cut_word = tmp_word;
            }
        }
        cur->is_word = true;
        if (!cut_word.empty()) {
            word_set.erase(cut_word);
        }
        word_set.insert(word);
    }
	*/

	Node *root_;
	int ans_;

	void buildTree(const string& word){
		Node *cur = root_;
		bool in_prefix = true;
		for(int i = 0; i < word.size(); i++){
			char c = word[i];
			if(cur->children[c - 'a'] == nullptr){
				in_prefix = false;
				cur->children[c - 'a'] = new Node(c, false);
			}
			cur = cur->children[c - 'a'];
		}
		cur->is_word = true;
		if(!in_prefix){
			ans_ += word.size()+1;
		}
	}


   public:
    int minimumLengthEncoding(vector<string>& words) {
        ans_ = 0;
        root_ = new Node(-1, false);
        sort(words.begin(), words.end(),
             [](const string& lhs, const string& rhs) {
                 return lhs.length() > rhs.length();
             });
        for_each(words.begin(), words.end(),
                 [](string& word) { reverse(word.begin(), word.end()); });
        for (const string& word : words) {
            buildTree(word);
        }
        return ans_;
    }
};

int main(int argc, const char** argv) {
    Solution sol;
    {
        vector<string> words = {"time", "me", "bell"};
        cout << sol.minimumLengthEncoding(words) << endl;
    }
    {
        vector<string> words = {"t"};
        cout << sol.minimumLengthEncoding(words) << endl;
    }
    {
        vector<string> words = {"time", "atime", "btime"};
        cout << sol.minimumLengthEncoding(words) << endl;
    }
    return 0;
}