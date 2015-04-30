#include "Deque.h"

using namespace std;

int main()
{
    Deque <int> b;
    for (size_t i = 0; i < 1e6; ++i)
    {
        int x = rand() % 1000000 + 9999999;
        b.pushFront(x % 10);
    }
    cout << b.getCapacity();
    return 0;
}
