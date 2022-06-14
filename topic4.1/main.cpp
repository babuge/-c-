#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	std::cout << "size:" << v.size() << std::endl; // 输出：0 
	std::cout << "capacity:" << v.capacity() << std::endl; // 输出 0

	// std::vector的存储是自动管理的，按需自动扩张
	// 但是如果空间不足，需要重新分配更多的内存，而重分配内存通常是性能上有开销的操作。
	v.push_back(1);
	v.push_back(1);
	v.push_back(1);
	std::cout << "size:" << v.size() << std::endl; // 输出 3
	std::cout << "capacity:" << v.capacity() << std::endl; // 输出 4

	// 这里自动扩张逻辑与Golang的slice很像
	v.push_back(4);
	v.push_back(5);
	std::cout << "size:" << v.size() << std::endl; // 输出 5
	std::cout << "capacity:" << v.capacity() << std::endl; // 输出8

	// 如下，容器清空了元素，但清空元素的内存没有被归还
	v.clear();
	std::cout << "szie:" << v.size() << std::endl; // 输出 0
	std::cout << "capacity: " << v.capacity() << std::endl; // 输出8

	
	// 额外的内存通过shrink_to_fit() 调用返回给系统
	v.shrink_to_fit();
	std::cout << "size: " << v.size() << std::endl; // 输出0
	std::cout << "capacity: " << v.capacity() << std::endl; // 输出0 
	
	return 0;
}
