#include<iostream>
using namespace std;
long long gcd(long long int a,long long int b){
    if(b==0) return abs(a);
    else return gcd(b,a%b);
}
void out(long long int a,long long int b){
    long long int pre = a/b;
    a = a%b;
    long long int g = gcd(a,b);
    a = a/g;
    b = b/g;
    if(a<0){
        if(pre!=0)
            printf("(%lld %lld/%lld)",pre,-a,b);
        else
            printf("(%lld/%lld)",a,b); 
    }else if(a==0){
        if(pre<0)
            printf("(%lld)",pre);
        else
            printf("%lld",pre);
    }else{
        if(pre!=0)
            printf("%lld %lld/%lld",pre,a,b);
        else
            printf("%lld/%lld",a,b);  
    }
}
int main(){
    long long int a,b,c,d;
    scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
    long long int add1,add2,sub1,sub2,mul1,mul2,div1,div2;
    add1 = a*d+b*c;
    add2 = b*d;
    sub1 = a*d-b*c;
    sub2 = b*d;
    mul1 = a*c;
    mul2 = b*d;
    div1 = a*d;
    div2 = b*c;
    if(div2<0) {div1 = -1*div1;div2 = -1*div2;}
    out(a,b);printf(" + ");out(c,d);printf(" = ");out(add1,add2);printf("\n");
    out(a,b);printf(" - ");out(c,d);printf(" = ");out(sub1,sub2);printf("\n");
    out(a,b);printf(" * ");out(c,d);printf(" = ");out(mul1,mul2);printf("\n");
    if(c==0)
        {out(a,b);printf(" / ");out(c,d);printf(" = Inf\n");}
    else
        {out(a,b);printf(" / ");out(c,d);printf(" = ");out(div1,div2);printf("\n");}
    return 0;
}