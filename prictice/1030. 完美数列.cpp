#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, p;
	int max = 0;
	cin >> n >> p;
	long long a[100000];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int j = i;
		for (; a[j] <= a[i] * p && j < n; j++) {}
		if (j - i > max) {
			max = j - i;
		}
	}
	cout << max << endl;
	system("pause");
	return 0;
}