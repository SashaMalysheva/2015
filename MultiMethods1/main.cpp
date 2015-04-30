#include <iostream>
#include <vector>

using namespace std;
struct A;
struct B;
struct IDispatcher
{
    virtual bool visitA(A* a) = 0;
    virtual bool visitB(B* b) = 0;
};

struct IShape
{
    virtual bool visit(IDispatcher* visitor) = 0;
};

struct A : IShape
{
    virtual bool visit(IDispatcher* visitor)
    {
        return visitor->visitA(this);
    }
};
struct B : IShape
{
    virtual bool visit(IDispatcher* visitor)
    {
        return visitor->visitB(this);
    }
};

bool RealIntersect(A*)
{
    cout<<"a"<< endl;
    return true;
}

bool RealIntersect(B*)
{
    cout<<"b"<< endl;
    return true;
}

bool RealIntersect(A*, B*)
{
    cout<<"a, b"<< endl;
    return true;
}

bool RealIntersect(B*, A*)
{
    cout<<"b, a"<< endl;
    return true;
}

bool RealIntersect(A*, A*)
{
    cout<<"a, a"<< endl;
    return true;
}

bool RealIntersect(B*, B*)
{
    cout<<"b, b"<< endl;
    return true;
}

bool RealIntersect(B*, B*, B*)
{
    cout<<"b, b, b"<< endl;
    return true;
}


bool RealIntersect(B*, B*, A*)
{
    cout<<"b, b, a"<< endl;
    return true;
}

bool RealIntersect(B*, A*, A*)
{
    cout<<"b, a, a"<< endl;
    return true;
}

bool RealIntersect(B*, A*, B*)
{
    cout<<"b, a, b"<< endl;
    return true;
}

bool RealIntersect(A*, B*, B*)
{
    cout<<"a, b, b"<< endl;
    return true;
}


bool RealIntersect(A*, B*, A*)
{
    cout<<"a, b, a"<< endl;
    return true;
}

bool RealIntersect(A*, A*, B*)
{
    cout<<"a, a, b"<< endl;
    return true;
}

bool RealIntersect(A*, A*, A*)
{
    cout<<"a, a, a"<< endl;
    return true;
}


template<int Arity>
struct FirstStep;

template<typename Shape1, int Arity>
struct SecondStep;

template<typename Shape1, typename Shape2, int Arity>
struct ThirdStep;


template<typename Step>
struct Dispatcher : IDispatcher
{
    Step step;
    virtual bool visitA(A* a)
    {
        return step.Process(a);
    }
    virtual bool visitB(B* b)
    {
        return step.Process(b);
    }
};

template<int Arity>
struct FirstStep
{
    vector<IShape*> unknown;
    template<typename Shape1>
    bool Process(Shape1* shape1)
    {
        Dispatcher<SecondStep<Shape1, Arity> > dsp;
        dsp.step.shape1 = shape1;
        for(int i = 1; i < Arity; i++)
            dsp.step.unknown.push_back(unknown[i]);
        return dsp.step.unknown[0]->visit(&dsp);
    }
};

template<>
struct FirstStep<1>
{
    vector<IShape*> unknown;
    template<typename Shape1>
    bool Process(Shape1* shape1)
    {
        return RealIntersect(shape1);
    }
};

template<typename Shape1, int Arity>
struct SecondStep
{
    Shape1* shape1;
    vector<IShape*> unknown;
    template<typename Shape2>
    bool Process(Shape2* shape2)
    {
        Dispatcher<ThirdStep<Shape1, Shape2, Arity>> dsp;
        dsp.step.shape1 = shape1;
        dsp.step.shape2 = shape2;
        for(int i = 1; i < Arity - 1; i++)
            dsp.step.unknown.push_back(unknown[i]);
        return dsp.step.unknown[0]->visit(&dsp);
    }
};

template<typename Shape1>
struct SecondStep<Shape1, 2>
{
    Shape1* shape1;
    vector<IShape*> unknown;
    template<typename Shape2>
    bool Process(Shape2* shape2)
    {
        return RealIntersect(shape1, shape2);
    }
};

template<typename Shape1, typename Shape2>
struct ThirdStep<Shape1, Shape2, 3>
{
    Shape1* shape1;
    Shape2* shape2;
    vector<IShape*> unknown;
    template<typename Shape3>
    bool Process(Shape3* shape3)
    {
        return RealIntersect(shape1, shape2, shape3);
    }
};

bool Intersect(IShape* shape1)
{
    Dispatcher<FirstStep<1> > dsp;
    dsp.step.unknown.push_back(shape1);
    return dsp.step.unknown[0]->visit(&dsp);
};

bool Intersect(IShape* shape1, IShape* shape2)
{
    Dispatcher<FirstStep<2> > dsp;
    dsp.step.unknown.push_back(shape1);
    dsp.step.unknown.push_back(shape2);
    return dsp.step.unknown[0]->visit(&dsp);
};


bool Intersect(IShape* shape1, IShape* shape2, IShape* shape3)
{
    Dispatcher<FirstStep<3>> dsp;
    dsp.step.unknown.push_back(shape1);
    dsp.step.unknown.push_back(shape2);
    dsp.step.unknown.push_back(shape3);
    return dsp.step.unknown[0]->visit(&dsp);
};

int main()
{
    cout << "You are asked to cross:" << endl;
    A s1;
    B s2;
    A s3;
    Intersect(&s2, &s1);
    Intersect(&s1, &s2, &s3);
    Intersect(&s2);

    return 0;
}
