#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct cmp{
    bool operator()(int a,int b){
    return a>b;
    }
};

int main(){
    priority_queue<int,vector<int>,cmp> q;
    for(int i=0;i<10;i++){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
    for(int i=9;i>=0;i--){
        q.push(i);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}