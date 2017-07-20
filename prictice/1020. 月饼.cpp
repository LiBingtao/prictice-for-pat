#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
struct mooncakes {
	double amount;
	double tolprice;
	double price;
};
bool cmp(mooncakes a, mooncakes b) {
	return a.price>b.price;
}
int main()
{
	int num;
	double profit = 0, needs;
	mooncakes mooncake[1000];
	cin >> num >> needs;
	for (int i = 0; i < num; i++) {
		cin >> mooncake[i].amount;
	}
	for (int i = 0; i < num; i++) {
		cin >> mooncake[i].tolprice;
		mooncake[i].price = mooncake[i].tolprice / mooncake[i].amount;
	}
	sort(mooncake, mooncake + num, cmp);
	for (int i = 0; i < num; i++) {
		if (needs <= mooncake[i].amount) {
			profit = profit + mooncake[i].price*needs;
			break;
		}
		else {
			profit = profit + mooncake[i].price*mooncake[i].amount;
			needs -= mooncake[i].amount;
		}
	}
	printf("%.2f", profit);
	system("pause");
	return 0;
}