#include <iostream>
#include <memory>

void foo(std::shared_ptr<int> i)
{
	(*i)++;
}

int main() {
	// auto pointer = new int(10); // illegal, no direct assignment
	// Constructed a std::shared_ptr
	auto pointer = std::make_shared<int>(10);
	foo(pointer);
	std::cout<< *pointer << std::endl; // 11
	// 智能指针将在当前作用域离开前被析构
	return 0;
}

