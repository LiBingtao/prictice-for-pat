#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct stu{
	int id,score;
	string name;
};
bool cmp1(stu a,stu b){
	return a.id<b.id;
}
bool cmp2(stu a,stu b){
	return (a.name==b.name)?a.id<b.id:a.name<b.name;	
}
bool cmp3(stu a,stu b){
	return (a.score==b.score)?a.id<b.id:a.score<b.score;	
}
int main(){
	u_long n,c;
	cin>>n>>c;
	vector<stu> student(n);
	for(u_long i=0;i<n;i++){
		int a,d;
		string b;
		cin>>a>>b>>d;
		student[i].id = a;
		student[i].name = b;
		student[i].score = d;
	}
	if(c==1) sort(student.begin(),student.end(),cmp1);
	if(c==2) sort(student.begin(),student.end(),cmp2);
	if(c==3) sort(student.begin(),student.end(),cmp3);
	for(u_long i = 0; i < n; i++) {
        printf("%06d ", student[i].id);
		cout<<student[i].name<<" "<<student[i].score<<endl;
    }
    return 0;
}

