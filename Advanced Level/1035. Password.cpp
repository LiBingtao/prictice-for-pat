#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string a,b;
        cin>>a>>b;
        int flag = 0;
        for (int j=0;j<b.length();j++){
            switch(b[j]){
                case '1' : b[j] = '@';flag=1;break;
                case '0' : b[j] = '%'; flag = 1; break;
                case 'l' : b[j] = 'L'; flag = 1; break;
                case 'O' : b[j] = 'o'; flag = 1; break;
            }
        }
        if(flag){
            string temp = a + ' ' + b;
            v.push_back(temp);
        }
    }
    if(v.size()==0){
        if(n==1){
            cout<<"There is 1 account and no account is modified"<<endl;
        }
        else{
            printf("There are %d accounts and no account is modified\n",n);
        }
    }
    else{
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<endl;
        }
    }
    return 0;
}