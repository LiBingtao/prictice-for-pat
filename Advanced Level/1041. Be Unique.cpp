#include<iostream>
using namespace std;
int main(){
    int n;
    int lottery[10010],unique[10010];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>lottery[i];
        unique[lottery[i]] += 1;
    }
    int flag = 0, i = 0;
    for(;i<n;i++){
        if(unique[lottery[i]]==1){
            flag =1;
            break;
        }
    }
    if(flag==0){
        cout<<"None"<<endl;
    }else{
        cout<<lottery[i]<<endl;
    }
    return 0;
}