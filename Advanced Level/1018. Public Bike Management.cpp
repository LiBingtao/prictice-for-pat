#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static vector<int> temppath,path;
static vector<int> pre[510];
static int e[510][510],num[510],dis[510];
const int inf = 99999999;
static bool visit[510];
static int minneed=inf,minback=inf;
void Dijkstra();
void dfs(int v);
static int c,n,s,m;
int main(){
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);	
	cin>>c>>n>>s>>m;
	for(int i=1;i<=n;i++){cin>>num[i];num[i]=num[i]-c/2;}
	for(int i = 0; i < m; i++){
		int a,b,d;
		cin>>a>>b>>d;		
		e[a][b] = d;
		e[b][a] = d;	
	}
	Dijkstra();
	dfs(s);
	cout<<minneed<<" 0";
	for(int i = int(path.size()) - 2; i >= 0; i--)
        cout<<"->"<<path[u_long(i)];
	cout<<" "<<minback<<endl;
	return 0;
}
void Dijkstra(){
	dis[0]=0;
	for(int i = 0; i <= n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j <= n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v <= n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[v] > dis[u] + e[u][v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
	return;
}
void dfs(int v){
	if(v==0){
		temppath.push_back(v);
		int need=0,back=0;
		for(int i = int(temppath.size())-1;i>=0;i--){
			int id = temppath[u_long(i)];
			if(num[id]>0){
				back += num[id];
			}
			else{
				if(back>(0-num[id])){back += num[id];}
				else{need = need-num[id]-back;back=0;}
			}
		}
		if(need<minneed){
			minneed = need;	
			minback = back;
			path = temppath;
		}
		else if(need==minneed&&back<minback){
			minback = back;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	temppath.push_back(v);
	for (u_long i=0;i<pre[v].size();i++){
		dfs(pre[v][i]);	
	}
	temppath.pop_back();
}
