#include<iostream>
int count = 0;
void sort(int *arr, int K)
{
	int temp;
	for (int i = 0; i < K; i++) 
	{
		for (int j = i+1; j < K; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
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
		int t = arr[i];
		if (t == 0)
		{
			continue;
		}
		while (t != 1)
		{
			
			if (t % 2 == 0) { t /= 2; }
			else { t = (3 * t + 1) / 2; }
			for (int j = 0; j < K; j++)
			{
				if (arr[j] == t)
				{ 
					arr[j] = 0; 
					break;
				}
			}
		}
	}
	sort(arr, K);
	int count = 0;
	while (arr[count] != 0) { count++;	}
	for (int i = 0; i < count; i++)
	{
		if (i == (count - 1)) { std::cout << arr[i]; }
		else { std::cout << arr[i] << " "; }
	}
	std::cin.get();
	std::cin.get();
	return 0;
}