#include "leetcode_base.h"

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
	unordered_map<Node *, Node *> umap; // map between original node and cloned node
	unordered_set<Node *> visit;

public:
	Node *cloneGraph(Node *node)
	{
		if (node == nullptr)
			return nullptr;

		umap.clear();
		visit.clear();
		// Generate node
		visit.insert(node);
		dfs1(node);

		// Generate connections among nodes
		visit.clear();
		visit.insert(node);
		dfs2(node);
		return umap[node];
	}

private:
	void dfs1(Node *node)
	{
		if (node == nullptr)
			return;
		umap.insert(pair<Node *, Node *>(node, new Node(node->val)));
		for (Node *neigh : node->neighbors)
		{
			if (visit.insert(neigh).second)
			{
				dfs1(neigh);
			}
		}
	}

	void dfs2(Node *node)
	{
		if (node == nullptr)
			return;
		for (Node *neigh : node->neighbors)
		{
			umap[node]->neighbors.push_back(umap[neigh]);
			if (visit.insert(neigh).second)
			{
				dfs2(neigh);
			}
		}
	}
};