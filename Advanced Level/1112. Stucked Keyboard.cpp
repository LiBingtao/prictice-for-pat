#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
string ori, res1,res2;
int k;
int asc[256];
bool visit[256];
bool add[256];
bool isstucked(int i) {
	if (asc[ori[i]] >= 1) { return true; }
	if (!visit[ori[i]]) {
		visit[ori[i]] = true;
		for (int j = i; j < ori.length(); j++) {
			if (ori[j] != ori[i]) { continue; }
			int flag = 1;
			for (int h = j + 1; h < ori.length(); h++) {
				if (ori[h] != ori[j]) {
					break;
				}
				flag++;
			}
			if (flag%k==0) {
				asc[ori[j]]++;
				j += k - 1;				
			}
			else {
				asc[ori[i]] = 0;
				return false;
			}
		}
	}	
	if (asc[ori[i]] >= 1) { return true; }
	else return false;
}
int main() {
	cin >> k >> ori;
	for (int i = 0; i < ori.length(); ) {
		res2 += ori[i];
		if (isstucked(i)) {
			if (!add[ori[i]]) {
				add[ori[i]] = true;
				res1 += ori[i];
				asc[ori[i]]++;
			}
			i += k;
		}
		else {
			i++;
		}
	}
	cout << res1 << endl;
	cout << res2 << endl;
	system("pause");
	return 0;
}
