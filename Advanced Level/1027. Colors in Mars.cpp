#include<iostream>
#include<map>
using namespace std;
int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	char r13[13];
	for(int i=0;i<=9;i++){
		r13[i] = char(i+'0');
	}
	for(int i=10;i<=12;i++){
		r13[i] = char(i-10+'A');	
	}
	cout<<"#"<<r13[a/13]<<r13[a%13];
	cout<<r13[b/13]<<r13[b%13];
	cout<<r13[c/13]<<r13[c%13];
	cout<<endl;
}
