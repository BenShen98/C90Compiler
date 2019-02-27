int foo(int x);

int main(){
    int x=5;
    int y;
    y=foo(x);
    return y-123;
}


int foo(int x){
    int y=123;
    return x+y;
}
