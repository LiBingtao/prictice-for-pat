#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct Student{
    int ts,id;
    vector<int> ps;
    int manfen;
    bool hassubmitted;
};
bool cmp(Student a,Student b){
    if(a.ts!=b.ts) return a.ts>b.ts;
    else if(a.manfen!=b.manfen) return a.manfen>b.manfen;
    else return a.id<b.id;
}
Student students[10010];
int main(){
    int n,k,m;
    int sta[6];
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++){
        students[i].ps.resize(k+1,-2);
    }
    for(int i=1;i<=k;i++){
        cin>>sta[i];
    }
    for(int i=0;i<m;i++){
        int id,which,score;
        cin>>id>>which>>score;
        students[id].id = id;
        if(students[id].ps[which]<score){
            if(score == -1&&students[id].ps[which]==-2){
                students[id].ps[which] = 0;
                continue;
            }
            if(students[id].ps[which]>0) students[id].ts = students[id].ts - students[id].ps[which] + score;
            else students[id].ts += score;
            students[id].hassubmitted = true;
            if(score == sta[which]){
                students[id].manfen++;
            }
            students[id].ps[which]=score;
        }
    }
    sort(students+1,students+n+1,cmp);
    int rank = 1;
    if(students[1].hassubmitted){
        printf("%d %05d %d", rank, students[1].id, students[1].ts);
        for(int j=1;j<=k;j++){
            if(students[1].ps[j]>=-1) cout<<" "<<students[1].ps[j];
            else cout<<" "<<"-";
        }
        cout<<endl;
    }
    int cnt = 1;
    for(int i=2;i<=n;i++){
        if(students[i].ts==students[i-1].ts) {cnt++;}
        else {rank+=cnt;cnt=1;}
        if(students[i].hassubmitted){
            printf("%d %05d %d", rank, students[i].id, students[i].ts);
            for(int j=1;j<=k;j++){
                if(students[i].ps[j]>=-1) cout<<" "<<students[i].ps[j];
                else cout<<" "<<"-";
            }
            cout<<endl;
        }
    }
    return 0;
}