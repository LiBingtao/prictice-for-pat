#include <stdio.h>  
#include <algorithm> 
using namespace std;
int inc, dec;
void getnum(int x)
{
	int a[4];
	a[0] = x / 1000;
	a[1] = x / 100 % 10;
	a[2] = x / 10 % 10;
	a[3] = x % 10;
	sort(a, a + 4);
	inc = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
	dec = a[3] * 1000 + a[2] * 100 + a[1] * 10 + a[0];
}


int main() {
	int n, s;
	scanf("%d", &n);
	if ((n / 1000 == n / 100 % 10) && (n / 1000 == n / 10 % 10) && (n / 1000 == n % 10)) {
		printf("%04d - %04d = 0000\n", n, n);
		return 0;
	}
	do {
		getnum(n);
		s = dec - inc;
		printf("%04d - %04d = %04d\n", dec, inc, s);
		n = s;
	} while (s != 6174);
	return 0;
}