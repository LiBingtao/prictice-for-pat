#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct custom{
	int wait;
	int time;
};
bool cmp(custom a,custom b){
	return a.time<b.time;	
}
int main(){
	u_long n,k;
	cin>>n>>k;
	vector<custom> v(n);
	for(u_long i=0;i<n;i++){
		int a,b,c,d;
		scanf("%d:%d:%d %d",&a,&b,&c,&d);
		v[i].time = a*60*60+b*60+c;	
		if(d>60) {d = 60;}
		v[i].wait = d*60;
	}
	sort(v.begin(),v.end(),cmp);
	vector<int> queue(k,28800);
	double total = 0;
	int count = 0;
	for(u_long i =0;i<n;i++){
		if(v[i].time<=17*60*60){
			int wait = 0;
			sort(queue.begin(),queue.end());
			if (v[i].time<8*60*60){
				wait += 8*60*60 - v[i].time;
			}
			if (v[i].time>=60*60*8 && v[i].time<queue[0]) {wait += queue[0] - v[i].time;}
			queue[0]+=v[i].wait;
			total += wait;
			count++;
		}
	}
	if(count==0){printf("0.0");}
	else
		printf("%.1f",total/count/60);
	return 0;
}
