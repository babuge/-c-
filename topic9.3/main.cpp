#include <iostream>
#include <string>

// 字符串字面量自定义必须设置如下的参数列表
std::string operator"" _wow1( const char *wow1, size_t len) {
	return std::string(wow1) + "wooooooooooow, amazing";
}
std::string operator"" _wow2(unsigned long long i) {
	return std::to_string(i) + "wooooooooooow, amazing";
}

int main() {

        auto str0 = "abc"_wow1;
        auto num = 1_wow2;
        std::cout << str0 << std::endl;
        std::cout << num << std::endl;

	std::string str = R"(c:\File\To\Path)"; // c:\\File\\To\\Path
	std::cout << str << std::endl;

	return 0;
}

