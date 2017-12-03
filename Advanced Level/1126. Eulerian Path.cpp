#include<iostream>
#include<vector>
using namespace std;
int degree[501];
int e[501][501];
int oddnum = 0;
int n,m,flag = 0;
bool visit[501];
vector<int> graph[501];
void dfs(int root){
    visit[root] = true;
    if(graph[root].size()==0) return;
    for(int i=0;i<graph[root].size();i++){
        if(!visit[graph[root][i]]){
            dfs(graph[root][i]);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        e[a][b]=e[b][a] = 1;
        degree[a]++;
        degree[b]++;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(i!=1) cout<<" ";
        cout<<degree[i];
        if(degree[i]%2!=0) oddnum++;
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            flag++;
            dfs(i);
        }
    }
    if(oddnum==0 && flag==1){
        cout<<"Eulerian"<<endl;
    }else if(oddnum==2 && flag==1) cout<<"Semi-Eulerian"<<endl;
    else cout<<"Non-Eulerian"<<endl;
    return 0;
}