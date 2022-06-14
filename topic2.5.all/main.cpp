#include <iostream>
#include <map>

template <typename Key, typename Value, typename F>
void update(std::map<Key, Value>& m,F foo) {
	//
	for(auto &&[key, value] : m)
	{
		auto v = foo(key);
		value = v;
	}	
}

int main() {
	std::map<std::string, long long int> m {
		{"a", 1},
		{"b", 1},
		{"c", 1},
	};
	
	update(m, [](std::string key) {
		return std::hash<std::string>{}(key);
	});
	
	for(auto &&[key, value] : m) {
		std::cout << key << " : " << value << std::endl;
	}
}
