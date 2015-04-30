#include "Array.h"

using namespace std;

int main()
{
    Array <int> b;
    int x = rand() % 1000000 + 9999999;
    for (size_t i = 0; i < 8; ++i)
    {
        cout << x % 10 << " ";
        b.pushBack(x % 10);
        x /= 10;
    }
    cout << endl;
    for (Array<int>::iterator i = b.begin(); i != b.end(); ++i)
        cout << *i << " ";
    return 0;
}
