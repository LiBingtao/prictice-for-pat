#include <iostream>
#include <string>
#include<iostream>
using namespace std;
void GetMemory( char **p )
{
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*p<<endl;
}
int main(){
    char a[4] = "aaa";
    char *str = a;
    cout<<&a<<endl;
    cout<<&str<<endl;
    GetMemory( &str ); 
    // strcpy( str, "hello world" );
    // printf( str );
    return 0;
}