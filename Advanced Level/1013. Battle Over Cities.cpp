#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node) {
	visit[node] = true;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == false && v[node][i] == 1) {
			dfs(i);
		}
	}
}
int main() {
	int m, k, a, b;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a][b] = v[b][a] = 1;
	}
	for (int i = 0; i < k; i++) {
		fill(visit, visit + 1010, false);
		int cnt = 0;
		int t;
		cin >> t;
		visit[t] = true;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == false) {
				dfs(j);
				cnt++;
			}
		}
		printf("%d\n", cnt - 1);
	}
	system("pause");
	return 0;
}