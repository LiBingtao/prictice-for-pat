#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
struct student{
    int g,gp,gm,gf;
    char id[21];
};
student stu[10001];
int main(){
    for(int i=0;i<10001;i++){
        stu[i].gp = stu[i].gm = stu[i].gf=-1;
    }
    for(int i=0;i<10001;i++){
        char a[21];
        scanf("%s",a);
        strcpy(stu[i].id,a);
        printf("%s\n%s\n",stu[i].id,a);
    }
    return 0;
}