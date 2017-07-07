#include<iostream>
#include<string>
using namespace std;
int main()
{	
	int n;
	cin >> n;
	cin.get();
	string arr[10];
	string result[10];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		cin.get();
	}
	
	int position_p = 0, position_t = 0;
	for (int i = 0; i < n; i++)
	{
		int count_p = 0,count_t = 0;
		for (int j = 0; j < (int)arr[i].length(); j++)
		{
			if (arr[i][j] != 'P' && arr[i][j] != 'A' && arr[i][j] != 'T')
			{
				result[i] = "NO";
				break;
			}
			if (arr[i][j] == 'P') {
				position_p = j;
				count_p++;
			}
			if (arr[i][j] == 'T') {
				position_t = j;
				count_t++;
			}
		}
		if (result[i] == "NO") {
			continue;
		}
		if (position_p*(position_t - position_p - 1) == ((int)arr[i].length() - position_t-1) && count_p == 1 && count_t == 1 && (position_t - position_p)>1) {
			result[i] = "YES";
		}
		else {
			result[i] = "NO";
		}
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}
	cin.get();
	cin.get();
	return 0;
}