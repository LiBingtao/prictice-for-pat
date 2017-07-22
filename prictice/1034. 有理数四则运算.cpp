#include <iostream>
#include <cmath>

using namespace std;

//辗转相除法
int gcd(long a, long b) {
	return b == 0 ? a : gcd(b, a % b);
}

void print(long a, long b) {
	long c = 0;
	long gcd1 = abs(gcd(a, b));
	a /= gcd1;
	b /= gcd1;
	if (a > 0) {
		if (b == 1) { //形如3/1
			printf("%ld", a);
		}
		else if (a > b) { 
			c = a / b;
			a = a % b;
			printf("%ld %ld/%ld",c,a,b);
		}
		else if (a == b) {
			printf("1");
		}
		else {
			printf("%ld/%ld",a,b);
		}
	}
	else if (a == 0) {
		printf("0");
	}
	else {
		if (b == 1) { //形如3/1
			printf("(%ld)", a);
		}
		else if (-1 * a > b) {
			c = a/b;
			a = -1 * a % b;
			printf("(%ld %ld/%ld)", c, a, b);
		}
		else if (a == b) {
			printf("-1");
		}
		else {
			printf("(%ld/%ld)", a, b);
		}
	}
}
void add(long a1, long b1,long a2,long b2) {
	long a, b;
	a = a1*b2 + a2*b1;
	b = b1*b2;
	print(a1, b1);
	printf(" + ");
	print(a2, b2);
	printf(" = ");
	print(a, b);
	printf("\n");
}
void subtract(long a1, long b1, long a2, long b2) {
	long a, b;
	a = a1*b2 - a2*b1;
	b = b1*b2;
	print(a1, b1);
	printf(" - ");
	print(a2, b2);
	printf(" = ");
	print(a, b);
	printf("\n");
}
void multiply(long a1, long b1, long a2, long b2) {
	long a, b;
	a = a1*a2;
	b = b1*b2;
	print(a1, b1);
	printf(" * ");
	print(a2, b2);
	printf(" = ");
	print(a, b);
	printf("\n");
}
void divide(long a1, long b1, long a2, long b2) {
	long a, b;
	a = a1*b2;
	b = b1*a2;
	if (b < 0) {
		b = -b;
		a *= -1;
	}
	print(a1, b1);
	printf(" / ");
	print(a2, b2);
	printf(" = ");
	if (b == 0) {
		printf("Inf");
		printf("\n");
	}
	else {
		print(a, b);
		printf("\n");
	}
	
}
int main()
{
	long a1, b1, a2, b2;
	scanf_s("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);
	add(a1, b1, a2, b2);
	subtract(a1, b1, a2, b2);
	multiply(a1, b1, a2, b2);
	divide(a1, b1, a2, b2);
	system("pause");
	return 0;
}
