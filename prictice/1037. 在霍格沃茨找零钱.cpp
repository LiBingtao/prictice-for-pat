#include<iostream>
using namespace std;
int main()
{
	int a1, b1, a2, b2, c1, c2;
	scanf_s("%d.%d.%d %d.%d.%d", &a1, &b1, &c1, &a2, &b2, &c2);
	bool gou = true;
	if (a1 > a2 || (a1 == a2 && b1 > b2) || (a1 == a2&&b1 == b2&&c1 > c2)) {
		gou = false;
	}
	int a, b, c;
	if (!gou) {
		cout << '-';
		a = a1 - a2;
		if (b1 >= b2) {
			b = b1 - b2;
		}
		else {
			a -= 1;
			b = b1 + 17 - b2;
		}
		if (c1 >= c2) {
			c = c1 - c2;
		}
		else {
			if (b > 0) {
				b -= 1;
			}
			else {
				a -= 1;
				b = 16;
			}
			c = c1 + 29 - c2;
		}
	}
	else {
		a = a2 - a1;
		if (b2 >= b1) {
			b = b2 - b1;
		}
		else {
			a -= 1;
			b = b2 + 17 - b1;
		}
		if (c2 >= c1) {
			c = c2 - c1;
		}
		else {
			if (b > 0) {
				b -= 1;
			}
			else {
				a -= 1;
				b = 16;
			}
			c = c2 + 29 - c1;
		}
	}
	cout << a << '.' << b << '.' << c << endl;
	system("pause");
	return 0;
}