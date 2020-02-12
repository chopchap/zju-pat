#include <iostream>
using namespace std;
struct node {
	int val;
	struct node *left, *right;
};
node *ll(node *root) {
	node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}
node *rr(node *root) {
	node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}
node *lr(node *root) {
	root->left = ll(root->left);
	return rr(root);
}
node *rl(node *root) {
	root->right = rr(root->right);
	return ll(root);
}
int getHeight(node *root) {
	if (root == NULL) return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}
node *insert(node *root, int val) {
	if (root == NULL) {
		root = new node();
		root->val = val;
		root->left = root->right = NULL;
	} else if (val < root->val) {
		root->left = insert(root->left, val);
		if (getHeight(root->left) - getHeight(root->right) == 2)
			root = val < root->left->val ? rr(root) : lr(root);
	} else {
		root->right = insert(root->right, val);
		if (getHeight(root->left) - getHeight(root->right) == -2)
			root = val > root->right->val ? ll(root) : rl(root);
	}
	return root;
}
int main() {
	int n, val;
	scanf("%d", &n);
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &val);
		root = insert(root, val);
	}
	printf("%d", root->val);
	return 0;
}
