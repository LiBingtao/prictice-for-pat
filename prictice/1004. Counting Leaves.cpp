#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> tree[100];
int book[100] = { 0 };
int level[100];
int maxdepth = 0;
//void dfs(int index, int depth);
void bfs();
int main()
{
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		for (int j = 0; j < b; j++) {
			int c;
			cin >> c;
			tree[a].push_back(c);
		}
	}
	bfs();
	cout << book[0];
	for (int i = 1; i <= maxdepth; i++) {
		cout << ' ' << book[i];
	}
	system("pause");
	return 0;
}
/*void dfs(int index, int depth) {
	if (tree[index].size() == 0) {
		book[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}
	for (int i = 0; i < tree[index].size(); i++) {
		dfs(tree[index][i], depth + 1);
	}
}*/
void bfs() {
	queue<int> q;
	q.push(1);
	level[1] = 0;
	while (!q.empty()) {
		int index = q.front();
		q.pop();
		maxdepth = max(level[index], maxdepth);
		if (tree[index].size() == 0) {
			book[level[index]]++;
		}
		for (int i = 0; i < tree[index].size(); i++) {
			q.push(tree[index][i]);
			level[tree[index][i]] = level[index] + 1;
		}
	}
}