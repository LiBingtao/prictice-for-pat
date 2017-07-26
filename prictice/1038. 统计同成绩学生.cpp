#include<vector>  
#include <sstream>  
#include<cmath>  
#include<iomanip>  
#include<iostream>  
#include <ctype.h>  
#include <stdlib.h>  

using namespace std;

int main()
{
	int n;
	cin >> n;
	int scorecnt[101] = { 0 };//新建一个101大小的数组，将输入的分数作为下标  

	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		if ((temp >= 0) && (temp <= 100))//确保分数有效，也确保数组不会越界  
		{
			scorecnt[temp]++;//重复分数加1  
		}
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int temp;
		cin >> temp;//输入要查找的分数  
		if (i)
			cout << " " << scorecnt[temp];//将其作为下标直接输出即可  
		else
		{
			cout << scorecnt[temp];
		}
	}
	return 0;
}