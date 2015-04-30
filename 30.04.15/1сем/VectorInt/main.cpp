#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "vector.h"

vector < int > x;

int main()
{
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 8; ++i)
    {
        x.push_back(i);
        std::cout << "add " << i << std::endl;
        std::cout << x.size() << std::endl;
        std::cout << x.capacity() << std::endl;
        std::cout << x[i] << std::endl;
        std::cout << std::endl;
    }

    while (x.size() > 0)
    {
        std::cout << "del " << std::endl;
        std::cout << x.pop_back() << std::endl;
        std::cout << x.size() << std::endl;
        std::cout << x.capacity() << std::endl;
        std::cout << std::endl;
    }
    x.pop_back();
    std::cout << x[10] << std::endl;
    return 0;
}

