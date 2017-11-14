#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> sum(n+1);
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        sum[i] += sum[i-1];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int left,right;
        cin>>left>>right;
        if(left>right) swap(left,right);
        int dis = sum[right-1]-sum[left-1];
        printf("%d\n",min(dis,sum[n]-dis));
    }
    return 0;
}