// shrink_to_fit() ; 将删除元素对应的内存归还给系统

#include <iostream>
#include <vector>

using vct = std::vector<int>;
vct  v;

void prnt(const vct  &arr) {
	std::cout << "size: " << arr.size();
	std::cout << " capacity:" << arr.capacity() << std::endl;
}

int main() {
	const int count = 100;
	prnt(v);
	for(int i=0;i<count; ++i) {
		v.push_back(i);
		prnt(v);
	}
	for(int i=0;i<count;++i) {
		v.push_back(i);
		if(i%20 == 0 && i!=0) {
			v.clear();
			std::cout << "--------clear-------" <<std::endl;
		}
		prnt(v);
	}
	
	// shrink_to_fit(),释放移除元素对应内存 
	std::cout << "直接调用自动归还多余扩展内存: ";
	v.shrink_to_fit();
	prnt(v);

	std::cout << "清空所有元素后，在归还内存：";
	v.resize(0);
	v.shrink_to_fit();
	prnt(v);

	return 0;
}
