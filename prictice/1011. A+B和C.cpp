#include<iostream>
using namespace std;
int main()
{
	long n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a + b > c) {
			cout << "Case #" << i + 1 << ':' << " true" << endl;
		}
		else {
			cout << "Case #" << i + 1 << ':' << " false" << endl;
		}
	}
	cin.get();
	cin.get();
	return 0;
}