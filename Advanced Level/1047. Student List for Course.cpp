#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
char name[40010][5];
bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main(){
    int n,k;
    vector<int> corse[2510];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int cnt;
        scanf("%s %d",name[i],&cnt);
        for(int j=0;j<cnt;j++){
            int id;
            scanf("%d",&id);
            corse[id].push_back(i);
        }
    }
    for(int i=1;i<=k;i++){
        sort(corse[i].begin(),corse[i].end(),cmp1);
        printf("%d %lu\n",i,corse[i].size());
        for(int j=0;j<corse[i].size();j++){
            printf("%s\n",name[corse[i][j]]);
        }
    }
    return 0;
}