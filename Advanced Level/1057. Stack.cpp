#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    vector<int>q,t;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="Pop"){
            if(q.size()==0){
                cout<<"Invalid"<<endl;
            }else{
                cout<<q.back()<<endl;
                q.pop_back();
            }
        }else if(s=="Push"){
            int k;
            cin>>k;
            q.push_back(k);
        }else{
            if(q.size()==0){
                cout<<"Invalid"<<endl;
            }else{
                t = q;
                sort(t.begin(),t.end());
                cout<<t[(t.size()-1)/2]<<endl;
            } 
        }
    }
    return 0;
}