int f(){
    int a[3];
    int *b;
    b=&a;
    *(b+1)=5;


    return *(b+1);
}
