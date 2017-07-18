#include<iostream>
using namespace std;
struct student {
	int id;
	int d;
	int c;
	bool operator > (const student &A) const {
		if (d + c != A.d + A.c) {
			return d + c > A.d + A.c;
		}
		else if (d != A.d) {
			return d > A.d;
		}
		else {
			return id < A.id;
		}
	}
};

void mysort(student s[],int num)
{
	int j;
	for (int i = 1; i < num; i++) {
		student tem = s[i];
		for (j = i; j > 0 && tem > s[j - 1]; j--) {
			s[j] = s[j - 1];
		}
		s[j] = tem;
	}
}
int main()
{
	int n, l, h;
	int s1_num = 0, s2_num = 0, s3_num = 0, s4_num = 0;
	student s1[100000], s2[100000], s3[100000], s4[100000];
	cin >> n >> l >> h;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b >= l &&c >= l) {
			if (b >= h && c >= h) {
				s1[s1_num].id = a;
				s1[s1_num].d = b;
				s1[s1_num].c = c;
				s1_num++;
			}
			else if (b >= h) {
				s2[s2_num].id = a;
				s2[s2_num].d = b;
				s2[s2_num].c = c;
				s2_num++;
			}
			else if (b >= c) {
				s3[s3_num].id = a;
				s3[s3_num].d = b;
				s3[s3_num].c = c;
				s3_num++;
			}
			else {
				s4[s4_num].id = a;
				s4[s4_num].d = b;
				s4[s4_num].c = c;
				s4_num++;
			}
		}
	}
	mysort(s1, s1_num);
	mysort(s2, s2_num);
	mysort(s3, s3_num);
	mysort(s4, s4_num);
	cout << s1_num + s2_num + s3_num + s4_num << endl;
	for (int i = 0; i < s1_num; i++) {
		cout << s1[i].id << ' ' << s1[i].d << ' ' << s1[i].c << endl;
	}
	for (int i = 0; i < s2_num; i++) {
		cout << s2[i].id << ' ' << s2[i].d << ' ' << s2[i].c << endl;
	}
	for (int i = 0; i < s3_num; i++) {
		cout << s3[i].id << ' ' << s3[i].d << ' ' << s3[i].c << endl;
	}
	for (int i = 0; i < s4_num; i++) {
		cout << s4[i].id << ' ' << s4[i].d << ' ' << s4[i].c << endl;
	}
	cin.get();
	cin.get();
	return 0;
}