#include<iostream>
#include<cstring>
#include<cstdio>
int main()
{
	char str[81];
	char word[40][80];
	int j = 0;
	std::cin.getline(str,81);
	int coun = 0;
	int length = strlen(str);
	for (int i = 0; i<length; i++) {
		if (str[i] == ' ') {
			word[coun][j]='\0';
			coun++;
			j = 0;
			continue;
		}
		word[coun][j++] = str[i];
	}
	word[coun][j] = '\0';
	for (int i = coun; i > 0; i--) {
		std::cout << word[i] << ' ';
	}
	
	std::cout << word[0];
	std::cin.get();
	std::cin.get();
}