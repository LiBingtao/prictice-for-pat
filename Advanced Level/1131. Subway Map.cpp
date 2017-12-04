#include<iostream>
#include<vector>
using namespace std;
vector<int> pre,path;
vector<int> e[10000];
bool visit[10000];
int line[10000][10000];
int transnum,start,destination,minn,mintrans;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]][a[i]] != preLine) cnt++;
        preLine = line[a[i-1]][a[i]];
    }
    return cnt;
}
void dfs(int s,int dep){
    visit[s]=true;
    if(s == destination){
        transnum = transferCnt(pre);
        if(dep<minn){
            minn = dep;
            path = pre;
            mintrans = transnum;
        }else if(dep==minn){
            if(transnum<mintrans){
                mintrans = transnum;
                path = pre;
            }
        }
    }
    if(s == destination) return;
    for(int i=0;i<e[s].size();i++){
        if(!visit[e[s][i]]){
            visit[e[s][i]]=true;
            pre.push_back(e[s][i]);
            dfs(e[s][i],dep+1);
            visit[e[s][i]]=false;
            pre.pop_back();
        }
    }
}
int main() {
    int n, m, k, last, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &last);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            e[last].push_back(temp);
            e[temp].push_back(last);
            line[last][temp] = line[temp][last] = i + 1;
            last = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &destination);
        minn=99999999;mintrans=99999999;
        pre.clear();
        pre.push_back(start);
        visit[start] = true;
        dfs(start,0);
        visit[start] = false;
        printf("%d\n", minn);
        int preLine = 0, preTransfer = start;
        for (int j = 1; j < path.size(); j++) {
            if (line[path[j-1]][path[j]] != preLine) {
                if (preLine != 0) printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j-1]);
                preLine = line[path[j-1]][path[j]];
                preTransfer = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, destination);
    }
    return 0;
}