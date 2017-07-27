#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> anser(m);
	vector<char> ans;
	int mf[100], score[1000] = { 0 }, cuo[100] = { 0 };
	for (int i = 0; i < m; i++) {
		int b, cor;
		cin >> mf[i] >> b >> cor;
		for (int j = 0; j < cor; j++) {
			char c;
			cin >> c;
			anser[i].push_back(c);
		}
	}
	cin.get();
	for (int i = 0; i < n; i++) {
		string a;
		getline(cin, a);
		int k = 0, j = 0;
		while (k < a.length()) {
			if (a[k] == '(') {
				while (a[k] != ')') {
					if (a[k] >= 'a'&&a[k] <= 'z') {
						ans.push_back(a[k]);
					}
					k++;
				}
				if (ans == anser[j]) {
					score[i] += mf[j];
				}
				else {
					cuo[j]++;
				}
				j++;
				ans.clear();
			}
			k++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << score[i] << endl;
	}
	int maxWrongCnt = 0;
	for (int i = 0; i < m; i++) {
		if (cuo[i] > maxWrongCnt) {
			maxWrongCnt = cuo[i];
		}
	}
	if (maxWrongCnt == 0)
		printf("Too simple");
	else {
		printf("%d", maxWrongCnt);
		for (int i = 0; i < m; i++) {
			if (cuo[i] == maxWrongCnt) {
				printf(" %d", i + 1);
			}
		}
	}
	system("pause");
	return 0;
}