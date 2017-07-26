#include <stdio.h>  
#include <string.h>  
int main() {
	char str[100001];
	gets_s(str);
	int numP = 0;
	int numPA = 0;
	int numPAT = 0;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == 'P')         
			++numP;
		else if (str[i] == 'A')    
			numPA = (numPA + numP) % 1000000007;
		else {    
			numPAT = (numPAT + numPA) % 1000000007;
		}
	}
	printf("%d", numPAT);
	return 0;
}