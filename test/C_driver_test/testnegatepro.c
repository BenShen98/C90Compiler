int testnegatepro();
int main(){
  abi_setup();
  return !(testnegatepro()==0xfffffff1);
}
