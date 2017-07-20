#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a;
	cin >> a;
	int d[10] = { 0 };
	for (int i = 0; i < (int)a.length(); i++) {
		d[a[i] - '0']++;
	}
	for (int i = 0; i < 10; i++) {
		if (d[i] == 0) {
			continue;
		}
		cout << i << ":" << d[i] << endl;
	}
	system("pause");
	return 0;
}