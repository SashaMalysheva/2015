#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

template <typename T>
class Deque
{
private:
    T* data;
    size_t Size;
    size_t CapFr;
    size_t CapEnd;
public:
    struct iterator
    {
        T* ptr;
        bool rev;
        iterator (T* ptr = 0, bool rev = false) : ptr(ptr), rev(rev) {}
        T& operator* ()
        {
            return *ptr;
        }
        T* operator-> ()
        {
            return ptr;
        }
        T* operator++ ()
        {
            if (rev)
                return --ptr;
            return ++ptr;
        }
        T* operator-- ()
        {
            if (rev)
                return ++ptr;
            return --ptr;
        }
        bool operator== (const iterator& other) const
        {
            return ptr == other.ptr;
        }
        bool operator!= (const iterator& other) const
        {
            return !(*this == other);
        }
    };
    iterator begin ()
    {
        iterator it(data + CapFr, false);
        return it;
    }
    iterator end ()
    {
        iterator it(data + CapFr + Size, false);
        return it;
    }
    iterator rbegin ()
    {
        iterator it(data + CapFr + Size - 1, true);
        return it;
    }
    iterator rend ()
    {
        iterator it(data + CapFr - 1, true);
        return it;
    }
    Deque (const size_t& DequeSize)
    {
        data = new T[DequeSize];
        Size = DequeSize;
        CapFr = CapEnd = 0;
    }
    Deque ()
    {
        data = new T[2];
        Size = 0;
        CapFr = 1;
        CapEnd = 1;
    }
    ~Deque ()
    {
        delete [] data;
    }
    T& get(const size_t& index) const
    {
        return *(data + CapFr + index);
    }
    T& operator[] (const size_t& index)
    {
        return *(data + CapFr + index);
    }
    void pushFront(const T& elem)
    {
        if (CapFr == 0)
        {
            T* tmp = data;
            data = new T [Size * 3];
            CapFr = Size;
            CapEnd = Size;
            for (int i = 0; i < Size; i++)
                *(data + CapFr + i) = *(tmp + i);
            delete [] tmp;
        }
        *(data + CapFr - 1) = elem;
        Size++;
        CapFr--;
        return;
    }
    T& popFront(const T& elem)
    {
        Size--;
        CapFr++;
        return *(data + CapFr - 1);
    }
    void pushBack(const T& elem)
    {
        if (CapEnd == 0)
        {
            T* tmp = data;
            data = new T [Size * 3];
            for (int i = 0; i < Size; i++)
                *(data + Size + i) = *(tmp + CapFr + i);
            CapFr = Size;
            CapEnd = Size;
            delete [] tmp;
        }
        *(data + CapFr + Size) = elem;
        Size++;
        CapEnd--;
        return;
    }
    T& popBack(const T& elem)
    {
        Size--;
        CapEnd++;
        return *(data + CapFr + Size);
    }
    size_t getSize() const
    {
        return Size;
    }
    size_t getCapacity() const
    {
        return Size + CapFr + CapEnd;
    }
};

#endif // DEQUE_H_INCLUDED
