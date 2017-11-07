#include<iostream>
#include<vector>
using namespace std;
static vector<int> post, in, level(100000, -1);
void pre(int root,int start,int end,int index){
	if (start>end) return;
	int i = start;
	for (; in[i] != post[root]; i++){}
	level[index] = post[root];
	pre(root - 1 + i - end, start, i - 1, index * 2 + 1);
	pre(root - 1, i + 1, end, index * 2 + 2);
}
int main(){
	int n,cnt=1;
    scanf("%d", &n);
    post.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i++) scanf("%d", &in[i]);
	pre(post.size()-1,0,post.size()-1,0);
	cout << level[0];
	for (int i=1;i<level.size();i++){
		if(level[i]!=-1&&cnt<n){
			cout<<" "<<level[i];
			cnt++;
		}
		if(cnt==n)break;
	}
	cout << endl;
	return 0;
}
