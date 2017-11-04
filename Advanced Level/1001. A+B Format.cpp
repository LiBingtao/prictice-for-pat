#include <cstdlib>  
#include <iostream>  
#include <string>  
#include <algorithm>  

using namespace std;

int main()
{
	int a, b, sum, n, i;

	n = 1, i = 1;
	cin >> a >> b;
	sum = a + b;
	bool isneg = false;
	if (sum<0)
	{
		isneg = true;
		sum = 0 - sum;
	}
	string str;
	if (isneg)
	{
		cout << '-';
	}
	if (sum < 1000) {
		cout << sum << endl;
	}
	else {
		while (sum)
		{
			char ch = '0' + sum % 10;
			sum /= 10;
			if (i % 4 == 0)
			{
				str.push_back(',');
				i = 1;
			}
			str.push_back(ch);
			i++;
		}
		reverse(str.begin(), str.end());
		cout << str << endl;

	}
	system("PAUSE");
	return 0;
}
/*
 	test
 */
 
