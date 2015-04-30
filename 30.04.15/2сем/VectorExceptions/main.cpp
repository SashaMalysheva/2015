#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "ArrExcps.h"

template <typename T>
class Array
{
private:
    T* data;
    size_t Size;
    size_t Capacity;
public:
    struct iterator
    {
        T* ptr;
        iterator (T* ptr = 0) : ptr(ptr) {}
        T& operator* ()
        {
            if (ptr == 0)
                throw nullPtr();
            return *ptr;
        }
        T* operator-> ()
        {
            if (ptr == 0)
                throw nullPtr();
            return ptr;
        }
        T* operator++ ()
        {
            if (ptr == 0)
                throw nullPtr();
            return ++ptr;
        }
        T* operator-- ()
        {
            if (ptr == 0)
                throw nullPtr();
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
        return data;
    }
    iterator end ()
    {
        return data + Size;
    }
    Array (const size_t& ArraySize)
    {
        int x = ArraySize;
        if (x <= 0)
            throw wrongSize();
        data = new T[ArraySize];
        Size = ArraySize;
        Capacity = ArraySize;
    }
    Array ()
    {
        data = new T;
        Size = 0;
        Capacity = 1;
    }
    ~Array ()
    {
        if (data == 0)
            throw nullPtr();
        delete [] data;
    }
    T& get(const size_t& index) const
    {
        if (index < 0 || index >= Size)
            throw wrongSize();
        return *(data + index);
    }
    T& operator[] (const size_t& index)
    {
        if (index < 0 || index >= Size)
            throw wrongSize();
        return *(data + index);
    }
    void pushBack(const T& elem)
    {
        if (Size < 0)
            throw wrongSize();
        if (Size >= Capacity)
        {
            if (Capacity < 0)
                throw wrongSize();
            Capacity = 2 * Size;
            if (data == 0)
                throw nullPtr();
            T* tmp = data;
            try
            {
                data = new T [Capacity];
            }
			catch (std::bad_alloc &data)
			{
				throw wrongSize();
			}
            for (int i = 0; i < Size; i++)
                *(data + i) = *(tmp + i);
            delete [] tmp;
        }
        *(data + Size) = elem;
        Size++;
    }
    size_t getSize() const
    {
        return Size;
    }
};

class BitPtr
{
public:
    char* byte;
    int bit;
    BitPtr(char* byte, const int& bit) : byte(byte), bit(bit)
    {
        if (byte == 0)
            throw nullPtr();
        if (bit < 0 || bit >= 8)
            throw wrongSize();
    };
    void operator= (const bool& value)
    {
        if (byte == 0)
            throw nullPtr();
        *byte ^= (-value ^ *byte) & (1 << (8 - bit - 1));
    }
    operator bool()
    {
        if (byte == 0)
            throw nullPtr();
        return *(byte) & (1 << (8 - bit - 1));
    }
};

template <>
class Array <bool>
{
private:
    char* data;
    size_t Size;
    size_t Capacity;
public:
    Array (const size_t& ArraySize)
    {
        int x = ArraySize;
        if (x <= 0)
            throw wrongSize();
        Capacity = ((ArraySize - 1) / 8 + 1) * 8;
        data = new char[Capacity / 8];
        Size = ArraySize;
    }
    Array ()
    {
        data = new char;
        Size = 0;
        Capacity = 8;
    }
    ~Array ()
    {
        if (data == 0)
            throw nullPtr();
        delete [] data;
    }
    bool get(const size_t& index) const
    {
        if (index < 0 || index >= Size)
            throw wrongSize();
        return *(data + index / 8) & (1 << (8 - index % 8 - 1));
    }
    BitPtr& operator[] (size_t index)
    {
        if (index < 0 || index >= Size)
            throw wrongSize();
        return *(new BitPtr(data + index / 8, index % 8));
    }
    void pushBack(const bool& value)
    {
        if (Size < 0)
            throw wrongSize();
        if (Size >= Capacity)
        {
            if (Capacity < 0)
                throw wrongSize();
            Capacity = 2 * Size;
            if (data == 0)
                throw nullPtr();
            char* tmp = data;
            try
            {
                data = new char [Capacity / 8];
            }
			catch (std::bad_alloc &data)
			{
				throw wrongSize();
			}
            for (size_t i = 0; i < Size / 8; i++)
                *(data + i) = *(tmp + i);
            delete [] tmp;
        }
        if (Size >= Capacity)
                throw unknownErr();
        *(data + Size / 8) ^= (-value ^ *(data + Size / 8)) & (1 << (8 - (Size % 8) - 1));
        Size++;
    }
    size_t getSize() const
    {
        return Size;
    }
};

#endif // ARRAY_H_INCLUDED
