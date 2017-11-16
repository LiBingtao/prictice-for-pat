#include<iostream>
#define max(a,b) ((a>b)?a:b)
using namespace std;
struct node{
    int key;
    node *left;
    node *right; 
};
node *leftleftrotate(node *root){
    node *t = root->left;
    root->left = t->right;
    t->right = root;
    return t;
}
node *rightrightrotate(node *root){
    node *t = root->right;
    root->right = t->left;
    t->left = root;
    return t; 
}
node *leftrightrotate(node *root){
    root->left = rightrightrotate(root->left);
    return leftleftrotate(root); 
}
node *rightleftrotate(node *root){
    root->right = leftleftrotate(root->right);
    return rightrightrotate(root); 
}
int Height(node *root){
    if(root == NULL) return 0;
    return max(Height(root->left),Height(root->right)) + 1;
}
node *insert(node *root,int val){
    if(root == NULL){
        root = new node();
        root->key = val;
        root->left = NULL;
        root->right = NULL;
    }
    else if(val < root->key){
        root->left = insert(root->left,val);
        if(Height(root->left) - Height(root->right) == 2){
            if(val < root->left->key) root = leftleftrotate(root);
            else root = leftrightrotate(root);
        }
    }
    else{
        root->right = insert(root->right,val);
        if(Height(root->left) - Height(root->right) == -2)
            root = (val > root->right->key)? rightrightrotate(root) : rightleftrotate(root);
    }
    return root;
}
int main(){
    int n, val;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    printf("%d", root->key);
    return 0;
}