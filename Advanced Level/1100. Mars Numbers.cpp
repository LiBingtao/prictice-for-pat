#include<iostream>
#include<map>
#include<string>
using namespace std;
string etmg[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string etms[13] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int> mgte,mste;
int main(){
    for(int i=0;i<13;i++){
        mgte[etmg[i]] = i;
        if(i!=0){
            mste[etms[i-1]] = i;
        }
    }
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        string a;
        getline(cin,a);
        if(a[0]>='0'&&a[0]<='9'){
            int b=0,c=0;
            for(int j=0;j<a.length();j++){
                b = b*10+(a[j]-'0');
            }
            c = b%13;
            b = b/13;
            if(b>0){
                if(c>0) cout<<etms[b-1]<<" "<<etmg[c]<<endl;
                else cout<<etms[b-1]<<endl;
            }else{
                cout<<etmg[c]<<endl;
            }
        }else{
            if(a.length()>3){
                string b = a.substr(0,3);
                string c = a.substr(4,3);
                int f = mste[b];
                int l = mgte[c];
                int res = f*13+l;
                cout<<res<<endl;
            }else{
                int res;
                if(mgte.find(a)==mgte.end()) res = mste[a]*13;
                else res = mgte[a];
                cout<<res<<endl;
            }
        }
    }
    return 0;
}