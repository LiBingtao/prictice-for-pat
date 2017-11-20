#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a[101],b[101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int flag = 0,i=2;
    for(;i<=n;i=i*2){
        for(int j=0;(j+1)*i<=n;j++){
            sort(a+j*i,a+i*(j+1));
        }
        sort(a+n/i*i,a+n);
        int k=0;
        for(;k<n;k++){
            if(a[k]!=b[k]){
                break;
            }
        }
        if(k==n) {flag=1;break;}
    }
    if(flag == 1){
        cout<<"Merge Sort"<<endl;
        i*=2;
        if(i>n){
            sort(a,a+n);
        }else{
            for(int j=0;(j+1)*i<=n;j++){
                sort(a+j*i,a+i*(j+1));
            }
            sort(a+n/i*i,a+n); 
        }
        
        for(int i=0;i<n;i++){
            if(i!=0)cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }else{
        cout<<"Insertion Sort"<<endl;
        for(int i=1;i<n;i++){
            if(b[i]<b[i-1]){
                sort(b,b+i+1);
                break;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=0)cout<<" ";
            cout<<b[i];
        }
        cout<<endl; 
    }
}