#include<iostream>
#include<string>
#include<cctype>
using namespace std;
int asc[256];
int main(){
    string a,b;
    cin>>a>>b;
    int i=0,j=0,t=0;
    char res[100];
    while(j<=b.length()){
        if(a[i]!=b[j]){
            res[t++] = a[i];
        }
        else{
            j++;
        }
        i++;
    }
    for(int k=i;k<a.length();k++){
        res[t++] = a[k];
    }
    for(int k=0;k<t;k++){
        res[k] = toupper(res[k]);
    }
    for(int k=0;k<t;k++){
        for(int m=0;m<k;m++){
            if(res[k]==res[m]){
                res[k] = '#';
            }
        }
    }
    for (int k = 0; k < t; k++) {
        if (res[k] != '#') cout << res[k];
    }
    return 0;
}