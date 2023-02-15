#include "utils.hpp"

#include <iostream>

// a declaration for our function template (we don't need the definition any more)
template <typename T>
T mymax(T x, T y);

template<>
int mymax<int>(int x, int y) // the generated function mymax<int>(int, int)
{
    return (x > y) ? x : y;
}

int main()
{
    std::cout << mymax<int>(1, 2) << '\n'; // instantiates and calls function mymax<int>(int, int)

    return 0;
}