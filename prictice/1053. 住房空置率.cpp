#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int N, D;
	double e;
	cin >> N >> e >> D;
	int n;
	double d;
	int possible = 0;
	int must = 0;
	for (int i = 0; i<N; i++) {
		int day = 0;
		cin >> n;                  //输入观察的天数   
		for (int j = 0; j<n; j++) {    //输入每天观察的用电量
			cin >> d;
			if (d<e)                 //计算小于e的天数
				day++;
		}
		if (day>(n / 2)) {           //如果超过一半的天数小于e则可能空置
			if (n>D)              //如果观察天数超过D且满足上一条件则一定空置
				must++;
			else possible++;        //否则还是可能空置

		}
	}                               //注意要先转换成double，不可以100*possible/N，如果possible=1，N=8，则为12.0,而不是12.5
	printf("%.1lf%% %.1lf%%\n", (double)possible / N * 100, (double)must / N * 100);
	return 0;

}