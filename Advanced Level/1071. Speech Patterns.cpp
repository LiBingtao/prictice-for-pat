#include<iostream>
#include<string>
#include<cctype>
#include<map>
using namespace std;
int main(){
    string s,t;
    getline(cin,s);
    map<string,int> m;
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])){
            s[i] = tolower(s[i]);
            t += s[i];
        }
        if(!isalnum(s[i]) || i == s.length()-1){
            if(t.length()!=0) m[t]++;
            t = "";
        }
    }
    int maxn = 0;
    for(auto it = m.begin();it!=m.end();it++){
        if(it->second > maxn){
            maxn = it->second;
            t = it->first;
        }
    }
    cout<<t<<" "<<maxn<<endl;
    return 0;
}