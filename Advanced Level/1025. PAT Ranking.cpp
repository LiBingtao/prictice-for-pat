#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct stu{
	long long id;
	int grade;
	int local_id;
	int local_rank;
	int rank;
};
bool cmp(stu a,stu b){
	return (a.grade==b.grade)? a.id<b.id : a.grade>b.grade;
}
int main(){
	vector<stu> vt;
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int k;
		cin>>k;
		vector<stu> v(k);
		for (int j=0;j<k;j++){
			scanf("%lld %d",&v[j].id,&v[j].grade);
			v[j].local_id = i+1;
		}
		sort(v.begin(),v.end(),cmp);
		v[0].local_rank = 1;
        	vt.push_back(v[0]);
		for(u_long j=0;j<v.size();j++){
			v[j].local_rank = (v[j].grade == v[j - 1].grade) ? (v[j - 1].local_rank) : (j + 1);
			vt.push_back(v[j]);
		}
	}
	sort(vt.begin(),vt.end(),cmp);
	vt[0].rank = 1;
	for(u_long i=0;i<vt.size();i++){
		vt[i].rank = ((vt[i].grade == vt[i-1].grade)?(vt[i-1].rank):(i+1));	
	}
	cout<<vt.size()<<endl;
	for(u_long i=0;i<vt.size();i++){
		printf("%13d %d %d %d\n",vt[i].id,vt[i].rank,vt[i].local_id,vt[i].local_rank);
	}
	return 0;
}
