#include <iostream>
#include <string>

int main()
{
    int x=3,y=0,z;
    z=(++y=x++); // y++ have no effect, is overriden by x
    std::cout<<x<<y<<z;//433
}

