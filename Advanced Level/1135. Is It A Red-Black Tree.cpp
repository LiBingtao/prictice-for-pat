#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int v,left,right;
};
const int Size = 32;
int pre[Size];
node tree[Size];
int n,m,finalblack;
bool is=true;
void build(int left,int right){
    if(left==right) {
        tree[left].v = pre[left];
        tree[left].left = -1;
        tree[left].right = -1;
        return;
    }
    if(left>right) return;
    tree[left].v = pre[left];
    int i=left+1;
    while(abs(pre[i])<abs(pre[left]) && i<=right) i++;
    if(left+1<=right && abs(pre[left+1]) < abs(pre[left])) tree[left].left = left+1;
    else tree[left].left = -1;
    if(i<=right) tree[left].right = i;
    else tree[left].right = -1;
    build(left+1,i-1);
    build(i,right);
}
void dfs(int root,int black){
    if(tree[root].v>0) black+=1;
    if(tree[root].left==-1 && tree[root].right==-1){
        if(black!=finalblack) is = false;
        return;
    }
    if(tree[root].v<0 && ((tree[root].left!=-1&&tree[tree[root].left].v<0) || (tree[root].right!=0&&tree[tree[root].right].v<0))){
        is = false;
        return;
    }
    if(tree[root].left!=-1) dfs(tree[root].left,black);
    else{
        if(black!=finalblack) is = false;
    }
    if(tree[root].right!=-1) dfs(tree[root].right,black);
    else{
        if(black!=finalblack) is = false; 
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        is = true;
        fill(pre,pre+Size,0);
        for(int j=0;j<Size;j++){
            tree[j].v=tree[j].left=tree[j].right=0;
        }
        cin>>m;
        for(int j=0;j<m;j++){
            cin>>pre[j];
        }
        if(pre[0]<0) is=false;
        build(0,m-1);
        finalblack=0;
        for(int j=0;j!=-1;){
            if(tree[j].v>0) finalblack++;
            j = tree[j].left;
        }
        dfs(0,0);
        if(is) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    return 0;
}