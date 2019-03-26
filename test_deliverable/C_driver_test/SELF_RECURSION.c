int recadd(int);
int main(){
  abi_setup();
  int f[20]={0,1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,};

  int i;

  for (i = 0; i < 20; i++) {
    if (f[i] != recadd(i))
      return i+1;
  }

  return 0;
}
