#include <string>
#include <iostream>
#include <tuple>
#include <variant>

// c++17
auto get_student(int id) 
{
	// 返回类型被推断为 std::tuple<double, char, std::string>
	if(id == 0)
		return std::make_tuple(3.8, 'A', "张三");
	if (id == 1)
		return std::make_tuple(2.9, 'C', "李四");
	if(id == 2)
		return std::make_tuple(1.7, 'D', "王五" );
	return std::make_tuple( 0.0, 'D', "null");
}
// c++17

template<size_t n, typename... T>
constexpr std::variant<T...> _tuple_index( const std::tuple<T...>& tpl, size_t i) {

	if constexpr (n >= sizeof...(T) )
                throw std::out_of_range(" 越界.");
        if (i==n)
                return std::variant<T...>{ std::in_place_index<n>, std::get<n>(tpl) };
        return _tuple_index<(n < sizeof...(T) - 1 ? n+1: 0) > (tpl, i);
}

template <typename... T>
constexpr std::variant<T...> tuple_index(const std::tuple<T...>& tpl, size_t i) {
	return _tuple_index<0>(tpl, i);
}

template <typename T0, typename... Ts>
std::ostream & operator<< (std::ostream & s, std::variant<T0, Ts...> const & v) {
        std::visit([&](auto &&x) { s << x; } , v);
        return s;
}

// 遍历元组
template <typename T>
auto tuple_len(T &tpl) {
	return std::tuple_size<T>::value;
}

int main() {
	std::tuple<std::string, double, double, int> t("123", 4.5, 4.6, 8);
	// 合并元组  c++14
	auto new_tuple = std::tuple_cat(get_student(1), std::move(t));
	
	// 迭代
	int len = tuple_len(new_tuple);
	for( int i = 0; i != len; ++i) 
	{
		// 运行期间索引
		std::cout << tuple_index(new_tuple,i) << std::endl;
	}
	return 0;
}
