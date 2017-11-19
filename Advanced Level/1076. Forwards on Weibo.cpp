#include<cstdio>
#include<vector>
using namespace std;
int res;
int n,l;
bool hasforward[1010];
vector<int> v[1010];
void dfs(int p,int dep){
    if(hasforward[p]==false){
        res++;
        hasforward[p]=true;
    }
    if(dep==l || v[p].size()==0) return;
    for(int i=0;i<v[p].size();i++){
        dfs(v[p][i],dep+1);
    }
}
int main(){
    scanf("%d %d",&n,&l);
    for(int i=1;i<=n;i++){
        int num;
        scanf("%d",&num);
        for(int j=1;j<=num;j++){
            int per;
            scanf("%d",&per);
            v[per].push_back(i);
        }
    }
    int q[1010];
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        int t;
        scanf("%d",&t);
        res = 0;
        fill(hasforward+1,hasforward+n+1,false);
        hasforward[t]=true;
        dfs(t,0);
        printf("%d\n",res);
    }
    return 0;
}