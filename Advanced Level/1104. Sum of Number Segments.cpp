#include<iostream>
using namespace std;
int a[100010];
int main(){
    int n;
    double t,sum = 0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        sum += t*i*(n-i+1);
    }
    printf("%.2lf",sum);
    return 0;
}