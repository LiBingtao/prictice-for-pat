#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int in[31],post[31];
int n,root;
int tree[31][2];
vector<int> result[31];
struct node {
    int index, depth;
};
void get(int inl,int inr,int postl,int postr,int &index){
    if(postl>postr) return;
    index = postr;
    int i=inl;
    while(in[i]!=post[postr]) {i++;}
    get(inl,i-1,postl,postl+i-inl-1,tree[index][0]);
    get(i+1,inr,postl+i-inl,postr-1,tree[index][1]);
}
void bfs() {
    queue<node> q;
    q.push(node{root, 0});
    while (!q.empty()) {
        node temp = q.front();
        q.pop();
        result[temp.depth].push_back(post[temp.index]);
        if (tree[temp.index][0] != 0)
            q.push(node{tree[temp.index][0], temp.depth + 1});
        if (tree[temp.index][1] != 0)
            q.push(node{tree[temp.index][1], temp.depth + 1});
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>in[i];
    }
    for(int i=1;i<=n;i++){
        cin>>post[i];
    }
    get(1,n,1,n,root);
    bfs();
    printf("%d", result[0][0]);
    for (int i = 1; i < 31; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < result[i].size(); j++)
                printf(" %d", result[i][j]);
        } else {
            for (int j = result[i].size() - 1; j >= 0; j--)
                printf(" %d", result[i][j]);
        }
    }
    cout<<endl;
    return 0;
}