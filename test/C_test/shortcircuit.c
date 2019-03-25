int f1(){
    int x;
    return ((  ++x || 6 )<<2)+x;
}

int f2(){
    int x;
    return ((   6 || ++x )<<2)+x;;
}


int f3(){
    int x=1;
    return ((  ++x && 0 )<<2)+x;
}

int f4(){
    int x=1;
    return ((   0 && ++x )<<2)+x;;
}