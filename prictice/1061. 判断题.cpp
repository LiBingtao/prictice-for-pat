#include<iostream>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int fen[100], da[100];
	for (int i = 0; i < m; i++) {
		cin >> fen[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> da[i];
	}
	int ans, res = 0;
	for (int i = 0; i < n; i++) {
		res = 0;
		for (int j = 0; j < m; j++) {
			cin >> ans;
			if (ans == da[j]) {
				res = res + fen[j];
			}
		}
		cout << res << endl;
	}
	return 0;
}