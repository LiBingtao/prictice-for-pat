#include<iostream>
#include<vector>
using namespace std;
int n,m;
vector<int> sum,res;
int bs(int i,int &j){
    int left = i,right = n;
    while(left < right){
        int mid = (left + right)/2;
        if(sum[mid]-sum[i-1]>=m){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    j = right;
    return sum[j] - sum[i-1];
}
int main(){
    cin>>n>>m;
    sum.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>sum[i];
        sum[i]+=sum[i-1];
    }
    int minsum = sum[n];
    for(int i=1;i<=n;i++){
        int j,tempsum;
        tempsum = bs(i,j);
        if(tempsum > minsum)
            continue;
        if(tempsum >= m) {
            if(tempsum < minsum) {
                res.clear();
                minsum = tempsum;
            }
            res.push_back(i);
            res.push_back(j);
        }
    }
    for(int i = 0; i < res.size(); i += 2)
        printf("%d-%d\n", res[i], res[i+1]);
    return 0;
}