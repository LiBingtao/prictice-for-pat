#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
#define lowbit(i) ((i)&(-i))
const int maxn=100010;
int c[maxn];
stack<int> q;
void update(int x,int v){
    for(int i=x;i<maxn;i+=lowbit(i)){
        c[i]+=v;
    }
}
int getsum(int x){
    int sum = 0;
    for(int i=x;i>0;i-=lowbit(i)){
        sum+=c[i];
    }
    return sum;
}
void PeekMedian() {
    int left = 1, right = maxn, mid, k = (q.size() + 1) / 2;
    while(left < right) {
        mid = (left + right) / 2;
        if(getsum(mid) >= k)
            right = mid;
        else
            left = mid + 1;
    }
    printf("%d\n", left);
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        char s[15];
        scanf("%s",s);
        if(s[1]=='o'){
            if(q.size()==0){
                cout<<"Invalid"<<endl;
            }else{
                cout<<q.top()<<endl;
                update(q.top(),-1);
                q.pop();
            }
        }else if(s[1]=='u'){
            int k;
            cin>>k;
            q.push(k);
            update(k,1);
        }else{
            if(q.size()==0){
                cout<<"Invalid"<<endl;
            }else{
                PeekMedian();
            } 
        }
    }
    return 0;
}