#include<cstdio>
using namespace std;
int main(){
    int a,b,c,d,e,f;
    scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
    a += d;
    b += e;
    c += f;
    if(c>=29){
        c = c - 29;
        b += 1;
    }
    if(b>=17){
        b = b -17;
        a += 1;
    }
    printf("%d.%d.%d",a,b,c);
    return 0;
}