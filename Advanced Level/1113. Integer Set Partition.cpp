#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
int a[100010];
int n, sum, sum1, sum2;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	for (int i = n/2; i < n; i++) {
		sum2 += a[i];
	}
	sum1 = sum - sum2;
	if (n % 2 == 0) {
		cout << 0 << " ";
	}
	else {
		cout << 1 << " ";
	}
	cout << sum2 - sum1 << endl;
	system("pause");
	return 0;
}
