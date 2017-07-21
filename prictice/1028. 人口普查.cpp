#include<cstring>  
#include<cstdio>  
using namespace std;
int main() {
	int n, count = 0;
	char a[6], b[11], old[6], young[6];
	char small[11] = "1814/09/05";
	char big[11] = "2014/09/07";
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%s%s", a, b);
		if (strcmp(b, "1814/09/05")>0 && strcmp("2014/09/07", b)>0) {
			count++;
			if (strcmp(b, small)>0) {
				strcpy(small, b);
				strcpy(young, a);
			}
			if (strcmp(big, b)>0) {
				strcpy(big, b);
				strcpy(old, a);
			}
		}
	}
	if (count>0) {
		printf("%d %s %s\n", count, old, young);
	}
	else {
		printf("0\n");
	}
	return 0;
}