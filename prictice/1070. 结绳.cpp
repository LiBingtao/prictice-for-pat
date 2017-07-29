#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, l;
	double a[10000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n-1; i++) {
		l = (a[i] + a[i + 1]) / 2;
		a[i + 1] = l;
	}
	cout << (int)l << endl;
	system("pause");
	return 0;
}