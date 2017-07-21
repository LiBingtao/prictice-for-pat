#include<iostream>
using namespace std;
int main()
{
	int n;
	char f;
	cin >> n >> f;
	int m = 1, t = 1;
	if (n == 1) {
		m = 1;
		t = 1;
	}
	else {
		while (t < n) {
		m = m + 2;
		t = t + m * 2;
		}
		t = t - m * 2;
		m -= 2;
	}
	
	for (int i = m; i >=1 ; i-=2) {
		for (int j = 0; j < (m-i)/2 ; j++) {
			cout << ' ';
		}
		for (int j = 0; j < i; j++) {
			cout << f;
		}
		cout << endl;
	}
	for (int i = 3; i <= m; i += 2) {
		for (int j = 0; j < (m - i)/2; j++) {
			cout << ' ';
		}
		for (int j = 0; j < i; j++) {
			cout << f;
		}
		cout << endl;
	}
	cout << n - t << endl;
	system("pause");
	return 0;
}