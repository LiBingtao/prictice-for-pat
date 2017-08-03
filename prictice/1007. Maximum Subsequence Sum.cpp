#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int k, t, left, templeft, right, sum = 0, max = -1, flag = 0;
	cin >> k;
	vector<int> v;
	for (int i = 0; i < k; i++) {
		cin >> t;
		v.push_back(t);
	}
	for (int i = 0; i < k; i++) {
		if (v[i] >= 0)flag = 1;
		sum += v[i];
		if (sum < 0) {
			sum = 0;
			templeft = i + 1;
			continue;
		}
		if (sum > max) {
			max = sum;
			left = templeft;
			right = i;
		}
	}
	if (flag == 0)cout << 0 << ' ' << v[0] << ' ' << v[k - 1] << endl;
	else cout << max << ' ' << v[left] << ' ' << v[right] << endl;
	system("pause");
	return 0;
}