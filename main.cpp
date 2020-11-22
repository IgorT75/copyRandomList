#include <unordered_map>

class Node {
public:
		int val;
		Node* next;
		Node* random;

		Node(int _val, Node* _next = nullptr, Node* _random = nullptr) : 
			val(_val), next(_next), random(_random) { }
};

// https://leetcode.com/problems/copy-list-with-random-pointer
class Solution {
	std::unordered_map<Node*, Node*> m;
public:
	Solution() = default;
	Node* copyRandomList(Node* head) {
		if (head == nullptr) return nullptr;
		if (m.find(head) != m.end()) return m[head];

		Node* p = new Node(head->val);
		m[head] = p;

		p->next = copyRandomList(head->next);
		p->random = copyRandomList(head->random);

		return p;
	}
};

int main() {
	Solution s;

	Node* n = new Node(7, new Node(13, new Node(11, new Node(10, new Node(1)))));
	n->random = nullptr;
	n->next->random = n;
	n->next->next->random = n->next->next->next->next;
	n->next->next->next->random = n->next->next;
	n->next->next->next->next->random = n;
	auto p = s.copyRandomList(n);

	return 0;
}