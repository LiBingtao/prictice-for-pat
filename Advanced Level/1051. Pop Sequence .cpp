#include<iostream>
#include<stack>
using namespace std;
int main() {
	int m, n, k;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int arr[1001];
		stack<int> s;
		for (int j = 0; j < n; j++) {
			cin >> arr[j];
		}
		int current = 0;
		for (int j = 1; j <= n; j++) {
			s.push(j);
			if (s.size() > m) break;
			while (!s.empty() && s.top() == arr[current]) {
				s.pop();
				current++;
			}
		}
		if (current == n) printf("YES\n");
		else printf("NO\n");
	}
	system("pause");
	return 0;
}