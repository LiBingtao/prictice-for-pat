#include<iostream>
using namespace std;
void rev(int arr[], int n, int m)
{
	for (int i = n, j = m; i < j; i++, j--) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	m = m%n;
	int arr[101];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	rev(arr, 0, n - m - 1);
	rev(arr, n - m, n - 1);
	rev(arr, 0, n - 1);
	for (int i = 0; i < n - 1; i++) {
		cout << arr[i] << " ";
	}
	cout << arr[n-1];
	cin.get();
	cin.get();
	return 0;
}