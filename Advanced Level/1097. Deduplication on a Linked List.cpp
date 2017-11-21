#include <iostream>
#include <vector>
using namespace std;
int book[10001];
struct node{
	int ad, key, next;
};
node list[100001];
vector<node> list1, list2;
int main() {
	int first,n;
	cin >> first >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		list[a].ad = a;
		list[a].key = b;
		list[a].next = c;
	}
	int add = first;
	while (list[add].next != -1){
		if(book[abs(list[add].key)] == 0){
			list1.push_back(list[add]);
			book[abs(list[add].key)] = 1;
		}
		else {
			list2.push_back(list[add]);
		}
		add = list[add].next;
	} 
	if (book[abs(list[add].key)] == 0) {
		list1.push_back(list[add]);
		book[abs(list[add].key)] = 1;
	}
	else {
		list2.push_back(list[add]);
	}
	for (int i = 0; i < list1.size(); i++) {
		if (i == list1.size()-1) {
			printf("%05d %d -1\n", list1[i].ad, list1[i].key);
		}
		else {
			printf("%05d %d %05d\n", list1[i].ad, list1[i].key,list1[i+1].ad);
		}
	}
	for (int i = 0; i < list2.size(); i++) {
		if (i == list2.size() - 1) {
			printf("%05d %d -1\n", list2[i].ad, list2[i].key);
		}
		else {
			printf("%05d %d %05d\n", list2[i].ad, list2[i].key, list2[i + 1].ad);
		}
	}
	system("pause");
	return 0;
}