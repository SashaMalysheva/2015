#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <algorithm>
#include <string.h>

class elm//Аналог ошибок, выводит в консоль
{
    public:
        elm(const std::string &data)
        {
            std::cout << data << std::endl;
        }
};

template < class T >
class vector
{
    private:
        T* data;
        int _size;
        int _capacity;
    public:
        void push_back(T el)
        {
            if (_size == _capacity)
                resize(2 * _capacity);
            data[_size++] = el;
        }

        T pop_back()
        {
            if (_size == 0)
            {
                elm("Error: No elements!");
                return 0;
            }
            T el = data[--_size];
            if (_size <= _capacity / 4)
                resize(_capacity / 2);
            return el;
        }

        T operator[] (const int index) const
        {
            if (index < 0 || index >= _size)
            {
                elm("Error: index is out of range!");
                return 0;
            }
            return data[index];
        }

        void resize (int capacity1)
        {
            T* data1 = new T[capacity1];
            memcpy(data1, data, sizeof(T) * _size);
            std::swap(data1, data);
            _capacity = capacity1;
            delete [] data1;
        }

        int size()
        {
            return _size;
        }

        int capacity()
        {
            return _capacity;
        }

        vector() : _capacity(1), _size(0), data(new T[1]) {}

        vector(int capacity) : _capacity(capacity), _size(0), data(new T[capacity]) {}

        ~vector()
        {
            delete [] data;
        }
};

#endif // VECTOR_H_INCLUDE
