#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct line {
	int id;
	queue<int> q;
	int poptime = 0;
	int endtime = 0;
};
bool cmp1(line a, line b) { 
	if (a.poptime == b.poptime) {
		return a.id < b.id;
	}
	else { return a.poptime < b.poptime; }
}
int main()
{
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	int need[1002];
	int finish[1002];
	fill(finish, finish + 1002, -1);
	for (int i = 0; i < k; i++) {
		cin >> need[i];
	}
	int check[1002];
	for (int i = 0; i < q; i++) {
		cin >> check[i];
	}
	line l[21];
	for (int i = 0; i < m*n && i<k; i++) {
		if (l[i%n].endtime >= 540) {
			l[i%n].id = i%n;
			l[i%n].q.push(i);
			l[i%n].poptime = need[l[i%n].q.front()];
			l[i%n].endtime += need[l[i%n].q.back()];
			continue;
		}
		l[i%n].id = i%n;
		l[i%n].q.push(i);
		l[i%n].poptime = need[l[i%n].q.front()];
		l[i%n].endtime += need[l[i%n].q.back()];
		finish[i] = l[i%n].endtime;
	}
	for (int i = m*n; i < k; i++) {
		sort(l, l + n, cmp1);
		if (l[0].poptime >= 540)break;
		if (l[0].endtime >= 540) {
			l[0].q.pop();
			l[0].q.push(i);
			l[0].poptime = l[0].poptime + need[l[0].q.front()];
			l[0].endtime = l[0].endtime + need[l[0].q.back()];
			continue;
		}
		l[0].q.pop();
		l[0].q.push(i);
		l[0].poptime = l[0].poptime + need[l[0].q.front()];
		l[0].endtime = l[0].endtime + need[l[0].q.back()];
		finish[i] = l[0].endtime;
	}
	for (int i = 0; i < q; i++) {
		if (finish[check[i]-1] == -1 ) {
			cout << "Sorry" << endl;
		}
		else {
			int h = finish[check[i]-1] / 60 + 8;
			int f = finish[check[i]-1] % 60;
			printf("%02d:%02d\n", h, f);
		}
	}
	system("pause");
	return 0;
}