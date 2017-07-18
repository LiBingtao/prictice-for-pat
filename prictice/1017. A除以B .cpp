#include<iostream>
#include<string>
using namespace std;
int main()
{	
	int a, tmp = 0;
	string str;
	cin >> str >> a;
	if (str.length() == 1 && str[0] - '0' < a)
	{
		cout << "0 " << str[0] - '0' << endl;
	}
	else {
		for (int i = 0; i < str.length(); i++) {
			if (i == 0 && (int)(str[i] - '0') < a) {
				tmp = tmp * 10 + (int)(str[i] - '0');
				continue;
			}
			tmp = tmp * 10 + (int)(str[i] - '0');
			cout << tmp / a;
			tmp = tmp%a;
		}
		cout << ' ' << tmp << endl;
	}
	system("pause");
	return 0;
}