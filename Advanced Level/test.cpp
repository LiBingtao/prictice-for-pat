#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w[10010], dp[10010];
bool choice[10010][10010];
int cmp1(int a, int b){return a > b;}
vector<int> arr;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    sort(w+1,w+1+n,cmp1);
    for(int i=1;i<=n;i++){
        for(int j=m;j>=w[i];j--){
            if(dp[j]<=dp[j-w[i]]+w[i]){
                choice[i][j] = true;
                dp[j] = dp[j-w[i]]+w[i];
            }
        }
    }
    if(dp[m]!=m) cout<<"No Solution"<<endl;
    else{
        int index=n,wei=m;
        while(wei>0){
            if(choice[index][wei]){
                arr.push_back(w[index]);
                wei-=w[index];
            }
            index--;
        }
        for(int i = 0; i < arr.size(); i++) {
            if(i != 0) printf(" ");
            printf("%d", arr[i]);
        }
    }
    return 0;
}