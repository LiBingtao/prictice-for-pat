#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
map<string,int> si;
map<int,string> is;
const int inf = 99999999;
int e[201][201];
int dis[201],weight[201];
bool visit[201];
int n,k;
int maxvalue = 0,mindepth,cntpath=0;
double maxavg;
vector<int> pre[201],temppath,path;
void dfs(int v){
    temppath.push_back(v);
    if(v == 1){
        int value = 0;
        for(int i=0;i<temppath.size();i++){
            value += weight[temppath[i]];
        }
        double tempavg = 1.0*value/(temppath.size()-1);
        if(value>maxvalue){
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        }else if(value == maxvalue && maxavg<tempavg){
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return;
    }
    for(int i=0;i<pre[v].size();i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main(){
    fill(e[0],e[0]+201*201,inf);
    fill(dis,dis+201,inf);
    string s;
    cin>>n>>k>>s;
    si[s] = 1;
    is[1] = s;
    for(int i=2;i<=n;i++){
        cin>>s>>weight[i];
        si[s]=i;
        is[i]=s;
    }
    string sa,sb;
    int temp;
    for(int i=0;i<k;i++){
        cin>>sa>>sb>>temp;
        e[si[sa]][si[sb]] = temp;
        e[si[sb]][si[sa]] = temp;
    }
    dis[1]=0;
    for(int i=1;i<=n;i++){
        int u=-1,minn=inf;
        for(int j = 1;j<=n;j++){
            if(dis[j]<minn && !visit[j]){
                u = j;
                minn = dis[j];
            }
        }
        if(u==-1) break;
        visit[u]=true;
        for(int v=1;v<=n;v++){
            if(visit[v]==false&&e[u][v]!=inf){
                if(e[u][v]+dis[u] < dis[v]){
                    dis[v] = e[u][v]+dis[u];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(e[u][v]+dis[u] == dis[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = si["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for(int i = path.size() - 1; i >= 1; i--) {
        cout << is[path[i]] << "->";
    }
    cout << "ROM\n";
    return 0;
}