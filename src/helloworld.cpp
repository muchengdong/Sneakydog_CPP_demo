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
namespace Sneakydog_CPP_demo
{
    int add2(const int a, const int b)
    {
        return a + b;
    }

}
