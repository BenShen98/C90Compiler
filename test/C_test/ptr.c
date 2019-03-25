int f(){
    int a=5;
    int *b;
    int c;

    b=&a;

    *b=10;

    return *b;
}
