
int f1();
int f(){
    return f1()+f2();
}



int f1(){
    return 1;
}

int f2(){
    int x=5;
    return x;
}
