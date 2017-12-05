#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int mid = s.length()/2;
        string s1 = s.substr(0,mid);
        string s2 = s.substr(mid,s.length());
        int a = stoi(s1);
        int b = stoi(s2);
        int c = stoi(s);
        if(a==0||b==0) cout<<"No";
        else if(c%a==0 && c/a%b==0) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}