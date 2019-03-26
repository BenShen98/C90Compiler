int testif_t();
int main(){
  abi_setup();
  if(testif_t()==21){
    return 0;
  }
  return 1;
}
