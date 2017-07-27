#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	string result = "";
	if (s1.size() > s2.size()) { 
		int val = s1.size() - s2.size();
		s2 = string(val, '0') + s2;
	}
	else if (s1.size() < s2.size()) { 
		int val = s2.size() - s1.size();
		s1 = string(val, '0') + s1;
	}
	int count = 1; 
	for (int i = s1.size() - 1; i >= 0; --i) {
		if (count % 2 == 1) { 
			int rest = (s1[i] + s2[i] - 2 * '0') % 13;
			if (rest >= 0 && rest < 10) {
				result = (char)(rest + '0') + result;
			}
			else if (rest == 10) {
				result = "J" + result;
			}
			else if (rest == 11) {
				result = "Q" + result;
			}
			else if (rest == 12) {
				result = "K" + result;
			}
		}
		else { 
			int tmp = s2[i] - s1[i];
			if (tmp < 0) {
				tmp += 10;
			}
			result = (char)(tmp + '0') + result;
		}
		++count;
	}
	cout << result << endl;
	return 0;
}
