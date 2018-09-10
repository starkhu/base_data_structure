#include<iostream>
#include<vector>

void Vector1DTest() {
	//1D array
	std::vector<int> vec, v1, v2, v3;
	std::cout << "maxsize of is" << vec.max_size() << std::endl;
	//size��ʾvec��ӵ�е�Ԫ�صĸ���
	//capacity��ʾϵͳ��vec������ڴ�ռ�Ĵ�С
	for (int i = 0; i < 10; i++) {
		vec.push_back(2 * i);
		std::cout << "size of vec is " << vec.size() << std::endl;
		std::cout << "capacity of vec is " << vec.capacity() << std::endl;
	}

	//resize 
	//���resize��n����nС�ڵ�ǰvector��Ԫ�ظ����������������Ԫ��
	//���resize(n)��n���ڵ�ǰvector�е�Ԫ�ظ����������n���ڴ�ռ䣬����ʼ��������ڴ�ռ�
	vec.resize(8);
	std::cout << "size of vec is " << vec.size() << std::endl;
	vec.resize(20);
	std::cout << "size of vec is " << vec.size() << std::endl;
	std::cout << "capacity of vec is " << vec.capacity() << std::endl;

	//reserve
	//���reserve(n)��nС�ڵ�ǰvector��Ԫ�ظ����������ֱ�ӷ���
	//���reserve(n)��n���ڵ�ǰvector��Ԫ�ظ�����ֻ����n���ڴ�ռ䣬�����ʼ���·�����ڴ�ռ�
	vec.reserve(6);
	std::cout << "size of vec is " << vec.size() << std::endl;
	vec.reserve(24);
	std::cout << "size of vec is " << vec.size() << std::endl;
	std::cout << "capacity of vec is " << vec.capacity() << std::endl;

	//ȥ�����һ��Ԫ��
	vec.pop_back();

	std::vector<int>::iterator iter;
	for (iter = vec.begin(); iter != vec.end(); iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;

	//����
	vec.insert(vec.begin() + 3, 1);

	//ɾ��
	vec.erase(vec.begin() + 1);
	vec.erase(vec.begin(), vec.begin() + 2);

	std::vector<int>::iterator iter1;
	for (iter1 = vec.begin(); iter1 != vec.end(); iter1++)
		std::cout << *iter1 << " ";
	std::cout << std::endl;


	//ȡ������ס�βָ�������
	std::cout << "vec.front() is" << vec.front() << std::endl;
	std::cout << "vec.back() is" << vec.back() << std::endl;

	//����
	std::cout << "vec.at(3) is " << vec.at(3) << std::endl;
	//std::cout << "vec.at(17) is " << vec.at(17) << std::endl;
	//::cout << "vec[17] is " << vec[17] << std::endl;
	
	//assign
	//v0�Ŀռ���vec��size, ����vec��capicity.
	std::vector<int> v0(vec);
	std::cout << "capacity of vec is " << vec.capacity() << std::endl;
	std::cout << "size of vec is " << vec.size() << std::endl;
	std::cout << "capacity of v0 is " << v0.capacity() << std::endl;

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

void VectorTest() {
	Vector1DTest();
}