#include<iostream>
#include<algorithm>
using namespace std;
struct mooncake{
    double amounts,price,unit_price;
};
bool cmp(mooncake a,mooncake b){
    return a.unit_price>b.unit_price;
}
int main(){
    int n,d;
    double profit = 0;
    mooncake mooncakes[1010];
    cin>>n>>d;
    for(int i = 0;i<n;i++){
        cin>>mooncakes[i].amounts;
    }
    for(int i = 0;i<n;i++){
        cin>>mooncakes[i].price;
        mooncakes[i].unit_price = mooncakes[i].price/mooncakes[i].amounts;
    }
    sort(mooncakes,mooncakes+n,cmp);
    for(int i=0;d>0&&i<n;i++){
        if(d>mooncakes[i].amounts){
            d -= mooncakes[i].amounts;
            profit += mooncakes[i].price;
        }else{
            profit += d*mooncakes[i].price/mooncakes[i].amounts;
            d = 0;
        }
    }
    printf("%.2f\n",profit);
    return 0;
}