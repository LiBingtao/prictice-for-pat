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
		cin >> n;                  //����۲������   
		for (int j = 0; j<n; j++) {    //����ÿ��۲���õ���
			cin >> d;
			if (d<e)                 //����С��e������
				day++;
		}
		if (day>(n / 2)) {           //�������һ�������С��e����ܿ���
			if (n>D)              //����۲���������D��������һ������һ������
				must++;
			else possible++;        //�����ǿ��ܿ���

		}
	}                               //ע��Ҫ��ת����double��������100*possible/N�����possible=1��N=8����Ϊ12.0,������12.5
	printf("%.1lf%% %.1lf%%\n", (double)possible / N * 100, (double)must / N * 100);
	return 0;

}