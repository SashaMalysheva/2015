#include <iostream>

using namespace std;

template<typename T1, typename T2>
class List {
    public:
        typedef T1 Head;
        typedef T2 Tail;
};
struct List_End{};


struct A {
    void foo(){
        cout<< "A is done! \n";
    }
};

struct B {
    void foo(){
        cout<< "B is done! \n";
    }
};

struct C::A {
    void foo(){
        cout<< "C is done! \n";
    }
};

template<typename List>
struct Inherit:List::Head, Inherit<typename List::Tail>
{
    typedef typename List::Head P;
    typedef Inherit<typename List::Tail> P2;

    void foo()
    {
        ((P*)this) -> foo();
        ((P2*)this) -> foo();
    }
};
template<> struct Inherit<List_End>{
    void foo(){};
};


int main()
{
    Inherit<List<A, List<B, List_End>>> b;
    b.foo();
    return 0;
}
