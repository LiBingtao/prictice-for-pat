#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int n,l;
bool hasforward[1010];
vector<int> v[1010];
// void dfs(int p,int dep){
//     if(hasforward[p]==false){
//         res++;
//         hasforward[p]=true;
//     }
//     if(dep==l || v[p].size()==0) return;
//     for(int i=0;i<v[p].size();i++){
//         dfs(v[p][i],dep+1);
//     }
// }
int bfs(int p){
    queue<int> q;
    q.push(p);
    hasforward[p]=true;
    int res = 0,dep=0,first=0,last=1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        first++;
        for(int i=0;i<v[top].size();i++){
            if(!hasforward[v[top][i]] && dep<=l){
                q.push(v[top][i]);
                hasforward[v[top][i]] = true;
                res++;
            }
        }
        if(first==last){
            last = res+1;
            dep++;
        }
        if(dep==l){
            return res;
        }
    }
    return res;
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
        fill(hasforward+1,hasforward+n+1,false);
        hasforward[t]=true;
        printf("%d\n",bfs(t));
    }
    return 0;
}