#include<iostream>
#include<set>
using namespace std;
int a[100000];
int main(){
    int n,m,id;
    set<int> s,res;
    cin>>n;
    for(int i=0;i<n;i++){
        int id1,id2;
        cin>>id1>>id2;
        a[id1] = id2;
        a[id2] = id1;
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>id;
        s.insert(id);
    }
    for(auto it=s.begin();it!=s.end();it++){
        if(s.find(a[*it])==s.end()) res.insert(*it);
    }
    cout<<res.size()<<endl;
    for(auto it=res.begin();it!=res.end();it++){
        if(it != res.begin()) cout<<" ";
        printf("%05d",*it);
    }
    return 0;
}