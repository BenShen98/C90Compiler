int main(){
  abi_setup();
  int x=f();
  if(x==4){
    return 0;
  } else if(x==0) {
      return -1;
  } else{
      return x;
  }
}
