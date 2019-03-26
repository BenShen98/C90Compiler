int array2(int a, int b)
{
    int c[50] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                 11, 12, 13, 14, 15, 16};

    c[39] = a * b;
    return c[39] ;
}