#include<iostream>
using namespace std;

int main(){
	int n;
    cin>>n;
    int a[100000];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    int b[100000];
    int max = 0, res = 0, index = 0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=i+1;j<n;j++){
        	if(a[j]<a[i]){
            	cnt++;
            }
        }
        b[i]=cnt;
    }
    for(int i=0;i<n;i++){
     	if((b[i]-i)>max){
        	max = b[i] - i;
            index = i;
        }   
        res += b[i];
    }
    cout<<res-max<<" "<<index<<endl;
    return 0;
}
