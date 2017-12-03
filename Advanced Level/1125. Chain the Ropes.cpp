#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    double a[10001];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<=n;i++){
        a[i] = (a[i] + a[i-1])/2;
    }
    cout<<int(a[n]*2)<<endl;
    return 0;
}