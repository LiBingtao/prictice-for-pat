#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int a = n % 10;
	n = n / 10;
	int b = n % 10;
	n /= 10;
	int c = n;
	for (int i = 0; i < c; i++) {
		cout << "B";
	}
	for (int i = 0; i < b; i++) {
		cout << "S";
	}
	for (int i = 0; i < a; i++) {
		cout << i + 1;
	}
	cin.get();
	cin.get();
}