#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include<string>
using namespace std;
static map<string, set<int> > title, author, key, pub, year;
void query(map< string, set<int> > &m, string &str) {
    if(m.find(str) != m.end()) {
        for(set<int>::iterator it = m[str].begin(); it != m[str].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main(){
	int n,id,m,num;
	cin>>n;
	string ttitle,tauthor, tkey, tpub, tyear;	
	for(int i=0;i<n;i++){
		cin>>id;
		cin.get();
		getline(cin,ttitle);
		title[ttitle].insert(id);
		getline(cin,tauthor);
		author[tauthor].insert(id);
		while(cin >> tkey) {
            key[tkey].insert(id);
            char c;
            c = getchar();
            if(c == '\n') break;
        }
        getline(cin, tpub);
        pub[tpub].insert(id);
        getline(cin, tyear);
        year[tyear].insert(id);
	}
	scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d: ", &num);
        string temp;
        getline(cin, temp);
        cout << num << ": " << temp << "\n";
        if(num == 1) query(title, temp);
        else if(num == 2) query(author, temp);
        else if(num == 3) query(key, temp);
        else if(num == 4) query(pub,temp);
        else if(num ==5) query(year, temp);
    }
    return 0;
}
