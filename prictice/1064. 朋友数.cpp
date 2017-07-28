#include<iostream>
#include<set>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
int sum(string a) {
	int s = 0;
	for (int i = 0; i < a.length(); i++) {
		s = s + a[i] - '0';
	}
	return s;
}
int main()
{
	int n;
	cin >> n;
	string a;
	set<int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		int s = sum(a);
		v.insert(s);
	}
	cout << v.size() << endl;
	for (auto i = v.begin(); i != v.end(); i++) {
		if (i != v.begin()) printf(" ");
		printf("%d", *i);
	}
	return 0;
}