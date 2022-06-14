#include <iostream>
#include <cstddef>
#include <limits>

struct Storage {
	char a;
	int b;
	double c;
	long long d;
};

struct alignas(std::max_align_t) AlignasStorage {
	char a;
	int b;
	double c;
	long long d;
};

int main() {
	std::cout << alignof(Storage) << std::endl;
	std::cout << alignof(AlignasStorage) << std::endl;

	std::cout << "size of: " << sizeof(long double) << std::endl;
	
	std::cout << "long double max" << std::numeric_limits<long double>::max() << std::endl;
	std::cout << "long double min" << std::numeric_limits<long double>::min() << std::endl;

	return 0;
}
