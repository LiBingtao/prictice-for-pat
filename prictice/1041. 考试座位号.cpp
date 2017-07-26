#include<iostream>
#include<string>
using namespace std;
struct S {
	string id;
	int kao;
};
int main()
{
	int n;
	S stu[1001];
	S temp;
	int tem;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp.id >> tem >> temp.kao;
		stu[tem].id = temp.id;
		stu[tem].kao = temp.kao;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tem;
		cout << stu[tem].id << ' ' << stu[tem].kao << endl;
	}
	system("pause");
	return 0;
}