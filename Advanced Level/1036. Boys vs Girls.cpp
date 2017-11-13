#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct stu{
    string name,gender,ID;
    int grade;
};
bool cmpM(stu a,stu b){
    return a.grade<b.grade; 
}
bool cmpF(stu a,stu b){
    return a.grade>b.grade; 
}
int main(){
    int n;
    vector<stu> male,famale;
    cin>>n;
    for (int i=0;i<n;i++){
        stu temp;
        cin>>temp.name>>temp.gender>>temp.ID>>temp.grade;
        if(temp.gender == "M")  male.push_back(temp);
        else famale.push_back(temp);
    }
    sort(male.begin(),male.end(),cmpM);
    sort(famale.begin(),famale.end(),cmpF);
    if(male.size()==0){
        if(famale.size()==0){
            cout<<"Absent"<<endl<<"Absent"<<endl<<"NA"<<endl;
        }else{
            cout<<famale[0].name<<" "<<famale[0].ID<<endl<<"Absent"<<endl<<"NA"<<endl;
        }
    }else if(famale.size()==0){
        cout<<"Absent"<<endl<<male[0].name<<" "<<male[0].ID<<endl<<"NA"<<endl;
    }else{
        cout<<famale[0].name<<" "<<famale[0].ID<<endl<<male[0].name<<" "<<male[0].ID<<endl<<(famale[0].grade - male[0].grade)<<endl;
    }
    return 0;
}