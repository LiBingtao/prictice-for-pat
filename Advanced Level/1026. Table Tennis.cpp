#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static int vip[101];
struct Table{
	int time;
	int served;
};
struct Custom{
	int atime,stime,wtime,ptime,vip;	
	bool served;
};
static Table table[101];
static Custom custom[10001];
bool cmp1(Custom a,Custom b){
	return a.atime<b.atime;
}
bool cmp2(Custom a,Custom b){
	return a.stime<b.stime;
}
int main(){
	int n,k,m;
	cin>>n;
	for(int i=0;i<n;i++){
		int h,mi,s,p;
		scanf("%d:%d:%d %d %d",&h,&mi,&s,&p,&custom[i].vip);
		custom[i].atime = h*3600 + mi*60 +s;
		custom[i].ptime = (p>120)?(120*60):(p*60);
	}
	cin>>k>>m;
	for(int i=0;i<k;i++){table[i].time = 28800;}
	for(int i=0;i<m;i++){
		int index;
		cin>>index;
		vip[index-1] = 1;
	}
	sort(custom,custom+n,cmp1);
	for (int i=0;i<n;i++){
		if(custom[i].atime>=21*3600){continue;}
		int flag=0,mintime=24*60*60;
		bool av = false;
		bool avv = false;
		if(custom[i].served){continue;}
		if(custom[i].vip==1){
			for(int ii=0;ii<k;ii++){
				if(vip[ii]==1&&custom[i].atime>=table[ii].time){
					flag = ii;
					av = true;
					avv = true;
					break;
				}
			}
			if(!avv){
				for(int ii=0;ii<k;ii++){
					if(custom[i].atime>=table[ii].time){
						flag = ii;
						av = true;
						break;
					}
				}
			}
		}else{
			for(int ii=0;ii<k;ii++){
				if(custom[i].atime>=table[ii].time){
					flag = ii;
					av = true;
					break;
				}
			}
		}
		if(!av){
			for(int j=0;j<k;j++){
				if(table[j].time<mintime){
					flag = j;
					mintime = table[j].time;
				}
			}
		}
		if(table[flag].time>=21*3600) break;
		if(av){
			custom[i].stime = custom[i].atime;
			table[flag].time = custom[i].atime+custom[i].ptime;
			custom[i].served=true;
		}
		if(!av){	
			if(vip[flag]==1){
				bool hasvip=false;
				for(int j=i;j<n;j++){
					if(custom[j].vip==1&&custom[j].served==false){
						custom[j].served = true;
						custom[j].wtime = table[flag].time-custom[j].atime;
						custom[j].stime = table[flag].time;
						table[flag].time+=custom[j].ptime;
						i-=1;
						hasvip = true;
						break;
					}	
				}
				if(!hasvip){
					custom[i].wtime = table[flag].time-custom[i].atime;
					custom[i].stime = table[flag].time;
					table[flag].time+=custom[i].ptime;
					custom[i].served=true;
				}
			}else{
				custom[i].wtime = table[flag].time-custom[i].atime;
				custom[i].stime = table[flag].time;
				table[flag].time+=custom[i].ptime;
				custom[i].served=true;
			}
		}
		table[flag].served += 1;
	}
	sort(custom,custom+n,cmp2);
	for(int i=0;i<n;i++){
		if(custom[i].served){
			printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",custom[i].atime/60/60,custom[i].atime/60%60,custom[i].atime%60,custom[i].stime/60/60,custom[i].stime/60%60,custom[i].stime%60,(custom[i].wtime+30)/60);	
		}
	}
	for(int i=0;i<k-1;i++){
		cout<<table[i].served<<" ";
	}
	cout<<table[k-1].served<<endl;
	return 0;
}
