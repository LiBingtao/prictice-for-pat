#include<iostream>
int main()
{
	int K;
	std::cin >> K;
	int arr[100];
	for (int i = 0; i < K; i++)
	{
		std::cin >> arr[i];
	}
	
	for (int i = 0; i < K; i++)
	{
		if (i == (K - 1)) { std::cout << arr[i]; }
		else { std::cout << arr[i] << " "; }
	}
	std::cin.get();
	std::cin.get();
}