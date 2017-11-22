#include<iostream>
#include<vector>
using namespace std;
vector<int> v[100010];
double lowestprice=999999999999.0,r,p;
int id,n;
void dfs(int root,double price){
    if(price>lowestprice) return;
    if(v[root].size()==0){
        if(price < lowestprice){
            lowestprice = price;
            id = 1;
        }else if(price == lowestprice){
            id++;
        }
        return;
    }
    for(int i=0;i<v[root].size();i++){
        dfs(v[root][i],price*(1+r/100));
    }
}
int main(){
    cin>>n>>p>>r;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        for(int j=0;j<num;j++){
            int t;
            cin>>t;
            v[i].push_back(t);
        }
    }
    dfs(0,p);
    printf("%.4lf %d\n",lowestprice,id);
    return 0;
}