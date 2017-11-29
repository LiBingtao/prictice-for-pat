#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    int n,max=0;
    int a[100010];
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        if(a[i]>n-i){
            if(a[i]==n-i+1){
                if(n-i>max)
                    max = n-i;
            }else{
                if(n-i+1>max) max = n-i+1;
            }
        }else{
            if(a[i]==a[i+1]) continue;
            int temp = a[i];
            if(n-i>a[i] && n-i<a[i+1]){
                temp = n-i;
            }
            max = (temp>max)?temp:max;
        }
    }
    cout<<max<<endl;
    return 0;
}