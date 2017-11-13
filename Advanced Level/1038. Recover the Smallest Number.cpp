#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool cmp(string a,string b){
    if (a.length() == b.length()){
        return a<b;
    }else{
       if(a.length()>b.length()){
           int size = b.length();
           string sub1 = a.substr(0,size);
           string sub2 = a.substr(size,a.length()-size);
           if(sub1 != b){
               return sub1<b;
           }else{
               return sub2<b;
           }
       } 
       else{
           int size = a.length();
           string sub1 = b.substr(0,size);
           string sub2 = b.substr(size,b.length()-size);
           if(sub1 != a){
               return a<sub1;
           }else{
               return a<sub2;
           }
       }
    }
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