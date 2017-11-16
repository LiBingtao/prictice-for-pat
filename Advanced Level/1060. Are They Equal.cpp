#include<iostream>
#include<string>
using namespace std;
int main(){
    string a,b,A,B;
    int n;
    cin>>n>>a>>b;
    int p1,q1;
    int cnt = 0;
    bool find = false;
    for(int i=0;i<a.length();i++){
        if(a[i]!='0'&&!find&&a[i]!='.'){
            q1 = i;
            cnt++;
            find = true;
        }
        if(a[i]=='.'){
            p1 = i;
            cnt++;
        }
        if(cnt==2) break;
    }
    if(cnt!=2) p1 = a.length();
    int k1 = 0;
    if(find) k1 = (p1>q1)?(p1-q1):(p1-q1+1);
    for(int i=q1;i<a.length();i++){
        if(A.length()<n&&a[i]!='.'){
            A = A + a[i];
        }
    }
    while(A.length()<n){
        A = A + '0';
    }
    int p2,q2;
    cnt = 0;
    find = false;
    for(int i=0;i<b.length();i++){
        if(b[i]!='0'&&!find&&b[i]!='.'){
            q2 = i;
            cnt++;
            find = true;
        }
        if(b[i]=='.'){
            p2 = i;
            cnt++;
        }
        if(cnt==2) break;
    }
    if(cnt!=2) p2 = b.length();
    int k2=0;
    if(find) k2 = (p2>q2)?(p2-q2):(p2-q2+1);
    for(int i=q2;i<b.length();i++){
        if(B.length()<n&&b[i]!='.'){
            B = B + b[i];
        }
    }
    while(B.length()<n){
        B = B + '0';
    }
    if(A==B&&k1==k2){
        cout<<"YES 0."<<A<<"*10^"<<k1<<endl;
    }else{
        cout<<"NO 0."<<A<<"*10^"<<k1<<" 0."<<B<<"*10^"<<k2<<endl;
    }
    return 0;
}