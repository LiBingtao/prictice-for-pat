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
void find(int same){
    vector<int> x,y;
    if(v[s].size()==0||v[d].size()==0) return;
    for(int i=0;i<v[s].size();i++){
        if(e[s][v[s][i]]==1&&v[s][i]!=d) x.push_back(v[s][i]);
    }
    for(int i=0;i<v[d].size();i++){
        if(e[d][v[d][i]]==1&&v[d][i]!=s) y.push_back(v[d][i]);
    }
    for(int i=0;i<x.size();i++){
        for(int j=0;j<y.size();j++){
            if(e[x[i]][y[j]]==same){
                node temp;
                temp.a = x[i];
                temp.b = y[j];
                res.push_back(temp);
            }
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
        if(a==0){
            if(b>0) find(1);
            else find(-1);
        }else if(b==0){
            if(a>0) find(1);
            else find(-1);
        }else if(a*b>0){
            find(1);
        }else {
            find(-1);
        }
        cout<<res.size()<<endl;
        for(int i=0;i<res.size();i++){
            printf("%04d %04d\n",res[i].a,res[i].b);
        }
    }
    return 0;
}