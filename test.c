int f(){
    int *b,a[3];
    b=&a[0];
    a[2]=5;

    return b[2];
}
