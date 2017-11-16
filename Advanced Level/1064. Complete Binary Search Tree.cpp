#include<iostream>
#include<algorithm>
#include<cmath>
#define min(a,b) ((a<b)?(a):(b))
using namespace std;
int n;
int arr[1010];
int level[1010];
void getlevel(int left,int right,int index){
    if(left>right) return;
    int num = right-left+1;
    int depth = log(num+1)/log(2);
    int leave = num - pow(2,depth) + 1;
    int root = left + pow(2,depth-1) - 1 + min(pow(2,depth-1),leave);
    level[index] = arr[root];
    getlevel(left,root-1,index*2+1);
    getlevel(root+1,right,index*2+2);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    getlevel(0,n-1,0);
    cout<<level[0];
    for(int i=1;i<n;i++){
        cout<<" "<<level[i];
    }
    cout<<endl;
    return 0;
}