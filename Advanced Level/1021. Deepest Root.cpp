#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
static bool visit[10002];
static int e[10002][10002];
static vector<int> result;
static vector<int> temp;
static int maxheight = 0;
static int n;
static int flag[10002];
void dfs(int node,int height){
	if(maxheight<height){
		maxheight = height;
		temp.clear();
		temp.push_back(node);
	}else if(maxheight==height){
		temp.push_back(node);	
	}
	visit[node] = true;
	for(int i=1;i<n+1;i++){
		if(visit[i]==false&&e[node][i]==1)
		{
			dfs(i,height+1);
		}
	}
}
int main(){
	int cnt = 0;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		e[a][b] = 1;
		e[b][a] = 1;
	}
	fill(visit,visit+10002,false);
	for(int i=1;i<n+1;i++){
		if(visit[i]==false){
			dfs(i,1);
			cnt += 1;
		}	
	}
	if(cnt>=2)printf("Error: %d components\n", cnt);
	else{
		result = temp;
		for(u_long i=0;i<temp.size();i++){
			flag[temp[i]]=1;	
		}
		fill(visit,visit+10002,false);
		dfs(temp[0],1);
		for(u_long i=0;i<temp.size();i++){
			if(flag[temp[i]]==0){
				result.push_back(temp[i]);	
			}	
		}
		sort(result.begin(),result.end());
		for(u_long i=0;i<result.size();i++)
			cout<<result[i]<<endl;
	}
}
