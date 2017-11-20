#include<iostream>
#include<vector>
using namespace std;
double p,r,res;
int n;
vector<int> v[100010];
int amount[100010];
void dfs(int index,double t){
    if(v[index].size()==0){
        res += p*t*amount[index];
        return;
    }
    for(int i=0;i<v[index].size();i++){
        dfs(v[index][i],t*(1+r));
    }
}
int main(){
    cin>>n>>p>>r;
    r = r/100;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num == 0){
            cin>>amount[i];
        }
        for(int j=0;j<num;j++){
            int fow;
            cin>>fow;
            v[i].push_back(fow);
        }
    }
    dfs(0,1);
    printf("%.1lf\n",res);
    return 0;
}