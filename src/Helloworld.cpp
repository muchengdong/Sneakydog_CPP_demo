#include <cmath>
#include <arrayfire.h>

extern "C" __declspec(dllexport) void print_af_info()
{
    af::info();
}

extern "C" __declspec(dllexport) int add(int a, int b)
{
    return a + b;
}


int main(){

    print_af_info();
    return 0;
}
