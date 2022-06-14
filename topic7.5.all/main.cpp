#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

const int MAX_BUFF = 100;
int main() {
	std::vector<int>v;
	std::atomic<bool> flag{false};
	
	std::thread producer([&](){
		unsigned short id= 0;
		while(true){
			++id;
			for(int i = 0; i < MAX_BUFF; ++i)
			{
				v.push_back((int)(id<<14)+i);
			}
			flag.store(true, std::memory_order_release);
			while(flag.load(std::memory_order_consume));
		}
	});
	std::thread consumer([&](){
		
		while(true)
		{
			if(flag.load(std::memory_order_consume)){
				for(int i = 0; i< MAX_BUFF; ++i)
				{
					std::cout << std::hex <<v.at(i) << " ";
				}
				v.clear();
				v.shrink_to_fit();
				std::cout <<std::endl;
				flag.store(false, std::memory_order_release);
			}

		}
	});
	producer.join();
	consumer.join();


	return 0;
}
