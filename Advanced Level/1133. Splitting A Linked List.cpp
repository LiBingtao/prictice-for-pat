#include<iostream>
#include<vector>
using namespace std;
struct node{
    int add,value,next;
};
vector<node> v1,v2,v3;
node list[100000];
int main(){
    int s,n,k;
    int a,b,c;
    cin>>s>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        list[a].add = a;
        list[a].value = b;
        list[a].next = c;
    }
    int index = s;
    while(index!=-1){
        if(list[index].value<0){
            v1.push_back(list[index]);
        }else if(list[index].value>k){
            v3.push_back(list[index]);
        }else{
            v2.push_back(list[index]);
        }
        index = list[index].next;
    }
    
    for(int i=0;i<v1.size();i++){
        if(i == v1.size()-1) {
            if(v2.size()>0) printf("%05d %d %05d\n",v1[i].add,v1[i].value,v2[0].add);
            else if(v3.size()>0) printf("%05d %d %05d\n",v1[i].add,v1[i].value,v3[0].add);
            else printf("%05d %d -1\n",v1[i].add,v1[i].value); 
        }
        else printf("%05d %d %05d\n",v1[i].add,v1[i].value,v1[i+1].add);
    }
    for(int i=0;i<v2.size();i++){
        if(i == v2.size()-1){
            if(v3.size()>0) printf("%05d %d %05d\n",v2[i].add,v2[i].value,v3[0].add); 
            else printf("%05d %d -1\n",v2[i].add,v2[i].value);  
        } 
        else printf("%05d %d %05d\n",v2[i].add,v2[i].value,v2[i+1].add);
    }
    for(int i=0;i<v3.size();i++){
        if(i == v3.size()-1) printf("%05d %d -1\n",v3[i].add,v3[i].value);
        else printf("%05d %d %05d\n",v3[i].add,v3[i].value,v3[i+1].add);
    }
    return 0;
}