#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[100010],b[100010];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    vector<int> res;
    int maxn = 0;
    for(int i=0;i<n;i++){
        if(a[i]>maxn) maxn = a[i];
        if(b[i]==a[i]&&a[i]>=maxn){
            res.push_back(b[i]);
        }
    } 
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();i++){
        if(i!=0) cout<<" ";
        cout<<res[i];
    }
    cout<<endl;
    return 0;
}