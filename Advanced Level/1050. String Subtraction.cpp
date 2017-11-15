#include<iostream>
#include<string>
using namespace std;
int main() {
	int ascii[256];
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	cout << ascii[0] << endl;
	for (int i = 0; i < s1.length(); i++) {
		ascii[s1[i]] = 1;
	}
	for (int i = 0; i < s2.length(); i++) {
		ascii[s2[i]] = 0;
	}
	for (int i = 0; i < s1.length(); i++) {
		if (ascii[s1[i]] == 1){
			cout << s1[i];
		}
	}
	cout << endl;
	cin.get();
	return 0;
}