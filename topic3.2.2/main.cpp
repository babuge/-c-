#include <iostream>
#include <functional>

int foo( int a, int b, int c) {
	std::cout << a << " " << b << " " << c <<std::endl;
	return 0;
}

int main() {
	// 将参数1,2绑定到函数foo上，但是使用std::placeholders::_1来占用第一个参数位置
	auto bindFoo = std::bind(foo, std::placeholders::_1, 1, 2);
	// 这时调用bindFoo时，只需提供第一个参数即可
	bindFoo(4);
		
	return 0;
}

