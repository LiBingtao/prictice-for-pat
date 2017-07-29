#include<iostream>
#include<cmath>
#include<map>
using namespace std;
int main()
{
	long z, tol;
	int x, y, m, n, flag = 0, unique = 0;
	long a[1003][1003] = { 0 };
	for (int i = 1; i <1003; i++) {
		for (int j = 1; j <1003; j++) {
			a[i][j] = -2^24;
		}
	}
	cin >> m >> n >> tol;
	map<long, int> s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			s[a[i][j]]++;
		}
	}
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <=m; j++) {
			if (abs(a[i][j] - a[i - 1][j - 1]) > tol&&abs(a[i][j] - a[i - 1][j]) > tol&&abs(a[i][j] - a[i - 1][j + 1]) > tol&&abs(a[i][j] - a[i][j - 1]) > tol&&abs(a[i][j] - a[i][j + 1]) > tol&&abs(a[i][j] - a[i + 1][j - 1]) > tol&&abs(a[i][j] - a[i + 1][j]) > tol&&abs(a[i][j] - a[i + 1][j + 1]) > tol) {
				if (s[a[i][j]] == 1) {
					flag++;
					x = j;
					y = i;
					z = a[i][j];
				}
			}
		}
		if (flag > 1) {
			break;
		}
	}
	if (flag == 0)cout << "Not Exist";
	if (flag == 1)printf("(%d, %d): %ld", x, y, z);
	if (flag > 1)cout << "Not Unique";
	return 0;
}