#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct treenode{
    int v;
    struct treenode *left,*right;
};
treenode *rotate_right(treenode *root){
    treenode *node = root->left;
    root->left = node->right;
    node->right = root;
    return node;
}
treenode *rotate_left(treenode *root){
    treenode *node = root->right;
    root->right = node->left;
    node->left = root;
    return node;
}
treenode *rotate_rightleft(treenode *root){
    root->right = rotate_right(root->right);
    root = rotate_left(root);
    return root;
}
treenode *rotate_leftright(treenode *root){
    root->left = rotate_left(root->left);
    root = rotate_right(root);
    return root;
}
int getHeight(treenode *root){
    if(root==NULL) return 0;
    else{
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        return l>r? l+1 : r+1;
    }
}
treenode *insert(int n,treenode *node){
    if(node==NULL){
        node = new treenode();
        node->v = n;
        node->left = NULL;
        node->right = NULL;
    }
    else if(n<node->v){
        node->left = insert(n,node->left);
        if(getHeight(node->left)-getHeight(node->right)==2){
            node = n<node->left->v? rotate_right(node) : rotate_leftright(node);
        }
    }
    else{
        node->right = insert(n,node->right);
        if(getHeight(node->right)-getHeight(node->left)==2){
            node = n>node->right->v? rotate_left(node) : rotate_rightleft(node);
        } 
    }
    return node;    
}
int n,after=0;
bool isc = true;
vector<int> levelOrder(treenode *node){
    vector<int> v;
    queue<treenode *> q;
    q.push(node);
    while(!q.empty()){
        treenode *top = q.front();
        q.pop();
        v.push_back(top->v);
        if(top->left!=NULL) {if(after) isc = false;q.push(top->left);}
        else{
            after = 1;
        }
        if(top->right!=NULL) {if(after) isc = false;q.push(top->right);}
        else{
            after = 1;
        }
    }
    return v;
}
int main(){
    cin>>n;
    treenode *tree = NULL;
    for(int i=0;i<n;i++){
        int value;
        cin>>value;
        tree = insert(value,tree);
    }
    vector<int> v = levelOrder(tree);
    cout<<v[0];
    for(int i=1;i<v.size();i++){
        cout<<" "<<v[i];
    }
    if(isc) cout<<endl<<"YES"<<endl;
    else cout<<endl<<"NO"<<endl;
    return 0;
}