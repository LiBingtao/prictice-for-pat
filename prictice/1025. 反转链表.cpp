#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
struct node {
	int add, data, next;
};
int main()
{
	vector<node> ori(100000);
	vector<node> list;
	vector<node> result;
	node temp;
	int start, n, k;
	cin >> start >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp.add >> temp.data >> temp.next;
		ori[temp.add] = temp;
	}
	int x = start;
	while (x != -1) {
		list.push_back(ori[x]);
		x = ori[x].next;
	}
	int end = k - 1;
	int n2 = list.size();
	while (end<n2) {
		for (int i = end; i>end - k; i--) {
			result.push_back(list[i]);
		}
		end += k;
	}
	for (int i = end - k + 1; i<n2; i++) {
		result.push_back(list[i]);
	}
	for (int i = 0; i < n2 - 1; i++) {
		printf("%05d %d %05d\n", result[i].add, result[i].data, result[i + 1].add);
	}
	printf("%05d %d -1\n", result[n2 - 1].add, result[n2 - 1].data);
	system("pause");
	return 0;
}