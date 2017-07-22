#include<iostream>
#include<string>
#include<string.h>
using namespace std;
int main()
{
	char ascii[256] = { 0 };
	char b[100001];
	gets_s(b);
	for (int i = 0; i<strlen(b); i++) {
		ascii[b[i]] = 1;
		if (b[i] >= 'A'&& b[i] <= 'Z')
		{
			b[i] = b[i] - 'A' + 'a';
			ascii[b[i]] = 1;
		}
	}
	string a;
	cin >> a;
	for(int i=0;i<a.length();i++)
	{
		if (ascii[a[i]] == 0) {
			if (a[i] >= 'A'&&a[i] <= 'Z' && (ascii['+'] == 1)) {
				continue;
			}
			cout << a[i];
		}
	}
	cout << endl;
	system("pause");
	return 0;
}