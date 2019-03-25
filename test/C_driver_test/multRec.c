int main(){
    abi_setup();
    int f[20]={1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9, 9,10,11,11,12};
    int m[20]={0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 7, 8, 9, 9,10,11,11,12,};

    int i;

    for (i = 0; i < 20; i++)
        if(f[i]!=F(i))
            return 1;

    for (i = 0; i < 20; i++)
        if(m[i]!=M(i))
            return 1;

    return 0;
}