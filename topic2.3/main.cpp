#include <iostream>
#include <type_traits>

// 尾返回类型

//	c++11
template<typename T, typename U>
auto add2(T x, U y) -> decltype(x +y){
	return x + y;
}
		
//	c++14:
// 普通函数具备返回值推导
template<typename T, typename U>
auto add3(T x, U y) {
	return x + y;
}
		
		
// check一下类型推导的正确性：
int main() {
	// c++11
	auto w = add2<int , double>(1,2.0);
	if(std::is_same<decltype(w), double>::value) {
		std::cout << "w is double: ";
	}
	std::cout << w << std::endl;
	
	
	// c++14
	auto q = add3<double, int>(1.0, 2);
	std::cout << "q: " << q << std::endl;

}
