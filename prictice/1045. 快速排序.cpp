#include <iostream>  
#include <algorithm>  
#include <stdio.h>  
using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int num[N], num_s[N];  //һ��ԭʼ���ݣ���һ�������Ѿ��źõ�����  
	for (int i = 0; i<N; i++)
	{
		scanf("%d", &num[i]);
		num_s[i] = num[i];
	}
	sort(num_s, num_s + N);
	int count = 0, max = 0;
	int res[N];

	for (int i = 0; i<N; i++)
	{
		if (num[i]>max)
			max = num[i];
		if (max == num[i] && num[i] == num_s[i])  //�����ǰ���Ǵӵ�һ��������ǰ������һ������������˳���Ӧλ�õ�����ͬ��������п�������Ԫ  
			res[count++] = num[i];
	}
	printf("%d\n", count);
	//sort(res,res+count);  
	for (int i = 0; i<count; i++)
		if (i == 0)
			printf("%d", res[i]);
		else
			printf(" %d", res[i]);
	printf("\n");
	return 0;
}