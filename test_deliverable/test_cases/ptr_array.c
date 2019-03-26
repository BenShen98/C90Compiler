int f(){
    int a[5];
    int (*p)[5];

    p=&a;

    *(*p+1)=6;

    return *(*p+1);
}
