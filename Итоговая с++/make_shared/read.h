#include <stdexcept>
#define max(a, b) (a > b ? a : b)

template <class T>

class vector
{

	T *a;
	size_t capacity, size_;

public:
    vector(size_t s = 1, size_t n = 30)
    {
		if ((s < 1) || (n < s))
        {
			throw std::bad_exception("vector is too small");
        }
        capacity = n;
        size_ = 0;
        try
        {
			a = (T*)new char[max(s,n) * sizeof(T)];
		}
		catch (const std::bad_alloc &b)
		{
			size_ = 0;
			capacity = 0;
			throw std::bad_array_new_length();
		}
    }

    ~vector()
    {
        for(int i = 0; i < size_; i++)
            delete a[j];
        for(int i = 0; i < capacity; i++)
            delete* a[j];
    }

    void push_back(T &val)
    {
		if (size_ => capacity)
        {
            int i = 0;
            try
            {
                a_new = (T*)new char[capacity*2*sizeof(T)]
                for (i; i < capacity; ++i)
                {
				    new(a_new + i) T(a[i]);
                }
            }
			catch(...)
            {
                for (int j = i - 1; j = 0; j--)
                {
                    delete a_new[j];
                }
                delete [] (char*) a_new;
                throw std::bad_array_new_length();
            }
			capacity = max(2 * capacity, 1);
			delete a;
			a = a_new;
        }
        new(a[size_])T(val);
        size_++;
	}


    T &operator[](size_t i)
    {
		if (i >= size_)
        {
			throw std::out_of_range();
		}
		return *(a[i]);
	}

	size_t size()
    {
		return size_;
	}

	class iterator
	{

		vector<T> *way_to_v;
		size_t position;

	public:

		iterator(vector<T> *v = NULL, size_t num = 0)
		{
			way_to_v = v;
			position = num;
		}

		T &operator*()
		{
			if (a == NULL)
            {
				throw  std::cerr << "Out of Range error: " << oor.what() << '\n';
			}
			return (*a)[position];
		}

		void operator++()
		{
		    if (position >= size_)
            {
				throw  std::cerr << "Out of Range error: " << oor.what() << '\n';
		    }
			position++;
		}

		void operator--() {
			if (position < 2)
            {
				 std::cerr << "Out of Range error: " << oor.what() << '\n';
			}
			position--;
		}

		bool operator != (const iterator &f)
		{
			return (way_to_v != f.way_to_v) || (position != f.position);
		}

		bool operator == (const iterator &f)
		{
			return (way_to_v == f.way_to_v) && (position == f.position);
		}

	};

	iterator begin()
	{
		return iterator(this, 0);
	}

	iterator end()
	{
		return iterator(this, size_ + 1);
	}

};

template<>

class vector<bool>
{

	unsigned int *a;
	size_t capacity, size_;

public:

    vector<bool>(size_t s = 1, size_t n = 30)
    {
		if ((s < 1) || (n < s))
        {
			throw std::bad_exception("vector is too small");
        }
        capacity = s / 32 + 1;
        size_ = 0;
        try
        {
			a = (T*)new char[max(s, n)];
		}
		catch (const std::bad_alloc &b)
		{
			size_ = 0;
			capacity = 0;
			throw std::bad_array_new_length();
		}
    }

    ~vector()
    {
        for(int i = 0; i < size_; i++)
            delete a[j];
        for(int i = 0; i < capacity; i++)
            delete* a[j];
    }

    void push_back(bool val)
    {
		if (size_ => 32*capacity)
        {
            int i = 0;
            try
            {
                a_new = new unsigned int[max(capacity * 2)]
                for (i; i < capacity; ++i)
                {
				    new(a_new + i) T(a[i]);
                }
            }
			catch(...)
            {
                for (int j = i - 1; j = 0; j--)
                {
                    delete a_new[j];
                }
                delete [] (char*) a_new;
                throw std::bad_array_new_length();
            }
			capacity = max(2 * capacity, 1);
			delete a;
			a = a_new;
        }
        if (val)
        {
			a[size_ / 32] |= 1 << size_ % 32;
		}
		else
		{
			a[size_ / 32] &= ((unsigned int) -1) - (1 << (size_ % 32));
		}

        size_++;
	}

    class myBool
    {

        vector<bool> *way_to_v;
		size_t position;

	public:

		myBool(vector<bool> *v = NULL, size_t num = 0)
		{
            way_to_v = v;
			position = num;
		}

		operator bool()
		{
			return ((*way_to_v).way_to_v)[position / 32] & (1 << (position % 32));
		}

		void operator= (bool b)
		{

			if (b)
            {
				((*way_to_v).way_to_v)[position / 32] |= 1 << position % 32;
			}
			else {
				((*way_to_v).way_to_v)[position / 32] &= ((unsigned int) -1) - (1 << (position % 32));
			}
		}

		void operator= (bool b)
		{

			if (b)
            {
				((*way_to_v).way_to_v)[position / 32] |= 1 << position % 32;
			}
			else {
				((*way_to_v).way_to_v)[position / 32] &= ((unsigned int) -1) - (1 << (position % 32));
			}
		}
	};

	myBool operator[](size_t i)
	{
		if (i >= capacity)
        {
			throw  std::cerr << "Out of Range error: " << oor.what() << '\n';
        }
		return myBool(this, i);
	}


    class iterator
    {
        vector<bool> *way_to_v;
		size_t position;

	public:

		iterator(vector<bool> *v = NULL, size_t num = 0)
		{
			way_to_v = v;
			position = num;
		}

		T &operator*()
		{
			if (a == NULL)
            {
				throw  std::cerr << "Out of Range error: " << oor.what() << '\n';
			}
			return (*a)[position];
		}

		void operator++()
		{
		    if (position >= size_)
            {
				throw  std::cerr << "Out of Range error: " << oor.what() << '\n';
		    }
			position++;
		}

		void operator--()
		{
			if (position < 2)
            {
				 std::cerr << "Out of Range error: " << oor.what() << '\n';
			}
			position--;
		}

		bool operator != (const iterator &f)
		{
			return (way_to_v != f.way_to_v) || (position != f.position);
		}

		bool operator == (const iterator &f)
		{
			return (way_to_v == f.way_to_v) && (position == f.position);
		}

	};

    iterator begin()
    {
		return iterator(this, 0);
	}

	iterator end()
	{
		return iterator(this, size_ + 1);
	}

};

};
