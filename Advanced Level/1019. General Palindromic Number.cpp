#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool is_equal(vector<int> a,vector<int>b,int size){
	for(int i=0;i<size;i++){
		if(a[i]!=b[i]) return false;	
	}
	return true;
}
int main(){
	int n,b;
	cin>>n>>b;
	if(n==0) {cout<<"Yes"<<endl<<0<<endl;return 0;}
	vector<int> b_base,rb_base;
	while(n){
		b_base.push_back(n%b);
		n = n/b;
	}
	rb_base = b_base;
	int size = b_base.size();
	reverse(rb_base.begin(),rb_base.end());
	bool result = is_equal(b_base,rb_base,size);
	if(result){
		cout<<"Yes"<<endl;	
	}
	else cout<<"No"<<endl;
	for(int i=size-1;i>0;i--){
		cout<<b_base[i]<<" ";
	}
	cout<<b_base[0]<<endl;
	return 0;
}	
