#include <stdio.h>

int a=5;

int foo(){
    a=a*a;
    printf("foo\n");
    return a;
}

int boo(){
    a=a+1;
    printf("boo\n");
    return a;
}

int f(int x, int y){
    printf("f");
    return x+y;
}

int main()
{
    int y=f( foo(), boo() );
    
    printf("%i",y);

    return 0;
}

