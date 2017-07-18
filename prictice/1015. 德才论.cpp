#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct student {
	int id;
	int d;
	int c;
	bool operator < (const student &A) const {
		if (d + c != A.d + A.c) {
			return d + c > A.d + A.c;
		}
		else if (d != A.d) {
			return d > A.d;
		}
		else {
			return id < A.id;
		}
	}
};


int main()
{
	int n, l, h;
	int count=0;
	vector<student> s1, s2, s3, s4;
	cin >> n >> l >> h;
	student tmp;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tmp.id = a;
		tmp.d = b;
		tmp.c = c;
		if (b >= l &&c >= l) {
			count++;
			if (b >= h && c >= h) {
				s1.push_back(tmp);
			}
			else if (b >= h) {
				s2.push_back(tmp);
			}
			else if (b >= c) {
				s3.push_back(tmp);
			}
			else {
				s4.push_back(tmp);
			}
		}
	}
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	sort(s3.begin(), s3.end());
	sort(s4.begin(), s4.end());
	cout << count << endl;
	vector<student>::iterator itr;
	for (itr = s1.begin(); itr != s1.end(); ++itr) {
		printf("%d %d %d\n", itr->id, itr->d, itr->c);
	}
	for (itr = s2.begin(); itr != s2.end(); ++itr) {
		printf("%d %d %d\n", itr->id, itr->d, itr->c);
	}
	for (itr = s3.begin(); itr != s3.end(); ++itr) {
		printf("%d %d %d\n", itr->id, itr->d, itr->c);
	}
	for (itr = s4.begin(); itr != s4.end(); ++itr) {
		printf("%d %d %d\n", itr->id, itr->d, itr->c);
	}
	cin.get();
	cin.get();
	return 0;
}