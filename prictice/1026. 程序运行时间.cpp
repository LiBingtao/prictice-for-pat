#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	long long a, b;

	cin >> a >> b;
	b = (0.5 + (double)(b - a) / 100);

	long long time = b;
	int hh = (int)(time / 3600);
	time %= 3600;
	int mm = (int)(time / 60);
	time %= 60;
	int ss = (int)time;

	printf("%02d:%02d:%02d\n", hh, mm, ss);

	return 0;
}