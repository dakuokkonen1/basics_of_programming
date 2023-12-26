#include <iostream>
#include <queue>

struct TreeNode {
	int data;
	struct TreeNode* left, * right;
};

class Solution {
public:
	// Функция для обхода дерева в ширину
	void bfs(TreeNode* root, int& max_sum) {
		std::queue<TreeNode*> q;
		q.push(root);
		int sum = 0;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				TreeNode* node = q.front();
				q.pop();
				sum += node->data;
				if (node->left) {
					q.push(node->left);
				}
				if (node->right) {
					q.push(node->right);
				}
			}
			if (sum > max_sum) {
				max_sum = sum;
			}
		}
	}

	int maxPathSum(TreeNode* root) {
		int max_sum = 0;
		bfs(root, max_sum);
		return max_sum;
	}
};

int main() {
	TreeNode root1{ 1, nullptr, nullptr };
	TreeNode node1_1{ 2, nullptr, nullptr };
	TreeNode node1_2{ 3, nullptr, nullptr };

	root1.left = &node1_1;
	root1.right = &node1_2;

	Solution solution;
	std::cout << "Max path sum: " << solution.maxPathSum(&root1) << std::endl;
}