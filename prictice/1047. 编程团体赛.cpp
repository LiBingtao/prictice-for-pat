#include <iostream>

using namespace std;

int queue[1001];

int main() {
	int n;
	scanf("%d", &n);
	int max = 0, max_index = -1;
	for (int i = 0; i < n; ++i) {
		int queueNo, memberNo, grade;
		scanf("%d-%d %d", &queueNo, &memberNo, &grade);
		// memberNo没卵用的，就来客串一下
		queue[queueNo] += grade;
		if (queue[queueNo] > max) {
			max = queue[queueNo];
			max_index = queueNo;
		}
	}
	printf("%d %d\n", max_index, max);
	return 0;
}

