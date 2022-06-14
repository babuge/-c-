#include <iostream>
	
using foo = void(int); // 定义函数类型
void functional(foo f) { // foo被视为退化后的函数指针类型foo*
	f(1);
}
		
int main() {
	auto f = [] (int value) {
		std::cout << value << std::endl;
	};
	functional(f); // 传递闭包对象，隐式转换为 foo*类型函数指针值
	f(1); // lambda表达式调用
		
	return 0;
}
