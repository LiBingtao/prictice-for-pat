#include<iostream>
int count = 0;
int func(int n)
{	
	if (n == 1) 
	{
		return count;
	}
	else if (n % 2 == 0)
	{
		count++;
		return func(n / 2);
	}
	else
	{
		count++;
		return func((3 * n + 1)/2);
	}
	
}

int main()
{
	int n = 0;
	std::cin >> n;
	int count = func(n);
	std::cout << count;
	std::cin.get();
	std::cin.get();
	return 0;
}
