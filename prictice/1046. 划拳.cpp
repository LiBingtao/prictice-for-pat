#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iomanip>  
using namespace std;

int main()
{
	//freopen("in.txt", "r", stdin);  
	//freopen("out.txt", "w", stdout);  
	int n = 0;
	cin >> n;
	int a1, a2, b1, b2;
	int count_a = 0, count_b = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a1 >> a2 >> b1 >> b2;
		int m = a1 + b1;
		if (a2 == m && b2 == m)
			continue;
		else if (a2 == m)
			count_a++;
		else if (b2 == m)
			count_b++;
	}
	cout << count_b << " " << count_a;
	return 0;
}