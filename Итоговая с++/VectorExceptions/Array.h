#include <iostream>
#include <new>

template<typename T>
	class  my_vector {
	private:
		T* my_array;
		size_t my_capacity;
		size_t my_size;

	void delete_array(T* &array1, size_t end1)
	{
        for (int i = 0; i < end1; ++i)
        {
            (array1 + i)->~T();
        }
        delete[] (char*)array1;
        array1 = NULL;
	}

	public:
		my_vector() : my_size(0), my_capacity(4)
		{
			my_array = (T*) (new char[my_capacity * sizeof(T)]);
		}

		~my_vector()
		{
			delete_array(my_array, my_size);
		}

		size_t size() const
		{
			return my_size;
		}

		size_t capacity() const
		{
			return my_capacity;
		}

		void push_back(const T &a)
		{
			if (my_size < my_capacity)
            {
				new(my_array + my_size) T(a);
				++my_size;
			}
			else
            {
				T*  tmp = (T*)(new char[2 * my_capacity * sizeof(T)]);
				size_t i = 0;

				try
				{
					for (; i != my_size; ++i)
                    {
						new (tmp + i) T(*(my_array + i));
					}

					new (tmp + i) T(a);

					++my_size;
					my_capacity *= 2;

					delete_array(my_array, my_size);
					my_array = tmp;
				}
				catch ( ... )
				{
					(tmp, i);delete_array
					throw;
				}
			}
		}

		T& operator[](size_t i) const
		{
			return my_array[i];
		}
	};
