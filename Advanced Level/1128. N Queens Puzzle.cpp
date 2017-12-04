#include<iostream>
#include<vector>
#include<set>
using namespace std;
vector<int> s,a,b;
int main(){
    int k,n,temp;
    cin>>k;
    for(int i=0;i<k;i++){
        int flag = 0;
        cin>>n;
        s.clear();
        s.resize(n+1,0);
        a.clear();
        a.resize(n*2,0);
        b.clear();
        b.resize(n*2,0);
        for(int j=0;j<n;j++){
            cin>>temp;
            if(s[temp]==0 && a[temp+j]==0 && b[temp+j]==0){
                s[temp] = 1;
                a[temp+j]=1;
                b[temp+j]=1;
            }else{
                flag = 1;
            }
        }
        if(flag) cout<<"NO";
        else cout<<"YES";
        cout<<endl;
    }
    return 0;
}