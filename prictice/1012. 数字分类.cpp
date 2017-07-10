#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a1 = 0, a2 = 0, a3 = 0, a5 = 0, y;
	int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
	double a4 = 0;
	int n;
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		y = arr[i] % 5;
		if (arr[i] % 2 == 0 && y == 0) {
			a1 += arr[i];
			count1++;
		}
		if (y == 1) {
			if (count2 % 2 == 0) {
				a2 += arr[i];
				count2++;
			}
			else {
				a2 -= arr[i];
				count2++;
			}
		}
		if (y == 2) {
			a3 += 1;
			count3++;
		}
		if (y == 3) {
			a4 += arr[i];
			count4++;
		}
		if (y == 4) {
			if (arr[i] > a5) {
				a5 = arr[i];
				count5++;
			}
		}
	}
	if (count1 == 0) {
		cout << "N ";
	}
	else {
		cout << a1 << ' ';
	}
	if (count2 == 0) {
		cout << "N ";
	}
	else {
		cout << a2 << ' ';
	}
	if (count3 == 0) {
		cout << "N ";
	}
	else {
		cout << a3 << ' ';
	}
	if (count4 == 0) {
		cout << "N ";
	}
	else {
		double t = a4 / (double)count4;
		cout << setiosflags(ios::fixed) <<setprecision(1) << t << ' ';
	}
	if (count5 == 0) {
		cout << "N";
	}
	else {
		cout << a5;
	}
	cin.get();
	cin.get();
	return 0;
}