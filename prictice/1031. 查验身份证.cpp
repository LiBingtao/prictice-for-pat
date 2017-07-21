#include<iostream>
using namespace std;
int main()
{
	char ID[19];
	int n, flag = 0, tol = 0;
	int weight[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };
	char z[11] = { '1', '0','X','9','8','7','6','5','4','3','2' };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ID;
		tol = 0;
		int j;
		for (j = 0; j < 17; j++) {
			if (ID[j] >= '0'&&ID[j] <= '9') {
				tol = tol + (ID[j]-'0') * weight[j];
			}
			else {
				cout << ID << endl;
				flag = 1;
				break;
			}
		}
		if (z[tol % 11] != ID[17] && j==17) {
			flag = 1;
			cout << ID << endl;
		}
	}
	if (flag == 0) {
		cout << "All passed" << endl;
	}
	system("pause");
	return 0;
}