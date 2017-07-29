#include<iostream>
using namespace std;
int main()
{
	int m, n, a, b, c, tmp;
	cin >> m >> n >> a >> b >> c;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp >= a&&tmp <= b) {
				tmp = c;
			}
			if (j != 0)
				printf(" ");
			printf("%03d", tmp);
		}
		printf("\n");
	}
	return 0;
}