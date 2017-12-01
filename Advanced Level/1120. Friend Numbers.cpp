#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    set<int> s;
    string c;
    int n,temp;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c;
        temp = 0;
        for(int j=0;j<c.length();j++){
            temp += c[j]-'0';
        }
        s.insert(temp);
    }
    cout<<s.size()<<endl;
    for(auto it=s.begin();it!=s.end();it++){
        if(it!=s.begin()) cout<<" ";
        cout<<*it;
    }
    return 0;
}