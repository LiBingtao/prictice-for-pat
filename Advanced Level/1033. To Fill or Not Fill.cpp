#include<iostream>
#include<algorithm>
using namespace std;
struct station{
    double price;
    double dis;
    double distance;
};
bool cmp(station a,station b){
    return a.distance<b.distance;
}
int main(){
    double c,d,da;
    int n;
    double price = 0;
    double gas = 0, td = 0;
    cin>>c>>d>>da>>n;
    station sta[510];
    for(int i=0;i<n;i++){
       cin>>sta[i].price>>sta[i].distance; 
    }
    sta[n].price = 0.0;
    sta[n].distance = d;
    sort(sta,sta+n,cmp);
    if(sta[0].distance != 0) {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    for(int i=n;i>0;i--){
        sta[i-1].dis = sta[i].distance - sta[i-1].distance;
    }
    int i = 0, flag = 0;
    while(i<n){
        if(sta[i].dis>c*da){
            printf("The maximum travel distance = %.2f\n",sta[i].distance + c*da);
            flag = 1;
            break;
        }
        int u = -1;
        for(int j=i+1;j<=n;j++){
            if(sta[i].price>sta[j].price){
                u = j;
                break;
            }
        }
        if(sta[u].distance - sta[i].distance > c*da){
            price += (c - gas)*sta[i].price;
            gas = c - sta[i].dis/da; 
            i++;
        }else{
            if(gas>=(sta[u].distance - sta[i].distance)/da){
                gas = gas - (sta[u].distance - sta[i].distance)/da;
                i = u;
            }else{
                price += ((sta[u].distance - sta[i].distance)/da - gas)*sta[i].price; 
                gas = 0;
                i = u; 
            }
        }
    }
    if(flag == 0){
        printf("%.2f\n",price);
    }
    return 0;
}