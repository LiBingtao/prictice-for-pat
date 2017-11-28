#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int num[1000];
int maxdepth = -1;
vector<int> tree[1001];
struct node {
	int v;
	struct node *left, *right;
};
node *build(node *root,int n) {
	if (root == NULL) {
		root = new node;
		root->v = n;
		root->left = NULL;
		root->right = NULL;
	}
	else if (n <= root->v) {
		root->left = build(root->left, n);
	}
	else {
		root->right = build(root->right, n);
	}
	return root;
}
void dfs(node *root, int depth) {
	if (root == NULL) {
		maxdepth = max(depth, maxdepth);
		return;
	}
	num[depth]++;
	dfs(root->left, depth + 1);
	dfs(root->right, depth + 1);

}
int main() {
	int n, t;
	cin >> n;
	node *root = NULL;
	for (int i = 0; i < n; i++) {
		cin >> t;
		root = build(root, t);
	}
	dfs(root, 0);
	printf("%d + %d = %d", num[maxdepth - 1], num[maxdepth - 2], num[maxdepth - 1] + num[maxdepth - 2]);
	system("pause");
	return 0;
}
