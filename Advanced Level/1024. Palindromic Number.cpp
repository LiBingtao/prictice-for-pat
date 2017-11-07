#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static int num,k,cnk=0;
bool is_palindromic(int n){
	int m = 0;
	vector<int> sn;
	while(n){
		sn.push_back(n%10);
		n = n/10;
	}
	for(u_long i=0;i<sn.size();i++){
		m = m*10 + sn[i];
	}
	for(u_long i=0;i<sn.size()/2;i++){
		if(sn[i]!=sn[sn.size()-1-i]) {if(cnk<k) {num+=m;return false;} else return false; }	
	}
	return true;
}

int main(){
	cin>>num>>k;
	while(cnk<=k){
		if(is_palindromic(num)){
			break;	
		}
		cnk++;
	}
	cout<<num<<endl;
	cout<<(cnk>k?k:cnk)<<endl;
	return 0;
}
