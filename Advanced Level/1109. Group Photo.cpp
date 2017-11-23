#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct person {
	string name;
	int tall;
};
bool cmp(person a,person b) {
	if(a.tall!=b.tall) return a.tall > b.tall;
	else return a.name < b.name;
}
person p[10001];
vector<string> temp;
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i].name >> p[i].tall;
	}
	sort(p, p + n, cmp);
	int m = n / k;
	int index = (n - m*(k - 1)) / 2;
	temp.resize(n - m*(k - 1));
	for (int i = 0; i < n - m*(k - 1); i++) {
		index = index + i*pow(-1,i);
		temp[index] = p[i].name;
	}
	for (int i = 0; i < n - m*(k - 1); i++) {
		if (i != 0) cout << " ";
		cout << temp[i];
	}
	cout << endl;
	temp.clear();
	for (int i = 0; i < k-1; i++) {
		temp.resize(m);
		index = m / 2;
		int top = 0;
		for (int j = n - m*(k - 1) + (m*i); j < n - m*(k - 1) + (m*(i + 1)); j++) {
			index = index + top*pow(-1, top);
			temp[index] = p[j].name;
			top++;
		}
		for (int l = 0; l < m; l++) {
			if (l != 0) cout << " ";
			cout << temp[l];
		}
		cout << endl;
		temp.clear();
	}
	system("pause");
	return 0;
}
