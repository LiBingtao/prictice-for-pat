#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> v[101];
int n, m;
int maxn = -1, reslevel = 0;
void bfs(int index, int level) {
	int cnt = 0, first = 0, last = 1, res = 0;
	queue<int> q;
	q.push(index);
	while (!q.empty()) {
		int top = q.front();
		q.pop();
		first++;
		cnt++;
		for (int i = 0; i < v[top].size(); i++) {
			q.push(v[top][i]);
			res++;
		}
		if (first == last) {
			if (cnt > maxn) {
				maxn = cnt;
				reslevel = level;
			}
			cnt = 0;
			last = res + 1;
			level++;
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int fa, chn;
		cin >> fa >> chn;
		for (int j = 0; j < chn; j++) {
			int ch;
			cin >> ch;
			v[fa].push_back(ch);
		}
	}
	bfs(1, 1);
	cout << maxn << " " << reslevel << endl;
	system("pause");
	return 0;
}