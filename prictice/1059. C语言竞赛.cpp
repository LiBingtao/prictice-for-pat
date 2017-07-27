#include <cstdio>
#include <iostream>
#include <cmath>
#include <map>
#include <set>
using namespace std;
bool isprime(int a) {
	if (a <= 1) return false;
	int Sqrt = sqrt((double)a);
	for (int i = 2; i <= Sqrt; i++) {
		if (a % i == 0)
			return false;
	}
	return true;
}
int main() {
	int n, k;
	int a[10000] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		a[k] = i + 1;
	}
	cin >> k;
	set<int> ss;
	for (int i = 0; i < k; i++) {
		int id;
		cin >> id;
		printf("%04d: ", id);
		if (a[id] == 0) {
			printf("Are you kidding?\n");
			continue;
		}
		if (ss.find(id) == ss.end()) {
			ss.insert(id);
		}
		else {
			printf("Checked\n");
			continue;
		}
		if (a[id] == 1) {
			printf("Mystery Award\n");
		}
		else if (isprime(a[id])) {
			printf("Minion\n");
		}
		else {
			printf("Chocolate\n");
		}
	}
	return 0;
}