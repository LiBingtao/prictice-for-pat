#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node{
    int id,left,right;
};
node tree[11];
void level_order(int root){
    queue<int> q;
    q.push(root);
    cout<<root;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        if(top!=root) cout<<" "<<top;
        if(tree[top].left!=-1)q.push(tree[top].left);
        if(tree[top].right!=-1)q.push(tree[top].right); 
    }
    cout<<endl;
}
void in_order(int root){
    if(tree[root].left==-1&&tree[root].right==-1){
        cout<<root;
        return;
    }
    if(tree[root].left!=-1) in_order(tree[root].left);
    if(tree[root].left!=-1) cout<<" ";
    cout<<root;
    if(tree[root].right!=-1) cout<<" "; 
    if(tree[root].right!=-1) in_order(tree[root].right);
}
int main(){
    int n;
    scanf("%d", &n);getchar();
    vector<int> find_root(n);
    for(int i=0;i<n;i++){
        tree[i].id = i;
        char c1,c2;
        scanf("%c %c", &c1, &c2);getchar(); 
        if(c1=='-') tree[i].right = -1;
        else{
            tree[i].right = int(c1-'0');
            find_root[tree[i].right] = 1;
        }
        if(c2=='-') tree[i].left = -1;
        else{
            tree[i].left = int(c2-'0');
            find_root[tree[i].left] = 1;
        } 
    }
    int root;
    for(int i=0;i<n;i++){
        if(find_root[i] == 0){
            root = i;
            break;
        }
    }
    level_order(root);
    in_order(root);
    return 0;
}