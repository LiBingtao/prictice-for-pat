#include<cstdio>
#include<vector>
using namespace std;
vector<int> prime(500000,1);
int main(){
    long int a;
    scanf("%ld",&a);
    printf("%ld=",a);
    if(a==1){
        printf("%ld",a);
    }else{
        for(int i=2;i*i<50000;i++){
            for(int j=2;i*j<50000;j++){
                prime[i*j] = 0;
            }
        }   
        bool state = false;
        for(int i=2;a>=2;i++){
            int cnt = 0,flag = 0;
            while(a%i==0){
                cnt++;
                a = a/i;
                flag=1;
            }
            if(flag){
                if(state) printf("*");
                printf("%d",i);
                if(cnt>=2) printf("^%d",cnt);
                state = true;
            }
        }
    }
    printf("\n");
    return 0;
}