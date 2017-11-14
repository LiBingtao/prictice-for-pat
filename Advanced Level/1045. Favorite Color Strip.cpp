#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,l,m;
    vector<int> fav,backup;
    cin>>n;
    fav.resize(n+1);
    cin>>m;
    for(int i=1;i<=m;i++){
        int t;
        cin>>t;
        fav[t] = i;
    }
    cin>>l;
    for(int i=0;i<l;i++){
        int t;
        cin>>t;
        if(fav[t]>=1){
            backup.push_back(fav[t]);
        }
    }
    int cnt = backup.size();
    int maxn = 0;
    vector<int> dp(cnt);
    for(int i=0;i<cnt;i++){
        dp[i] = 1;
        for(int j=0;j<i;j++){
            if(backup[j]<=backup[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        maxn = max(dp[i],maxn);
    }
    cout<<maxn<<endl;
    return 0;
}