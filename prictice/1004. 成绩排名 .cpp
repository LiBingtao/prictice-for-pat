#include<iostream>
#include<string>
using namespace std;
struct student
{
	string name;
	string ID;
	int gra;
};
int main()
{
	int n, max = 0, min = 0;
	cin >> n;
	student stu[200];
	for (int i = 0; i < n; i++) {
		cin >> stu[i].name >> stu[i].ID >> stu[i].gra;
	}
	for (int i = 1; i < n; i++) {
		stu[i].gra > stu[max].gra ? max = i : max = max;
		stu[i].gra < stu[min].gra ? min = i : min = min;
	}
	cout << stu[max].name << " " << stu[max].ID << endl;
	cout << stu[min].name << " " << stu[min].ID << endl;
}