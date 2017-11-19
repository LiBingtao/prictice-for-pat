#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int e[1020][1020];
int dis[1020];
const int inf = 99999999;
bool visit[1020];
int main(){
    int n,m,k,ds;
    cin>>n>>m>>k>>ds;
    fill(e[0],e[0]+1020*1020,inf);
    fill(dis,dis+1020,inf);
    for(int i=0;i<k;i++){
        string a,b;
        int an,bn,c;
        cin>>a>>b>>c;
        if(a[0]=='G'){
            a = a.substr(1);
            an = n+stoi(a);
        }else{
            an = stoi(a);
        }
        if(b[0]=='G'){
            b = b.substr(1);
            bn = n+stoi(b);
        }else{
            bn = stoi(b);
        }
        e[an][bn] = c; 
        e[bn][an] = c;
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for(int index=n+1;index<=m+n;index++){
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for(int i=0;i<n+m;i++){
            int minn=inf,u=-1;
            for(int j=1;j<=m+n;j++){
                if(minn>dis[j] && visit[j]==false){
                    minn = dis[j];
                    u = j;
                }
            }
            if(u==-1) break;
            visit[u] = true;
            for(int v=1;v<=m+n;v++){
                if(visit[v]==false){
                    if(e[u][v]+dis[u]<dis[v]){
                        dis[v] = e[u][v] + dis[u];
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dis[i]>ds){
                mindis = -1;
                break;
            }
            if(dis[i]<mindis){
                mindis = dis[i];
            }
            aver += 1.0*dis[i];
        }
        if(mindis == -1) continue;
        aver = aver/n;
        if(mindis>ansdis){
            ansdis = mindis;
            ansaver = aver;
            ansid = index;
        }else if(mindis == ansdis && aver<ansaver){
            ansid = index;
            ansaver = aver;
        }
    }
    if(ansid == -1) cout<<"No Solution"<<endl;
    else{
        printf("G%d\n",ansid - n);
        printf("%.1f %.1f\n", ansdis, ansaver);
    }
    return 0;
}