#include<iostream>
#include<stdio.h>
using namespace std;
int yueshu(int k, int x) {
	return k%x == 0 ? x : yueshu(x, k%x);
}
int main()
{
	int n1, m1, n2, m2, k;
	scanf_s("%d/%d %d/%d %d", &n1, &m1, &n2, &m2, &k);
	double small = double(n1) / m1;
	double big = double(n2) / m2;
	if (small > big) {
		double temp = small;
		small = big;
		big = temp;
	}
	int a[10000];
	int j = 0;
	for (int i = 1; i < k; i++) {
		int yue = yueshu(k, i);
		if (yue != 1) {
			continue;
		}
		else {
			a[j++] = i;
		}
	}
	for (int i = 0; i < j; i++) {
		if (double(a[i]) / k > small&&double(a[i]) / k < big) {
			if (i + 1 >= j || double(a[i + 1]) / k >= big) {
				printf("%d/%d\n", a[i], k);
				break;
			}
				
			else {
				printf("%d/%d ", a[i], k);
			}
		}
	}
	system("pause");
	return 0;
}