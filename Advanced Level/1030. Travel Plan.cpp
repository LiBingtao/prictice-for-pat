#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static int inf = 99999999;
int main()
{
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	int e[510][510], c[510][510], dis[510], cost[510];
	bool visit[510];
	vector<int> path[510];
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	fill(cost, cost + 510, inf);
	fill(visit, visit + 510, false);
	for (int i = 0; i < m; i++) {
		int a, b, aa, bb;
		cin >> a >> b >> aa >> bb;
		e[a][b] = aa;
		e[b][a] = aa;
		c[a][b] = bb;
		c[b][a] = bb;
	}
	dis[s] = 0;
	cost[s] = 0;
	for (int i = 0; i < n; i++) {
		int u=-1, minn = inf;
		for (int j = 0; j < n; j++) {
			if (dis[j] < minn && visit[j] == false) {
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1) break;
		visit[u] = true;
		for (int v = 0; v < n; v++) {
			if (visit[v] == false && e[u][v] != inf) {
				if (dis[u] + e[u][v] < dis[v]) {
					dis[v] = dis[u] + e[u][v];
					cost[v] = cost[u] + c[u][v];
					path[v].clear();
					path[v].push_back(u);
				}
				else if (dis[u] + e[u][v] == dis[v] && cost[u] + c[u][v] < cost[v]) {
					dis[v] = dis[u] + e[u][v];
					cost[v] = cost[u] + c[u][v];
					path[v].clear();
					path[v].push_back(u);
				}
			}
		}
			
	}
	vector<int> p;
	int id = d;
	p.push_back(id);
	while(id!=s){
		id = path[id][0];
		p.push_back(id);
	}
	for(int i=p.size()-1;i>=0;i--){
		cout<<p[i]<<" ";	
	}
	cout<<dis[d]<<" "<<cost[d]<<endl;
	return 0;
}
