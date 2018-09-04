/***********************************************************************
*STL(Standard Template Library)
*  C++中STL之所以获得广泛的赞誉，不仅是因为提供了众多容器
*  还因为STL封装了很多复杂的数据结构算法和数据结构，如vector封装了数组，
*  list封装了链表，map和set封装了二叉树
*STL中标准关联容器set,multiset, map, multimap内部采用了非常高效的
*  平衡检索二叉树：红黑树。红黑树的统计性能好于一般的平衡二叉树
*map和set的插入删除效率比其他容器高的原因：不需要内存拷贝和内存移动
*  map和set容器内元素以节点的方式存储，插入和删除时只需要节点指针变动
*STL采用自己的Allocator分配内存， 以内存池的方式管理这些内存，
*  大大减少了内存碎片
***********************************************************************/

#include<iostream>
#include<map>
#include<string>

typedef std::map<int, std::string> MAP_INT_STRING;

enum InsertionMethod {
	Insert,
	ValueType,
	Array,
};

enum TraverseMap {
	Forward,
	Reverse,
	T_Array,
};

enum SearchMethod {
	S_Count,
	S_Find,
};

enum EraseMethod {
	E_Iter,
	E_Key,
	E_Range,
};

// Insert和ValueType效果一样：当map中出现这个关键字后，插入无效。
// Array与上面效果相反，新的键值对会覆盖原来的键值对。
void InsertElement(MAP_INT_STRING *map_std, int key, std::string value,
	enum InsertionMethod im) {
	switch (im)
	{
	case Insert:
		map_std->insert(std::pair<int, std::string>(key, value));
		break;
	case ValueType:
		map_std->insert(std::map<int, std::string>::value_type(key, value));
		break;
	case Array:
		(*map_std)[key] = value;
		break;
	default:
		break;
	}

}

void SearchValue(MAP_INT_STRING *map_stu, int key, enum SearchMethod sm) {
	switch (sm)
	{
	case S_Count:
		// count 返回指定元素出现的次数
		if (map_stu->count(key))
			std::cout << "found this key" << std::endl;
		else
			std::cout << "not found this key" << std::endl;
		break;
	case S_Find:
	{
		MAP_INT_STRING::iterator iter;
		iter = map_stu->find(key);
			if (iter != map_stu->end())
				std::cout << "the value of " << key << " is: " 
				<< iter->second << std::endl;
			else
			{
				std::cout << "not found this key" << std::endl;
			}
		break;
	}

	default:
		break;
	}
}

void EraseElement(MAP_INT_STRING *map_stu, enum EraseMethod e_method) {
	switch (e_method)
	{
	case E_Iter:
	{
		MAP_INT_STRING::iterator iter;
		iter = map_stu->find(1);
		map_stu->erase(iter);
		break;
	}
	case E_Key:
		//删除成功返回1， 否则返回0
		if (map_stu->erase(1))
			std::cout << "erase key successfully" << std::endl;
		else
			std::cout << "failed to erase" << std::endl;
		break;
	case E_Range:
		map_stu->erase(map_stu->begin(), map_stu->end());
	default:
		break;
	}
}

void PrintMap(MAP_INT_STRING *map_stu, enum TraverseMap t_map) {
	//MAP_INT_STRING::iterator iter;
	std::map<int, std::string>::reverse_iterator r_iter;
	int n_size = map_stu->size();
	switch (t_map)
	{
	case Forward:
	{
		MAP_INT_STRING::iterator iter;
		for (iter = map_stu->begin(); iter != map_stu->end(); iter++)
			std::cout << iter->first << " : " << iter->second << std::endl;
		break;
	}
	case Reverse:
		//std::map<int, std::string>::reverse_iterator r_iter;
		for(r_iter = map_stu->rbegin(); r_iter != map_stu->rend(); r_iter++)
			std::cout << r_iter->first << " : " << r_iter->second << std::endl;
		break;
	case T_Array:
		for (int i = 1; i <= n_size; i++) {
			std::cout << (*map_stu)[i] << std::endl;	
		}
		break;
	default:
		break;
	}

}

//map内部自建一颗红黑树，这棵树对数据具有自动排序功能
//根据key快速查找记录，查找的时间复杂度基本为log2(N)
void MapTest() {
	std::map<int, std::string> mapStu;

	//map中默认按照key的升序排列
	//插入元素
	InsertElement(&mapStu, 10, "apple", Insert);
	InsertElement(&mapStu, 2, "google", ValueType);
	InsertElement(&mapStu, 3, "microsoft", Array);
	InsertElement(&mapStu, 1, "samsung", Insert);
	InsertElement(&mapStu, 2, "yahu", ValueType);
	InsertElement(&mapStu, 3, "huawei", Array);

	//获取map的大小
	int map_size = mapStu.size();
	std::cout << "size of mapStu is: " << map_size << std::endl;

	//正向/反向遍历
	PrintMap(&mapStu, Forward);
	PrintMap(&mapStu, Reverse);
	PrintMap(&mapStu, T_Array);

	//查找元素
	SearchValue(&mapStu, 1, S_Count);
	SearchValue(&mapStu, 1, S_Find);
	SearchValue(&mapStu, 4, S_Count);
	SearchValue(&mapStu, 4, S_Find);

	//删除元素
	EraseElement(&mapStu, E_Iter);
	EraseElement(&mapStu, E_Key);
	EraseElement(&mapStu, E_Range);

	//map是否为空
	if (mapStu.empty())
		std::cout << "map is empty" << std::endl;
	else
		std::cout << "map is not empty" << std::endl;
}