#include <iostream>

class error {
protected:
	std::string message;
public:
	error(std::string str) : message(str) {}
	void show() {
		std::cerr << message << "\n";
	}
};

template<typename T, size_t s>
class Array
{
private:
	T arr[s];
public:
	Array()
	{
		for (int i = 0; i < s; ++i)
			arr[i] = 0;
	}

	T& operator[] (size_t i) try
	{
		if (i > s || i < 0)
			throw error("You requested out of array.");
		return arr[i];
	} catch (error my)
	{
		my.show();
	}
	size_t size()
	{
		return s;
	}
};

template<size_t s>
class Array<bool, s>
{
private:
	char arr[s];

	class Boolean
	{
		Array& arr;
		int idx;
		Boolean& operator=(Boolean&);
	public:
		Boolean(Array& a, int i) : arr(a), idx(i) {}

		Boolean operator=(bool f)
		{
			arr.set_bit(idx, f);
			return *this;
		}

		operator bool()
		{
			return arr.get_bit(idx);
		}
	};

public:
	Array()
	{
		for (int i = 0; i < s; ++i)
			arr[i] = 0;
	}

	Boolean operator[] (size_t i) try
	{
		if (i > s * 8 || i < 0)
			throw error("You requested out of array.");
		Boolean b(*this, i);
		return b;
	}
	catch (error my)
	{
		my.show();
	}

	bool get_bit(int i) try
	{
		if (i > s * 8 | i < 0)
			throw error("You requested out of array.");
		return (arr[i/8] >> (i % 8) & 1);
	}
	catch (error my)
	{
		my.show();
	}

	void set_bit(int i, bool f) try
	{
		if (i > s * 8 | i < 0)
			throw error("You requested out of array.");
		if (f)
			arr[i/8] |= (1 << (i % 8));
		else
			arr[i/8] &= (~(1 << (i % 8)));
	}
	catch (error my)
	{
		my.show();
	}

	void out() {
		for (int i = 0; i < 8 * s; ++i)
			std::cout << (*this)[i];
		std::cout << '\n';
	}
};

template<typename T, size_t s, template<typename T, size_t s> class storage>
class my_stack {
private:
	storage<T, s> my_storage;
	size_t size;
public:
	my_stack() : size(0) {}

	void push(T x) try
	{
		if (size == s)
			throw error("You wanted to push item when the place was over");
		my_storage[size++] = x;
	}
	catch (error my)
	{
		my.show();
	}

	T pop() try
	{
		if (size == 0)
			throw error("You wanted to remove a non-existent item");
		return my_storage[--size];
	}
	catch (error my)
	{
		my.show();
	}
};

template<typename T, size_t s, template<typename T, size_t s> class storage>
class my_queue {
private:
	storage<T, s> my_storage;
	size_t l;
	size_t r;
	size_t size;
public:
	my_queue() : l(0), r(0), size(0) {}

	void push(T x) try
	{
		if (size == s)
			throw error("You wanted to push item when the place was over");
		size++;
		my_storage[r++] = x;
		r %= s;
	}
	catch (error my)
	{
		my.show();
	}

	T pop() try
	{
		if (size == 0)
			throw error("You wanted to remove a non-existent item");
		size--;
		T tmp = my_storage[l++];
		l %= s;
		return tmp;
	}
	catch (error my)
	{
		my.show();
	}
};
