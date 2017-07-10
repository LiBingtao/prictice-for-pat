#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1, str2, str3, str4;
	int day, hour, minite, st = 0;
	string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
	std::cin >> str1 >> str2 >> str3 >> str4;
	for (int i = 0; i < (int)str1.length() && i<(int)str2.length(); i++) {
		if (st == 0 && str1[i] == str2[i] && str1[i]>='A'&& str1[i] <= 'G') {
			day = (int)str1[i] - (int)'A';
			st++;
			continue;
		}
		if ((st == 1 && str1[i] == str2[i] && str1[i] >= 'A'&&str1[i]<='N') || (st == 1 && str1[i] == str2[i] && str1[i] >= '0' && str1[i] <= '9')) {
			if (str1[i] >= 'A'&& str1[i] <= 'N') {
				hour = (int)str1[i] - (int)'A'+10;
				break;
			}
			else {
				hour = (int)str1[i] - (int)'0';
				break;
			}	
		}
	}
	for (int i = 0; i < (int)str3.length() && i<(int)str4.length(); i++) {
		if ((str3[i] == str4[i] && str3[i] >= 'a' && str3[i]<='z') || (str3[i] == str4[i] && str3[i] >= 'A' && str3[i] <= 'Z')) {
			minite = i;
			break;
		}
	}
	std::cout << week[day] << " ";
	if (hour < 10) {
		std::cout << 0 << hour;
	}
	else {
		std::cout << hour;
	}
	std::cout << ":";
	if (minite < 10) {
		std::cout << 0 << minite;
	}
	else {
		std::cout << minite;
	}
	std::cin.get();
	std::cin.get();
	return 0;
}