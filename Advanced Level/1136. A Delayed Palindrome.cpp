#include<iostream>
#include<string>
using namespace std;
bool is(string a){
    int k=a.length();
    for(int i=0;i<k/2;i++){
        if(a[i]!=a[k-1-i]) return false;
    }
    return true;
}
string add(string a){
    string temp,b;
    int shiwei=0;
    int k = a.length();
    for(int i=0;i<k;i++){
        b += a[k-i-1];
        int x = a[k-1-i]-'0';
        int y = a[i]-'0';
        int z = x+y+shiwei;
        shiwei = z/10;
        z = z%10;
        temp = char(z+'0') + temp;
    }
    if(shiwei!=0) temp = char(shiwei+'0') + temp;
    cout<<a<<" + "<<b<<" = "<<temp<<endl;
    return temp;
}
int main(){
    string a;
    cin>>a;
    int cnt=0;
    while(cnt<=9&&!is(a)){
        a = add(a);
        cnt++;
    }
    if(cnt==10 && !is(a)){
        cout<<"Not found in 10 iterations.";
    }else{
        cout<<a<<" is a palindromic number.";
    }
    return 0;
}