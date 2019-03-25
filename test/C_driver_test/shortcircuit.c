/* Checked is correct, gcc bug? */
int main(){
    if(f1()!=5)
        return 1;

    if(f2()!=4)
        return 2;

    if(f3()!=2)
        return 3;

    if(f4()!=1)
        return 4;

    return 0;
}