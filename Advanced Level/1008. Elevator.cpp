#include<iostream>
using namespace std;
int main()
{
	int n, next, last = 0, time = 0;
	cin >> n;
	for(int i=0;i<n;i++) {
		cin >> next;
		if (next > last) {
			time = time + (next - last) * 6 + 5;
		}
		else time = time + (last - next) * 4 + 5;
		last = next;
	}
	cout << time << endl;
	system("pause");
	return 0;
}