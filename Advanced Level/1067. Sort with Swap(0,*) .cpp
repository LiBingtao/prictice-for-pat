#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,index=1,cnt=0,ans=0;
    int p[100100];
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        p[num] = i;
        if(num!=0&&num!=i){
            cnt++;
        }
    }
    while(cnt>0){
        if(p[0]==0){
            while(index<n&&p[index]==index){
                if(p[index]!=index){
                    swap(p[0],p[index]);
                    ans++;
                    break;
                }
                index++;
            }
        }
        while(p[0]!=0){
            swap(p[0],p[p[0]]);
            cnt--;
            ans++;
        }
    }
    cout<<ans<<endl;
}