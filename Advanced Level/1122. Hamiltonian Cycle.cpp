
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
#include<iostream>
#include<vector>
using namespace std;
int e[201][201];
int n,m,k;
vector<int> temp;
bool visit[201];
bool iscy(){
    
    return true;   
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[a][b]=e[b][a]=1;
    }
    cin>>k;
    for(int i=0;i<k;i++){
        int num,flag = 0;
        cin>>num;
        temp.clear();
        temp.resize(num);
        fill(visit,visit+201,false);
        for(int j=0;j<num;j++){
            cin>>temp[j];
        }
        if(num!=n+1 || temp[0]!=temp[num-1]){
            flag = 1;
        }
        else{
            for(int j=0;j<num-1;j++){
                if(e[temp[j]][temp[j+1]]==0 || visit[temp[j]]){
                    flag=1;
                    break;
                }
                visit[temp[j]]=true;
            }
        }
        if(flag) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}