#include<iostream>
#include<algorithm>
using namespace std;
long long arr[100010];
int main(){
    long long n,p;
    cin>>n>>p;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int maxn=-1,j=1;
    for(int i=0;i<n;i++){
        long long chengji = arr[i]*p; 
        if(chengji>=arr[n-1]){
            if(maxn<n-i) maxn=n-i;
            break;
        }else{
            while(chengji>=arr[j]) j++;
            if(j-i>maxn){
                maxn=j-i;
            }
        } 
    }
    cout<<maxn<<endl;
    return 0;
}