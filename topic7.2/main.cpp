#include <iostream>
#include <thread>
#include <mutex>

int v = 1;

void critical_section(int change_v) {
	static std::mutex mtx;
	std::lock_guard<std::mutex> lock(mtx);
	
	// 执行竞争操作
	v = change_v;
	// 离开作用域自动释放mtx
}

int main() {
	std::thread t1(critical_section, 2) , t2(critical_section, 3);
	t1.join();
	t2.join();
	
	std::cout << v << std::endl;
	
	return 0;
}

