#include<iostream>
#include<vector>
using namespace std;
vector<int> g[10001];
int temp[10001];
int main(){
    int n,m,k;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int num,flag=0;
        cin>>num;
        for(int j=0;j<n;j++){
            temp[j] = g[j].size();
        }
        for(int j=0;j<num;j++){
            int t;
            cin>>t;
            temp[t] = 0;
            for(int v=0;v<g[t].size();v++){
                temp[g[t][v]]--;
            }
        }
        for(int j=0;j<n;j++){
            if(temp[j]>0){
                flag = 1;
                break;
            }
        }
        if(flag == 1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}