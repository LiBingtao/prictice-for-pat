#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct DATA {
	int id, fid, mid;
	double area, m;
	int cid[5];
}Data[10000];
struct node {
	int id, m;
	double sets, area;
	bool flag = false;
}ans[10000];
int pre[10000];
int find(int i) {
	while (i != pre[i]) {
		pre[i] = pre[pre[i]];
		i = pre[i];
	}
	return i;
}
void Union(int i, int j) {
	int a = find(i);
	int b = find(j);
	if (a < b) {
		pre[b] = a;
	}
	else if(a>b) {
		pre[a] = b;
	}
}
bool cmp(node a, node b) {
	if (a.area != b.area) {
		return a.area > b.area;
	}
	else {
		return a.id < b.id;
	}
}
bool visit[10000];
int main() {
	int n, k, cnt = 0;
	cin >> n;
	for (int i = 0; i < 10000; i++)
	{
		pre[i] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> Data[i].id >> Data[i].fid >> Data[i].mid >> k;
		visit[Data[i].id] = true;
		if (Data[i].fid != -1) {
			visit[Data[i].fid] = true;
			Union(Data[i].fid, Data[i].id);
		}
		if (Data[i].mid != -1) {
			visit[Data[i].mid] = true;
			Union(Data[i].mid, Data[i].id);
		}
		for (int j = 0; j < k; j++) {
			cin >> Data[i].cid[j];
			visit[Data[i].cid[j]] = true;
			Union(Data[i].cid[j], Data[i].id);
		}
		cin >> Data[i].m >> Data[i].area;
	}
	for (int i = 0; i < n; i++) {
		int id = find(Data[i].id);
		ans[id].id = id;
		ans[id].sets += Data[i].m;
		ans[id].area += Data[i].area;
		ans[id].flag = true;
	}
	for (int i = 0; i < 10000; i++) {
		if (visit[i]) {
			ans[find(i)].m++;
		}
		if (ans[i].flag)
			cnt++;
	}
	for (int i = 0; i < 10000; i++) {
		if (ans[i].flag) {
			ans[i].sets = (double)(ans[i].sets * 1.0 / ans[i].m);
			ans[i].area = (double)(ans[i].area * 1.0 / ans[i].m);
		}
	}
	sort(ans, ans + 10000, cmp);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++)
		printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].m, ans[i].sets, ans[i].area);
	system("pause");
	return 0;
}
