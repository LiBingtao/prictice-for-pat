#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct node{
    int value,left,right;
};
int t = 0;
node tree[101];
int v[101];
void inorder(int root){
    if(tree[root].left==-1&&tree[root].right==-1){
        tree[root].value = v[t++];
        return;
    }
    if(tree[root].left!=-1){
        inorder(tree[root].left);
    }
    tree[root].value = v[t++];
    if(tree[root].right!=-1){
        inorder(tree[root].right);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tree[i].left>>tree[i].right;
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v,v+n);
    inorder(0);
    queue<int> q;
    q.push(0);
    cout<<tree[0].value;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(top!=0 )cout<<" "<<tree[top].value;
        if(tree[top].left != -1) q.push(tree[top].left);
        if(tree[top].right != -1) q.push(tree[top].right);
    }
    cout<<endl;
    return 0;
}