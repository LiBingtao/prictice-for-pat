#include<cstdio>
#include<vector>
#include<set>
using namespace std;
int main(){
    int n,m,k,temp,a,b;
    scanf("%d",&n);
    vector< set<int> > v(n);
    for (int i=0;i<n;i++){
        set<int> s;
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%d %d",&a,&b);
        int cnb = v[b-1].size();
        int cna = 0;
        for(auto it = v[a-1].begin();it!=v[a-1].end();it++){
            if(v[b-1].find(*it)==v[b-1].end()){
                cnb++;
            }
            else{
                cna++;
            }
        }
        double ans = (double)cna / cnb * 100;
        printf("%.1f%%\n", ans);
    }
    return 0;
}