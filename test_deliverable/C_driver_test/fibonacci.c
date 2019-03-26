int Fibonacci(int);
int main(){
  abi_setup();

    int a[10]={0,1,1,2,3,5,8,13,21,34};

    int i=0;
    for( ; i<10; i++){
        if(Fibonacci(i)!=a[i]){
            return 1;
        }
    }

    return 0;

}
