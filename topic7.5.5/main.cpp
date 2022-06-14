#include <thread>
#include <atomic>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	std::atomic<int> flag {0};
	std::thread release([&](){
		v.push_back(42);
		std::cout << "1" << std::endl;
		flag.store(1, std::memory_order_release);
	});
	std::thread acqrel([&]() {
		// 期望值：1,保证原子性，flag设置1后，在设置2 否则一直等待 	
		int expected = 1; // must before compare_exchange_strong
		std::cout << "befor" << std::endl;
		while(!flag.compare_exchange_strong(expected, 2, std::memory_order_acq_rel)) {
			expected = 1;
			std::cout << "running realy" << std::endl;
		}
		// flag has changed to 2
		std::cout << "changed to :" << expected << std::endl;
	});
	std::thread acquire([&](){
		// 一直等待flag>=2, 保证flag设置1后并改变为2，
		// 保证了vector 写42一定完成在读42之前
		while(flag.load(std::memory_order_acquire) < 2);
		std::cout << v.at(0) << std::endl; // must be 42
	});
	
	release.join();
	acqrel.join();
	acquire.join();
	return 0;
}
