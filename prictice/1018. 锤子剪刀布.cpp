#include<iostream>
using namespace std;
char most_gesture(int j, int c, int b);
int main()
{
	int jw = 0, jwc = 0, jwj = 0, jwb = 0, p = 0;
	int yw = 0, ywc = 0, ywj = 0, ywb = 0;
	int n;
	cin >> n;
	char a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a == b) {
			p++;
		}
		else if ((a == 'J'&&b == 'B') || (a == 'B'&&b == 'C') || (a == 'C'&&b == 'J')) {
			jw++;
			switch (a) {
				case'C':jwc++; break;
				case'J':jwj++; break;
				case'B':jwb++; break;
			}
		}
		else {
			yw++;
			switch (b) {
			case'C':ywc++; break;
			case'J':ywj++; break;
			case'B':ywb++; break;
			}
		}
	}
	a = most_gesture(jwj, jwc, jwb);
	b = most_gesture(ywj, ywc, ywb);
	cout << jw <<' '<< p <<' '<< yw << endl;
	cout << yw <<' '<< p <<' '<< jw << endl;
	cout << a << ' ' << b << endl;
	system("pause");
	return 0;
}

char most_gesture(int j, int c, int b) {
	if (j > c) {
		if (j > b) {
			return 'J';
		}
		else {
			return 'B';
		}
	}
	else if (j == c) {
		if (j > b) {
			return 'C';
		}
		else {
			return 'B';
		}
	}
	else {
		if (c <= b) {
			return 'B';
		}
		else {
			return 'C';
		}
	}
}
