#include <vector>
#include <algorithm>
#include <map>
#include <iostream>
using namespace std;
int main(){
    map< string,vector<int> > m;
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++){
        int corse,num;
        scanf("%d %d",&corse,&num);
        for(int j=0;j<num;j++){
            char name[5];
            scanf("%s",name);
            m[name].push_back(corse);
        }
    }
    for(int i=0;i<n;i++){
        char name[5];
        scanf("%s",name);
        sort(m[name].begin(),m[name].end());
        printf("%s %d",name,int(m[name].size()));
        for(int j=0;j<m[name].size();j++){
            printf(" %d",m[name][j]);
        }
        printf("\n");
    }
    return 0;
}