#include<iostream>
#include<vector>

void VectorTest() {
	//1D array
	std::vector<int> vec, v1, v2, v3;
	std::cout << "maxsize of is" << vec.max_size() << std::endl;
	for (int i = 0; i < 10; i++) {
		vec.push_back(2 * i);
		std::cout << "size of vec is " << vec.size() << std::endl;
		std::cout << "capacity of vec is " << vec.capacity() << std::endl;
	}

	//resize
	//如果resize（n）中n小于当前vector中元素个数，则舍弃后面的元素
	vec.resize(8);
	std::cout << "size of vec is " << vec.size() << std::endl;
	vec.resize(20);
	std::cout << "size of vec is " << vec.size() << std::endl;

	//reserve
	//如果reserve(n)中n小于当前vector中元素个数，则调用直接返回
	vec.reserve(8);
	std::cout << "size of vec is " << vec.size() << std::endl;
	vec.reserve(24);
	std::cout << "size of vec is " << vec.size() << std::endl;

	//去掉最后一个元素
	vec.pop_back();

	std::vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	//插入
	vec.insert(vec.begin() + 3, 1);

	//删除
	vec.erase(vec.begin() + 1);
	vec.erase(vec.begin(), vec.begin() + 2);

	std::vector<int>::iterator iter1;
	for (iter1 = vec.begin(); iter1 != vec.end(); iter1++)
		std::cout << *iter1 << " ";
	std::cout << std::endl;


	//取数组的首、尾指向的数据
	std::cout << "vec.front() is" << vec.front() << std::endl;
	std::cout << "vec.back() is" << vec.back() << std::endl;

	//查找
	std::cout << "vec.at(3) is " << vec.at(3) << std::endl;
	
	//assign
	v1 = vec;
	std::vector<int>::iterator iter2;
	for (iter2 = v1.begin(); iter2 != v1.end(); iter2++)
		std::cout << *iter2 << " ";
	std::cout << std::endl;

	v2.assign(vec.begin(), vec.begin() + 3);
	for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)
		std::cout << *iter2 << " ";
	std::cout << std::endl;

	v3.assign(7, 3);
	for (iter2 = v3.begin(); iter2 != v3.end(); iter2++)
		std::cout << *iter2 << " ";
	std::cout << std::endl;

	//swap
	v1.swap(v2);
	for (iter2 = v2.begin(); iter2 != v2.end(); iter2++)
		std::cout << *iter2 << " ";
	std::cout << std::endl;
	std::swap(v1, v2);
}