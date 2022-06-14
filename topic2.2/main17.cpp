#include <iostream>
#include <vector>
#include <algorithm>

// c++17之后 支持在if 、switch中声明一个新变量
int main(){
	std::vector<int> vec = {1, 2, 3,4};
	
	if(const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(),2); itr != vec.end()){
		*itr = 3;
	}
	
	if(const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(),3); itr != vec.end()){
                *itr = 4;
        } 

	for(std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
		std::cout<< *element << std::endl;


	return 0;
}
