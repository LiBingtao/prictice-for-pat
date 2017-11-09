#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cin>>str;
	int n = str.length();
	int n1,n2=3;
	n1 = (n+2-n2)/2;
	while(n1>n2){
		n2++;
		n1 = (n+2-n2)/2;
	}
	int i=0;
	for(;i<n1-1;i++){
		cout<<str[i];
		for(int j=0;j<n2-2;j++){
			cout<<" ";	
		}
		cout<<str[n-1-i]<<endl;
	}
	for(int k=i;k<i+n2;k++){
		cout<<str[k];	
	}
	cout<<endl;
	return 0;
}
