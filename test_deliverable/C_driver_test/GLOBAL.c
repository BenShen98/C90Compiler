extern int x;
extern int y;
int main(){
  abi_setup();
  testglobal();
  return (x+y)!=17;
}
