#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct p {
	string id;
	string in;
	string out;
};
int main()
{
	int n;
	cin >> n;
	vector<p> v;
	p temp;
	for (int i = 0; i < n; i++) {
		cin >> temp.id >> temp.in >> temp.out;
		v.push_back(temp);
	}
	int min, max;
	string s = "00:00:00", b = "23:59:59";
	for (int i = 0; i < n; i++) {
		if (v[i].out > s) {
			max = i;
			s = v[i].out;
		}
		if (v[i].in < b) {
			min = i;
			b = v[i].in;
		}
	}
	cout << v[min].id << ' ' << v[max].id << endl;
	system("pause");
	return 0;
}