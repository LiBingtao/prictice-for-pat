#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
int main() 
{
	int N;
	cin >> N;
	string mess,three="";
	string fire[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
	string jinzhi[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
	map<string, int>ge;
	map<string, int>shi;
	ge["tret"] = 0;
	ge["jan"] = 1; ge["feb"] = 2; ge["mar"] = 3; ge["apr"] = 4; ge["may"] = 5; ge["jun"] = 6;
	ge["jly"] = 7; ge["aug"] = 8; ge["sep"] = 9; ge["oct"] = 10; ge["nov"] = 11; ge["dec"] = 12;
	shi["tam"] = 1; shi["hel"] = 2; shi["maa"] = 3; shi["huh"] = 4; shi["tou"] = 5; shi["kes"] = 6;
	shi["hei"] = 7; shi["elo"] = 8; shi["syy"] = 9; shi["lok"] = 10; shi["mer"] = 11; shi["jou"] = 12;
	int len, number = 0;
	getchar();
	for (int i = 0; i < N; i++) {
		getline(cin, mess);
		if (mess[0] >= '0'&&mess[0] <= '9') {
			for (int j = 0; j < mess.size(); j++)
				number = number * 10 + mess[j] - '0';
			if (number < 13)
				cout << fire[number] << endl;
			else {
				if (number % 13 == 0) cout << jinzhi[number / 13 - 1] << endl;
				else cout << jinzhi[number / 13 - 1] << " " << fire[number % 13] << endl;
			}
		}
		else {
			for (int k = 0; k < mess.size(); k = k + 4) {
				three = three + mess[k] + mess[k + 1] + mess[k + 2];
				if (ge.find(three) != ge.end())
					number = number + ge[three];
				if (shi.find(three) != shi.end())
					number = number + shi[three] * 13;	
				three = "";
			}
				cout << number << endl;
		}
		number = 0;
	}
	return 0;
}