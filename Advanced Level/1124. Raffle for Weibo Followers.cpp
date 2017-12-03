#include<iostream>
#include<string>
#include<set>
using namespace std;
int main(){
    int m,n,s;
    cin>>m>>n>>s;
    string str[1001];
    set<string> has;
    for(int i=1;i<=m;i++){
        cin>>str[i];
    }
    if(s>m){
        printf("Keep going...");
    }
    else{
        int i=s;
        while(i<=m){
            if(has.find(str[i])==has.end()){
                cout<<str[i]<<endl;
                has.insert(str[i]);
                i+=n;
            }else{
                i++;
            }
        }
    }
    return 0;
}