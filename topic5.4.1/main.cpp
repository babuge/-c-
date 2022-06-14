#include <iostream>
#include <string>
#include <memory>

struct A;
struct B;

#define RefP std::shared_ptr
#define RefPMk std::make_shared

#define RefP1 std::weak_ptr


struct A {
	RefP1<B> pointer;
	~A() {
		std::cout << "A 被销毁" << std::endl;
	}
};
struct B {
	RefP1<A> pointer;
	~B() {
		std::cout << "B 被销毁" << std::endl;
	}
};

int main() {
	auto a = RefPMk<A>();
	auto b = RefPMk<B>();
	
	a->pointer = b;
	b->pointer = a;
}
