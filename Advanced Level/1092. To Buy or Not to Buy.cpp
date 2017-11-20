#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    map<char,int> m;
    int flag = 0, res = 0;
    for(int i=0;i<a.length();i++){
        m[a[i]]++;
    }
    for(int i=0;i<b.length();i++){
        m[b[i]]--;
    }
    for(auto it=m.begin();it!=m.end();it++){
        if(it->second<0){
            flag=1;
            break;
        }
    }
    if(flag){
        cout<<"No ";
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second<0){
                res = res + it->second;
            }
        } 
        cout<<-res<<endl;
    }else{
        cout<<"Yes ";
        for(auto it=m.begin();it!=m.end();it++){
            res = res + it->second;
        }  
        cout<<res<<endl;
    }
    return 0;
}