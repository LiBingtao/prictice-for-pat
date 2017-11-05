#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool isprime(int n){
	if(n <= 1) return false;
	for(int i=2;i*i<=n;i++){
		if(n%i == 0){
			return false;
		}
	}	
	return true;
}
int main(){
	int N, D;
	vector<int> v;
	while(cin>>N && N>=0){
		cin>>D;
		if(!isprime(N)) {
			printf("No\n");
			continue;
		}
		while(N){
			v.push_back(N%D);
			N = N/D;
		}
		reverse(v.begin(),v.end());
		int M = 0;
		while(!v.empty()){
			int a = v.back();
			M = D*M + a;
			v.pop_back();
		}
		if(isprime(M)){
			cout<<"Yes"<<endl;
		}
		else cout<<"No"<<endl;
	}
}
