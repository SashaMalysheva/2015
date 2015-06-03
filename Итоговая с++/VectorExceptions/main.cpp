#include "Array.h"
#include <iostream>
#include <vector>

int main() {
	my_vector<int> v;

	for (int i = 0; i < 5; ++i)
		v.push_back(i);

	for (int i = 0; i < v.size(); ++i)
		std::cerr << v[i] << ' ';

	std::cerr << '\n';
}
