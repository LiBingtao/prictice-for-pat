#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, index, max = 0, max2 = 0;
	int a[100000] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m, k;
		cin >> m >> k;
		if (m > max) { max = m; };
		a[m] = a[m] + k;
	}
	for (int i = 1; i < max+1; i++) {
		if (a[i] > max2) {
			max2 = a[i];
			index = i;
		}
	}
	cout << index << ' ' << max2 << endl;
	system("pause");
	return 0;
}