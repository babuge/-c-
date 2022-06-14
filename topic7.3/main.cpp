#include <iostream>
#include <future>
#include <thread>

int main() {
	// 将一个返回值为7的lambda表达式封装到task中
	// std::packaged_task 的模板参数为要封装的函数的类型
	std::packaged_task<int()> task([](){ return 7;});
	// 获取task的期物
	std::future<int> result = task.get_future(); // 在线程中执行task
	std::thread(std::move(task)).detach(); // 分离线程
	std::cout << "waiting …" ;
	result.wait(); // 在此设置屏障，阻塞到期物的完成
	// 输出执行结果
	std::cout << "done!" << std::endl << " future result is " << result.get() << std::endl;
	
	return 0;
}
