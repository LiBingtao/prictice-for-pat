#include<iostream>
#include<string>
using namespace std;
int main()
{
	string pw, tr;
	int max;
	cin >> pw >> max;
	cin.get();
	getline(cin, tr);
	int count = 1;
	while (tr != "#") {
		if (tr == pw && count <= max) {
			cout << "Welcome in" << endl;
			break;
		}
		if (tr != pw && count<=max) {
			cout << "Wrong password: " << tr << endl;
		}
		count++;
		if (count > max) {
			cout << "Account locked" << endl; break;
		}
		getline(cin, tr);
	}
	system("pause");
	return 0;
}