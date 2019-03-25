<<<<<<< HEAD
int main()
{
        int n=4,m=3;
        n++;
    int a[n][m]+=5;
=======
/* Check is correct, gcc bug? */
int f1(){
    int x;
    return ((  ++x || 6 )<<2)+x;
}

int f2(){
    int x;
    return ((   6 || ++x )<<2)+x;
}


int f3(){
    int x=1;
    return ((  ++x && 0 )<<2)+x;
}

int f4(){
    int x=1;
    return ((  0 && ++x )<<2)+x;
}
>>>>>>> ast2mips

/* Check is correct, gcc bug? */
int main(){
    int a,b,c,d;
    a=f1();
    b=f2();
    c=f3();
    d=f4();
    if(a==5 && b==4 && c==2 && d==1){
        return 0;
    }else{
        return 1;
    }
}
