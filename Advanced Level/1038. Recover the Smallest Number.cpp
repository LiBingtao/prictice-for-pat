#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){
    return a+b<b+a; 
}
int main(){
    int n;
    string str[10001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    sort(str,str+n,cmp);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() != 0 && s[0] == '0')
        s.erase(s.begin());
    if(s.length() == 0)
        cout << 0;
    else
        cout << s;
    return 0;
}