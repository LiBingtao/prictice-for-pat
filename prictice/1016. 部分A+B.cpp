#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a, b;
	char da, db;
	int at = 0, bt = 0;
	cin >> a >> da >> b >> db;
	for (int i = 0; i < (int)a.length(); i++) {
		if (a[i] == da) {
			at = at * 10 + (int)(da-'0');
		}
	}
	for (int i = 0; i < (int)b.length(); i++) {
		if (b[i] == db) {
			bt = bt * 10 + (int)(db-'0');
		}
	}
	int result = at + bt;
	cout << result;
	cin.get();
	cin.get();
	return 0;
}