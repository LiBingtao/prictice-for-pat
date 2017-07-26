#include<iostream>  
#include<fstream>  
#include<string>  
#include<map>  
using namespace std;

int main()
{
	string S1 = "PATest", S2;
	map<char, int>Map;
	for (int i = 0; i<S1.size(); i++)
	{
		Map[S1[i]] = 0;
	}

	cin >> S2;
	int num = 0;
	for (int i = 0; i<S2.size(); i++)
	{
		if (Map.find(S2[i]) != Map.end())
		{
			Map[S2[i]]++;
			num++;
		}
	}
	while (num)
	{
		for (int i = 0; i<S1.size(); i++)
		{
			if (Map[S1[i]])
			{
				cout << S1[i];
				Map[S1[i]]--;
				num--;
			}
		}
	}
	cout << endl;
	return 0;
}