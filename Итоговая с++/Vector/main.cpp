#include "Array.h"
#include <iostream>

int main() {
	std::cout << "Test" << '\n';

	Array<int, 5> a;

	a[3] = 2;

	std::cout << a[3] << '\n';
	std::cout << a.size() << '\n';

	std::cout << "Bool" << '\n';

	Array<bool, 1> b;

	b.out();

	b[1] = true;

	b.out();

	b[5] = true;

	b.out();

	return 0;
}
