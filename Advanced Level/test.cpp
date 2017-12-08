#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int main(){
    string a = "123456";
    int b;
    string c;
    sscanf(a,"%d",b);
    sprintf(c,"%05d",b);
    return 0;
}