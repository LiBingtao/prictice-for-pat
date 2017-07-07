#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
	string pin[10] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < (int)n.length(); i++)
	{
		sum += (int)(n[i] - '0');
	}
	stack<int> st;
	while (sum != 0)
	{
		st.push(sum % 10);
		sum /= 10;
	}
	while (1)
	{
		int get = st.top();
		st.pop();
		if (st.empty())
		{
			cout << pin[get];
			break;
		}
		else {
			cout << pin[get] << " ";
		}
	}
	cin.get();
	cin.get();
}