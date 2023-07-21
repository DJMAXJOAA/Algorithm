#include <iostream>
#include <queue>
#include <vector>
using namespace std;

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

class Solution {
public:
	queue<Node*> que;
	vector<bool> visit; // 100ĭ
	Node* start;
	Node* save;
public:
	Node* cloneGraph(Node* node)
	{
		visit.resize(101);

		if (node == nullptr)
			return nullptr;

		start = new Node;
		start->val = node->val;
		for (int i = 0; i < node->neighbors.size(); i++)
		{
			Node* temp = new Node;
			temp->val = node->neighbors[i]->val;
			start->neighbors.push_back(temp);
		}
		save = start;

		que.push(node);
		visit[node->val] = true;
		while (que.size() != 0)
		{
			for (auto itr = save->neighbors.begin(); itr != save->neighbors.end(); ++itr)
			{
				auto& value = *itr;

				if (visit[value->val] == true)
					continue;

				que.push(value);
				visit[value->val] = true;
			}
			que.pop();
			if (que.size() != 0)
			{
				save->val = que.front()->val;
				for (int i = 0; i < que.front()->neighbors.size(); i++)
				{
					Node* temp = new Node;
					temp->val = que.front()->neighbors[i]->val;
					save->neighbors.push_back(temp);
				}
			}
		}

		return start;
	}
};