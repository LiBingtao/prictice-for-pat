#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() 
{
	int n;
	cin >> n;
	double a[10001];
	for (int i = 0; i < n; i++) {
		int b, c;
		cin >> b >> c;
		double d = (double)(b*b + c*c);
		a[i] = sqrt(d);
	}
	sort(a, a + n);
	printf("%.2lf", a[n - 1]);
	return 0;
}