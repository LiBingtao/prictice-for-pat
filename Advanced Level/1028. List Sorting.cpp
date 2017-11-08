#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
struct stu{
	int id,score;
	char name[10];
};
bool cmp1(stu a,stu b){
	return a.id<b.id;
}
bool cmp2(stu a,stu b){
	return (strcmp(a.name,b.name)==0)?a.id<b.id:strcmp(a.name, b.name) < 0;	
}
bool cmp3(stu a,stu b){
	return (a.score==b.score)?a.id<b.id:a.score<b.score;	
}
int main(){
	u_long n,c;
	cin>>n>>c;
	vector<stu> student(n);
	for(u_long i=0;i<n;i++){
		scanf("%d %s %d", &student[i].id, student[i].name, &student[i].score);
	}
	if(c==1) sort(student.begin(),student.end(),cmp1);
	if(c==2) sort(student.begin(),student.end(),cmp2);
	if(c==3) sort(student.begin(),student.end(),cmp3);
	for(u_long i = 0; i < n; i++) {
		printf("%06d %s %d\n", student[i].id, student[i].name, student[i].score);
    }
    return 0;
}

