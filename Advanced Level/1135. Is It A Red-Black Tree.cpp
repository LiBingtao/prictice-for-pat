#include<iostream>
#include<algorithm>
using namespace std;
const int Size = 100000;
int tree[Size],pre[Size];
int n,m,finalblack;
bool is=true;
void build(int left,int right,int index){
    if(left>right) return;
    tree[index] = pre[left];
    int i=left+1;
    while(abs(pre[i])<abs(pre[left]) && i<m) i++;
    build(left+1,i-1,index*2+1);
    build(i,right,index*2+2);
}
void dfs(int root,int black){
    if(tree[root]==0){
        if(black!=finalblack) is = false;
        return;
    }
    if(tree[root]>0) black+=1;
    if(tree[root]<0 && (tree[root*2+1]<0 || tree[root*2+2]<0)){
        is = false;
        return;
    }
    dfs(root*2+1,black);
    dfs(root*2+2,black);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        is = true;
        fill(tree,tree+Size,0);
        fill(pre,pre+Size,0);
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>pre[j];
        }
        if(pre[0]<0) is=false;
        build(0,m-1,0);
        finalblack=0;
        for(int j=0;tree[j]!=0;j=j*2+1){
            if(tree[j]>0) finalblack++;
        }
        dfs(0,0);
        if(is) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}