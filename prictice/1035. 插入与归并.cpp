#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	vector<int> ori;
	vector<int> tar;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		ori.push_back(temp);
	}
	for (int i = 0; i < n; ++i) {
		int temp;
		cin >> temp;
		tar.push_back(temp);
	}
	int pos = -1;
	for (int i = 1; i < n; i++) {
		if (tar[i] < tar[i - 1]) {
			pos = i;
			break;
		}
	}
	int flag = 0;
	for (int i = pos; i < n; i++) {
		if (ori[i] != tar[i]) {
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "Insertion Sort" << endl;
		sort(tar.begin(), tar.begin() + pos+1);
		for (int i = 0; i < n-1; i++) {
			cout << tar[i]<<' ';
		}
		cout << tar[n - 1]<<endl;
	}
	if (flag == 1) {
		cout << "Merge Sort" << endl;
		bool eq = false;
		int k = 1;
		while (!eq) {
			if (equal(ori.begin(), ori.end(), tar.begin())) {
				eq = true;
			}
			k *= 2;
			for (int i = 0; i < n / k; i++) {
				sort(ori.begin() + i * k, ori.begin() + (i + 1) * k);
			}
			sort(ori.begin() + k * (n / k), ori.end());
		}
		for (int i = 0; i < n - 1; i++) {
			cout << ori[i]<<' ';
		}
		cout << ori[n - 1]<<endl;
	}
	system("pause");
	return 0;
}