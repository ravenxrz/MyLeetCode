//
// Created by Raven on 2021/3/24.
//

class Solution {
    struct TrieNode {
        char cur;       // current char
        TrieNode *children[26];   // children node
        int id;         // use id to indicate whether this node is the end of a word or not
        // <0 means middle node.  >= 0 means a end char. default: -1
        TrieNode(char c) : cur(c), id(-1)
        {
            memset(children, 0, sizeof(children));
        }
    };
    
    TrieNode *root = new TrieNode('0');
    
    void insert(const string &word, int id)
    {
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            if (cur->children[c - 'a'] == NULL) {
                cur->children[c - 'a'] = new TrieNode(c);
            }
            cur = cur->children[c - 'a'];
        }
        cur->id = id;
    }
    
    void search(vector<vector<int>> &ans, string &word, int start_pos)
    {
        TrieNode *cur = root;
        for (int i = start_pos; i < word.size(); ++i) {
            char c = word[i];
            if (cur->children[c - 'a'] == NULL) {      // word doesn't exist in trie tree
                return;
            } else {
                cur = cur->children[c - 'a'];
                if (cur->id != -1) {        // find a pattern (small word) in trie tree
//                    assert(ans.size() >
//                           cur->id);       // to confirm that ans vector has target idx, so we have to initialize ans vector in main driver program
                    ans[cur->id].push_back(start_pos);
                }
            }
        }
    }

public:
    vector<vector<int>> multiSearch(string big, vector<string> &smalls)
    {
        if(smalls.empty()) return {};
        vector<vector<int>> ans;
        for (int i = 0; i < smalls.size(); ++i) {
            insert(smalls[i], i);
            ans.emplace_back(vector<int>());
        }
        
        // search in ans
        for (int i = 0; i < big.size(); ++i) {
            search(ans, big, i);
        }
        return ans;
    }
};
