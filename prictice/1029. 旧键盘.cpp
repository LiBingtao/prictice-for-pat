#include<iostream>
using namespace std;
int main()
{
	char exp[82];
	char act[82];
	char res[82];
	cin >> exp >> act;
	int i = 0, j = 0, n = 0;
	while (exp[i] != '\0') {
		if (exp[i] == act[j] && act[j] != '\0') {
			i++;
			j++;
		}
		else {
			bool has = false;
			if (exp[i] >= 'a'&&exp[i] <= 'z') {
				exp[i] = exp[i] - 32;
			}
			for (int k = 0; k < n; k++) {
				if (exp[i] == res[k]) {
					has = true;
					i++;
					break;
				}
			}
			if (!has) {
				res[n] = exp[i];
				i++;
				n++;
			}
		}	
	}
	res[n] = '\0';
	cout << res << endl;
	system("pause");
	return 0;
}