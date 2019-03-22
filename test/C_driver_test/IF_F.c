int testif_f();
int main(){
  abi_setup();
  if(testif_f()==6){
    return 0;
  }
  return 1;
}
