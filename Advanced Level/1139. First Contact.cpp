#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
    int a,b;
};
int e[10000][10000];
vector<int> v[10000];
int n,m,s,d,k;
bool visit[10000];
vector<int> path;
vector<node> res;
void dfs1(int root,int dep){
    if(dep==3){
        if(root==d&&dep==3){
            if(e[path[2]][d]==1){
                node temp;
                temp.a = path[1];
                temp.b = path[2];
                res.push_back(temp);
            }
        }
        return;
    }
    for(int i=0;i<v[root].size();i++){
        if(dep==0){
            if(e[root][v[root][i]]==1&&!visit[v[root][i]]){
                path.push_back(v[root][i]);
                visit[v[root][i]] = true;
                dfs1(v[root][i],dep+1);
                visit[v[root][i]] = false;
                path.pop_back();
            }
        }else{
            if(!visit[v[root][i]]){
                path.push_back(v[root][i]);
                visit[v[root][i]] = true;
                dfs1(v[root][i],dep+1);
                visit[v[root][i]] = false;
                path.pop_back();
            }
        }
    }
}
void dfs2(int root,int dep){
    if(dep==3){
        if(root==d){
            node temp;
            temp.a = path[1];
            temp.b = path[2];
            res.push_back(temp);
        }
        return;
    }
    
    for(int i=0;i<v[root].size();i++){
        if(e[root][v[root][i]]==1&&!visit[v[root][i]]){
            path.push_back(v[root][i]);
            visit[v[root][i]] = true;
            dfs2(v[root][i],dep+1);
            visit[v[root][i]] = false;
            path.pop_back();
        }
    }
    
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        int c = abs(a);
        int d = abs(b);
        if(a*b>=0) {e[c][d]=1;e[d][c]=1;}
        else {e[c][d]=-1;e[d][c]=-1;}
        v[c].push_back(d);
        v[d].push_back(c);
    }
    for(int i=0;i<10000;i++){
        if(v[i].size()>1){
            sort(v[i].begin(),v[i].end());
        }
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int a,b;
        cin>>a>>b;
        fill(visit,visit+10000,false);
        res.clear();
        path.clear();
        s = abs(a);
        d = abs(b);
        visit[s]=true;
        path.push_back(s);
        if(a*b>=0){
            dfs2(s,0);
        }else{
            dfs1(s,0);
        }
        
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            printf("%04d %04d\n",res[i].a,res[i].b);
        }
    }
    return 0;
}