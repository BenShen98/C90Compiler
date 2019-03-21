
int recadd(int a){
    if(a<1){
        return 0;
    } else{
        return (a+recadd(a-1));
    }
}