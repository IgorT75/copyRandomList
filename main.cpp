#include <unordered_map>

class Node {
public:
		int val;
		Node* next;
		Node* random;

		Node(int _val, Node* _next = nullptr, Node* _random = nullptr) : 
			val(_val), next(_next), random(_random) { }
};

// https://leetcode.com/problems/clone-binary-tree-with-random-pointer/
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode *random;
	TreeNode(int x = 0, TreeNode *left = nullptr, TreeNode *right = nullptr, TreeNode *random = nullptr) :
		val(x), left(left), right(right), random(random) {}
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

class TreeSolution {
	std::unordered_map<TreeNode*, TreeNode*> m;
public:
	TreeSolution() = default;
	TreeNode* copyRandomBinaryTree(TreeNode* root) {
		if (root == nullptr) return nullptr;
		if (m.find(root) != m.end()) return m[root];

		TreeNode* p = new TreeNode(root->val);
		m[root] = p;

		p->left = copyRandomBinaryTree(root->left);
		p->right = copyRandomBinaryTree(root->right);
		p->random = copyRandomBinaryTree(root->random);

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

	TreeSolution t;


	return 0;
}
