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
	vector<vector<stu>> v;
	vector<stu> vt;
	int n;
	cin>>n;
	v.resize(n);
	for (int i=0;i<n;i++){
		int k;
		cin>>k;
		for (int j=0;j<k;j++){
			stu temp;
			scanf("%lld %d",&temp.id,&temp.grade);
			temp.local_id = i+1;
			v[i].push_back(temp);
		}
	}
	for (int i=0;i<n;i++){
		sort(v[i].begin(),v[i].end(),cmp);
		v[i][0].loca_rank = 1;
        vt.push_back(v[i][0]);
		for(u_long j=0;j<v[i].size();j++){
			v[j].loca_rank = (v[j].grade == v[j - 1].grade) ? (v[j - 1].loca_rank) : (j + 1);
			vt.push_back(v[i][j]);
		}
	}
	sort(vt.begin(),vt.end(),cmp);
	vt[0].rank = 1;
	for(u_long i=0;i<vt.size();i++){
		vt[i].rank = ((vt[i].grade == vt[i-1].grade)?(v[i-1].rank):(i+1));	
	}
	cout<<vt.size()<<endl;
	for(u_long i=0;i<vt.size();i++){
		printf("%13d %d %d %d\n",vt.id,vt.rank,vt.local_id,vt.local_rank);
	}
	return 0;
}
