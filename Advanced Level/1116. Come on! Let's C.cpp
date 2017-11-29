#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool isprime(int a){
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
int arr[10000];
int main(){
    int n,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        int id;
        cin>>id;
        arr[id] = i;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int id;
        cin>>id;
        if(arr[id]!=0){
            if(arr[id]==-1){
                printf("%04d: Checked\n",id);
            }else if(arr[id]==1){
                printf("%04d: Mystery Award\n",id);
                arr[id] = -1;
            }else if(isprime(arr[id])){
                printf("%04d: Minion\n",id);
                arr[id] = -1;
            }else{
                printf("%04d: Chocolate\n",id);
                arr[id] = -1;
            }
        }else{
            printf("%04d: Are you kidding?\n",id);
        }
    }
    return 0;
}