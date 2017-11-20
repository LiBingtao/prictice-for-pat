#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> pre,in,post;
int n;
void get_post(int root,int start,int end){
    if(start>end) return;
    for(int i=start;i<end;i++){
        if(pre[root]==in[i]){
            get_post(root+1,start,i-1);
            get_post(root+1+i-start,i+1,end);
            break;
        }
    }
    post.push_back(pre[root]);
}
int main(){
    stack<int> s;
    cin>>n;
    for(int i=0;i<2*n;i++){
        char t[10];
        cin>>t;
        if(t[1]=='u'){
            int temp;
            cin>>temp;
            s.push(temp);
            pre.push_back(temp);
        }else{
            int temp = s.top();
            s.pop();
            in.push_back(temp);
        }
    }
    get_post(0,0,n-1);
    for(int i=0;i<post.size();i++){
        if(i!=0)cout<<" ";
        cout<<post[i];
    }
    return 0;
}