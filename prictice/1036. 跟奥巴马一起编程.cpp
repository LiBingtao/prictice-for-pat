#include<iostream>
using namespace std;
int main()
{
	int n;
	char ch;
	cin >> n >> ch;
	int h = (int)((float)(n) / 2 + 0.5)*2-1;
	for (int i = 0; i < h; i++) {
		if (i == 0 || i == h - 1) {
			for (int j = 0; j < n; j++) {
				cout << ch;
			}
			cout << endl;
		}
		else if(i % 2 == 1) {
		}
		else {
			for (int j = 0; j < n; j++) {
				if (j == 0 || j == n - 1) {
					cout << ch;
				}
				else {
					cout << ' ';
				}
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}