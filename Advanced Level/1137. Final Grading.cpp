#include<iostream>
#include<algorithm>
#include<map>
#include<string.h>
using namespace std;
struct student{
    int g,gp,gm,gf;
    char id[21];
};
student stu[10001];
map<string,int> fid;
bool cmp(student a,student b){
    if(a.g!=b.g) return a.g>b.g;
    else return strcmp(a.id,b.id)<0;
}
int main(){
    for(int i=0;i<10001;i++){
        stu[i].gp = stu[i].gm = stu[i].gf=-1;
    }
    int cnt=0;
    int p,m,n;
    cin>>p>>m>>n;
    char a[21];
    for(int i=0;i<p;i++){
        int b;
        scanf("%s %d",a,&b);
        if(b>=200){
            fid[a] = cnt;
            strcpy(stu[fid[a]].id,a);
            stu[fid[a]].gp = b;
            cnt++;
        }
    }
    for(int i=0;i<m;i++){
        int b;
        scanf("%s %d",a,&b); 
        if(fid.find(a)!=fid.end()){
            stu[fid[a]].gm = b;
        } 
    }
    for(int i=0;i<n;i++){
        int b;
        scanf("%s %d",a,&b);
        if(fid.find(a)!=fid.end()){
            stu[fid[a]].gf = b;
        }
    }
    for(int i=0;i<cnt;i++){
        int x = (stu[i].gm>0)?stu[i].gm:0;
        int y = (stu[i].gf>0)?stu[i].gf:0; 
        stu[i].g = (x>y)?int(0.4*x+0.6*y+0.5):y;
    }
    sort(stu,stu+cnt,cmp);
    for(int i=0;i<cnt;i++){
        if(stu[i].g<60) break;
        printf("%s %d %d %d %d\n",stu[i].id,stu[i].gp,stu[i].gm,stu[i].gf,stu[i].g);
    }
    return 0;
}