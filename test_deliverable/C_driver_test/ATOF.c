double f();

int main(){
    abi_setup();
    double x=5.21;
    return f(x)!=x;
}