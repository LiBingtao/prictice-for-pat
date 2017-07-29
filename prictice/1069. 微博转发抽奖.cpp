#include<iostream>
#include<set>
#include<string>
using namespace std;
int main()
{
	int m, n, s;
	set<string> k;
	cin >> m >> n >> s;
	string a[1000];
	if (s > m) cout << "Keep going...";
	else {
		for (int i = 0; i < m; i++) {
			cin >> a[i];
		}
		for (int i = s-1; i < m; i += n) {
			if (k.find(a[i]) == k.end()) {
				cout << a[i] << endl;
				k.insert(a[i]);
			}
			else {
				for (int j = i; j < m; j++) {
					if (k.find(a[j]) == k.end()) {
						i = j;
						cout << a[i] << endl;
						k.insert(a[i]);
						break;
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}