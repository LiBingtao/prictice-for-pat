#include<iostream>
using namespace std;
int main(){
    int n,left,right,now,a=1,ans=0;
    cin>>n;
    while(n/a){
        left = n/a/10;
        now = n/a%10;
        right = n%a;
        if(now == 0) ans+=left*a;
        else if(now == 1) ans+=left*a+right+1;
        else ans+= (left+1)*a;
        a *= 10;
    }
    cout<<ans<<endl;
    return 0;
}