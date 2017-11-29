#include<iostream>
#include<vector>
#include<string>
using namespace std;
int father[10010];
int visit[10010];
int find(int a){
    while(a!=father[a]){
        father[a] = father[father[a]];
        a = father[a];
    }
    return a;
}
void Union(int a,int b){
    int fa = find(a);
    int fb = find(b);
    if(fa!=fb){
        father[fa] = fb;
    }
}
int main(){
    for(int i=0;i<10010;i++){
        father[i]=i;
    }
    int n,k,q,max=-1,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>k;
        vector<int> temp(k);
        for(int j=0;j<k;j++){
            cin>>temp[j];
            if(temp[j]>max) max=temp[j];
            if(j!=0){
                Union(temp[0],temp[j]);
            }
        }
    }
    for(int i=1;i<=max;i++){
        int id = find(i);
        if(visit[id]==0){
            cnt++;
            visit[id]=1;
        }
    }
    cout<<cnt<<" "<<max<<endl;
    cin>>q;
    for(int i=0;i<q;i++){
        int ta,tb;
        cin>>ta>>tb;
        if(find(ta)==find(tb)) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}