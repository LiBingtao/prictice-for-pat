#include<iostream>
#include<algorithm>
using namespace std;
struct node {
	int id, best;
	int score[4], rank[4];
}stu[2001];
int flag = -1;
bool cmp(node a, node b) { return a.score[flag] > b.score[flag]; }
int excist[1000000] = { 0 };
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].id >> stu[i].score[1] >> stu[i].score[2] >> stu[i].score[3];
		stu[i].score[0] = (stu[i].score[3] + stu[i].score[1] + stu[i].score[2]) / 3 + 0.5;
	}
	for (flag = 0; flag < 4; flag++) {
		sort(stu, stu + n, cmp);
		for (int i = 0; i < n; i++) {
			if (stu[i].score[flag] == stu[i - 1].score[flag]) {
				stu[i].rank[flag] = stu[i - 1].rank[flag];
			}
			else stu[i].rank[flag] = i + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		excist[stu[i].id] = i+1;
		stu[i].best = 0;
		int minn = stu[i].rank[0];
		for (int j = 1; j <= 3; j++) {
			if (stu[i].rank[j] < minn) {
				minn = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}
	char c[5] = { 'A','C', 'M', 'E' };
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		if (excist[tmp]) {
			cout << stu[excist[tmp] - 1].rank[stu[excist[tmp] - 1].best] << ' ' << c[stu[excist[tmp] - 1].best] << endl;
		}
		else {
			cout << "N/A" << endl;
		}
	}
	system("pause");
	return 0;
}