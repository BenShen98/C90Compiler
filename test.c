int f(){
    int x=0;
    if((++x>3) || (++x>3) || (++x>3) || (++x>3) || (++x>3) || (++x>3) || (++x>3) || (++x>3))
        return x;
    else
        return -1;
}
