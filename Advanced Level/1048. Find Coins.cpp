#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int coins[100010];
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int flag=0;
    sort(coins,coins+n);
    for(int i=0;i<n;i++){
        if(flag) break;
        for(int j=i+1;j<n;j++){
            if(coins[i]+coins[j]==m){
                cout<<coins[i]<<" "<<coins[j]<<endl;
                flag = 1;
                break;
            }
        }
    }
    if(!flag){
        cout<<"No Solution"<<endl;
    }
    return 0;
}