#include<iostream>
#include<set>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	int arr[100000];
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		arr[a] = b;
		arr[b] = a;
	}
	cin >> m;
	set<int> s;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}
	set<int> st;
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		if (s.find(arr[*it]) == s.end()) {
			st.insert(*it);
		}
	}
	cout << st.size() << endl;
	for (it = st.begin(); it != st.end(); it++) {
		if (it != st.begin()) {
			cout << ' ';
		}
		cout << *it;
	}
	system("pause");
	return 0;
}