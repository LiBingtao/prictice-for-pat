#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n,root;
int froot[21];
struct node{
    int left,right;
    string str;
};
vector<node> v;
void dfs(int root,int dep){
    if(v[root].left==-1&&v[root].right==-1){
        cout<<v[root].str;
        return;
    }
    if(dep!=0)cout<<"(";
    if(v[root].left!=-1){
        dfs(v[root].left,dep+1);
    }
    cout<<v[root].str;
    if(v[root].right!=-1){
        dfs(v[root].right,dep+1);
    }
    if(dep!=0)cout<<")";
}
int main(){
    cin>>n;
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i].str>>v[i].left>>v[i].right;
        froot[v[i].left]=froot[v[i].right]=1;
    }
    for(int i=1;i<=n;i++){
        if(froot[i]==0){
            root = i;
            break;
        }
    }
    dfs(root,0);
    return 0;
}