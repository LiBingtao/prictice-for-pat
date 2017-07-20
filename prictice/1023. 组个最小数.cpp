#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	string A;
	cin >> A;
	int index = A.find('E');
	string coff = A.substr(1, index - 1);
	string exps = A.substr(index + 1);
	stringstream ss(exps);
	int exp;
	ss >> exp;
	if (exp < 0)
	{
		if (A[0] == '-')
			cout << '-';
		cout << "0.";
		exp++;
		while (exp++)
			cout << '0';
		for (int i = 0; i < coff.length(); i++)
			if (coff[i] != '.')
				cout << coff[i];
		cout << endl;
	}
	else
	{
		if (A[0] == '-')
			cout << '-';
		exp += 1;
		bool flag = true;
		for (int i = 0; i < coff.length(); i++)
		{
			if (coff[i] == '0' && flag)
				exp--;
			else if (coff[i] != '.')
			{
				flag = false;
				cout << coff[i];
				exp--;
			}
			if (exp == 0 && i != coff.length() - 1)
				cout << '.';
		}
		while (exp-- && exp >= 0)
			cout << '0';
		cout << endl;
	}
	return 0;
}