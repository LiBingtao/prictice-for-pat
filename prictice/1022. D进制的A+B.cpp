#include<iostream>
#include<stack>
using namespace std;
stack<int> a;
int main()
{
	int A, B, D;
	cin >> A >> B >> D;
	A = A + B;
	while (A / D) {
		a.push(A % D);
		A = A / D;
	}
	a.push(A);
	while (!a.empty()) {
		cout << a.top();
		a.pop();
	}
	system("pause");
	return 0;
}