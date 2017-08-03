#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int sum = 0;
	stack<int> s;
	for (int i = 0; i < str.length(); i++) {
		sum = sum + str[i] - '0';
	}
	while (sum) {
		s.push(sum % 10);
		sum /= 10;
	}
	string eng[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	if (s.empty()) {
		cout << eng[0];
	}
	else {
		cout << eng[s.top()];
		s.pop();
		while (!s.empty()) {
			cout << ' ' << eng[s.top()];
			s.pop();
		}
	}
	system("pause");
	return 0;
}