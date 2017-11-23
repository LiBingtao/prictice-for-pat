#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
const int SIZE = 502;
const int inf = 99999999;
int n,m,s,d,mintime = inf,mindep = inf;
vector<int> pre[SIZE];
int length[SIZE][SIZE];
int times[SIZE][SIZE];
int dis[SIZE],ti[SIZE];
bool visit[SIZE];
vector<int> temppath,pathl,patht;
void dijkstra(int tar[],int data[][SIZE]){
    for(int i=0;i<n;i++){
        int u=-1,minn=inf;
        for(int j=0;j<n;j++){
            if(tar[j]<minn && !visit[j]){
                minn = tar[j];
                u = j;
            }
        }
        if(u==-1) break;
        visit[u] = true;
        for(int v=0;v<n;v++){
            if(!visit[v]&&data[u][v]!=inf){
                if(tar[u]+data[u][v]<tar[v]){
                    tar[v] = tar[u]+data[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(tar[u]+data[u][v]==tar[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}
void dfsl(int root,int time){
    temppath.push_back(root);
    if(root == s){
        if(time < mintime){
            mintime = time;
            pathl = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i=0;i<pre[root].size();i++){
        dfsl(pre[root][i],time + times[pre[root][i]][root]);
    }
    temppath.pop_back();
}
void dfst(int root,int dep){
    temppath.push_back(root);
    if(root==s){
        if(dep < mindep){
            mindep = dep;
            patht = temppath;
        }
        temppath.pop_back();
        return ;
    }
    for(int i=0;i<pre[root].size();i++){
        dfst(pre[root][i],dep + 1);
    }
    temppath.pop_back();
}
int main(){
    fill(dis,dis+SIZE,inf);
    fill(ti,ti+SIZE,inf);
    fill(length[0],length[0]+SIZE*SIZE,inf);
    fill(times[0],times[0]+SIZE*SIZE,inf);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,w,l,t;
        cin>>a>>b>>w>>l>>t;
        length[a][b] = l;
        times[a][b] = t;
        if(w!=1){
            length[b][a] = l;
            times[b][a] = t;
        }
    }
    cin>>s>>d;
    dis[s] = 0;
    ti[s] = 0;
    dijkstra(dis,length);
    dfsl(d,0);
    fill(visit,visit+SIZE,false);
    for(int i=0;i<SIZE;i++){
        pre[i].clear();
    }
    dijkstra(ti,times);
    dfst(d,0);
    printf("Distance = %d",dis[d]);
    if(pathl == patht){
        printf("; Time = %d: ", ti[d]);
    }else{
        printf(": ");
        for(int i = pathl.size() - 1; i >= 0; i--) {
            printf("%d", pathl[i]);
            if(i != 0) printf(" -> ");
        }
        printf("\n");
        printf("Time = %d: ", ti[d]);
    }
    for(int i=patht.size()-1;i>=0;i--){
        printf("%d", patht[i]);
        if(i != 0) printf(" -> ");
    }
    return 0;
}