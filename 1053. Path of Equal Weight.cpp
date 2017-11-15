#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, s;
vector<int> tree[101];
vector<int> path;
int weight[101];
void dfs(int index,int sum) {
	sum += weight[index];
	//cout << index << endl;
	path.push_back(weight[index]);
	if (tree[index].size() == 0 || sum >= s) {
		if (tree[index].size() == 0) {
			if (sum == s) {
				for (int i = 0; i < path.size()-1; i++) {
					cout << path[i] << " ";			
				}
				cout << path[path.size() - 1] << endl;
			}	
		}
		path.pop_back();
		return;
	}
	for (int i = 0; i < tree[index].size(); i++) {
		dfs(tree[index][i], sum);
	}
	path.pop_back();
}
bool cmp(int a, int b) {
	return weight[a] > weight[b];
}
int main() {
	cin >> n >> m >> s;
	for (int i = 0; i < n; i++) {
		cin >> weight[i];
	}
	for (int i = 0; i < m; i++) {
		int node, children, child;
		cin >> node >> children;
		for (int j = 0; j < children; j++) {
			cin >> child;
			tree[node].push_back(child);
		}
		sort(tree[node].begin(), tree[node].end(),cmp);
	}
	dfs(0,0);
	system("pause");
	return 0;
}