#include<iostream>
#include<queue>
using namespace std;
int brain[1300][130][80];
bool visit[1300][130][80];
int X[6] = {1, 0, 0, -1, 0, 0};
int Y[6] = {0, 1, 0, 0, -1, 0};
int Z[6] = {0, 0, 1, 0, 0, -1};
int m,n,l,t,ans;
struct node{
    int x,y,z;
};
bool judge(int x, int y, int z) {
    if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
    if(brain[x][y][z] == 0 || visit[x][y][z] == true) return false;
    return true;
}
int bfs(int i,int j,int k){
    int cnt = 0;
    node temp;
    temp.x = i,temp.y = j,temp.z = k;
    queue<node> q;
    visit[i][j][k]=true;
    q.push(temp);
    while(!q.empty()){
        node top = q.front();
        q.pop();
        cnt++;
        for(int n=0;n<6;n++){
            int tx = top.x + X[n];
            int ty = top.y + Y[n];
            int tz = top.z + Z[n];
            if(judge(tx, ty, tz)) {
                visit[tx][ty][tz] = true;
                temp.x = tx, temp.y = ty, temp.z = tz;
                q.push(temp);
            }
        }
    }
    if(cnt >= t)
        return cnt;
    else
        return 0;
}
int main(){
    cin>>m>>n>>l>>t;
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                cin>>brain[j][k][i];
            }
        }
    }
    for(int i=0;i<l;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<n;k++){
                if(brain[j][k][i]==1 && !visit[j][k][i]){
                    ans+=bfs(j,k,i);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}