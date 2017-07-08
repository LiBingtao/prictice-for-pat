#include<iostream>
using namespace std;
int main()
{
	int a, b;
	bool c = true;
	while (cin >> a >> b)
	{
		if (b != 0) {
			if (c) {
				c = false;
			}
			else {
				cout << ' ';
			}
			cout << a*b << ' ' << b - 1;
		}
		
	}
	
	if (c) {
		cout << "0 0";
	}
	system("pause");
	return 0;
}