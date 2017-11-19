#include<iostream>
#include<algorithm>
using namespace std;
struct node{
    int key,next;
};
int main(){
    int f,n,k;
    node list[100010];
    cin>>f>>n>>k;
    int sum=1;
    for(int i=0;i<n;i++){
        int ad,key,ne;
        cin>>ad>>key>>ne;
        list[ad].key = key;
        list[ad].next = ne;
    }
    int res[100010];
    int i = 1,ad = f;
    while(list[ad].next!=-1){
        res[i] = ad;
        ad = list[ad].next;
        i++;
        sum++;
    }
    res[i]=ad;
    res[i+1]=-1;
    int time = sum/k;
    for(int j=1;j<=time;j++){
        reverse(res+k*(j-1)+1,res+k*j+1);
    }
    for(int i=1;i<sum;i++){
        printf("%05d %d %05d\n",res[i],list[res[i]].key,res[i+1]);
    }
    printf("%05d %d %d\n",res[sum],list[res[sum]].key,res[sum+1]);
    return 0;
}