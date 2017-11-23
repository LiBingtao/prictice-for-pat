#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<int> like;
vector<int> father, isroot;
int Find(int child) {
	while (father[child] != child) {
		father[child] = father[father[child]];
		child = father[child];
	}
	return child;
}
void Union(int a, int b) {
	int aroot = Find(a);
	int broot = Find(b);
	if (aroot != broot) {
		father[aroot] = broot;
	}
}
int cmp1(int a, int b) {
	return a > b;
}
int main() {
	int n, t;
	cin >> n;
	father.resize(n + 1);
	like.resize(1001);
	isroot.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int num;
		scanf_s("%d:", &num);
		for (int j = 0; j < num; j++) {
			cin >> t;
			if (like[t] == 0) like[t] = i;
			else Union(i, like[t]);
		}
		
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		int root = Find(i); 
		isroot[root]++;
	}
	for (int i = 1; i <= n; i++) {
		if (isroot[i] != 0)
			cnt++;
	}
	printf("%d\n", cnt);
	sort(isroot.begin(), isroot.end(), cmp1);
	for (int i = 0; i < cnt; i++) {
		printf("%d", isroot[i]);
		if (i != cnt - 1) printf(" ");
	}
	return 0;
}