/***********************************************************************
*STL(Standard Template Library)
*  C++��STL֮���Ի�ù㷺����������������Ϊ�ṩ���ڶ�����
*  ����ΪSTL��װ�˺ܶิ�ӵ����ݽṹ�㷨�����ݽṹ����vector��װ�����飬
*  list��װ������map��set��װ�˶�����
*STL�б�׼��������set,multiset, map, multimap�ڲ������˷ǳ���Ч��
*  ƽ���������������������������ͳ�����ܺ���һ���ƽ�������
*map��set�Ĳ���ɾ��Ч�ʱ����������ߵ�ԭ�򣺲���Ҫ�ڴ濽�����ڴ��ƶ�
*  map��set������Ԫ���Խڵ�ķ�ʽ�洢�������ɾ��ʱֻ��Ҫ�ڵ�ָ��䶯
*STL�����Լ���Allocator�����ڴ棬 ���ڴ�صķ�ʽ������Щ�ڴ棬
*  ���������ڴ���Ƭ
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

// Insert��ValueTypeЧ��һ������map�г�������ؼ��ֺ󣬲�����Ч��
// Array������Ч���෴���µļ�ֵ�ԻḲ��ԭ���ļ�ֵ�ԡ�
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
		// count ����ָ��Ԫ�س��ֵĴ���
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
		//ɾ���ɹ�����1�� ���򷵻�0
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

//map�ڲ��Խ�һ�ź����������������ݾ����Զ�������
//����key���ٲ��Ҽ�¼�����ҵ�ʱ�临�ӶȻ���Ϊlog2(N)
void MapTest() {
	std::map<int, std::string> mapStu;

	//map��Ĭ�ϰ���key����������
	//����Ԫ��
	InsertElement(&mapStu, 10, "apple", Insert);
	InsertElement(&mapStu, 2, "google", ValueType);
	InsertElement(&mapStu, 3, "microsoft", Array);
	InsertElement(&mapStu, 1, "samsung", Insert);
	InsertElement(&mapStu, 2, "yahu", ValueType);
	InsertElement(&mapStu, 3, "huawei", Array);

	//��ȡmap�Ĵ�С
	int map_size = mapStu.size();
	std::cout << "size of mapStu is: " << map_size << std::endl;

	//����/�������
	PrintMap(&mapStu, Forward);
	PrintMap(&mapStu, Reverse);
	PrintMap(&mapStu, T_Array);

	//����Ԫ��
	SearchValue(&mapStu, 1, S_Count);
	SearchValue(&mapStu, 1, S_Find);
	SearchValue(&mapStu, 4, S_Count);
	SearchValue(&mapStu, 4, S_Find);

	//ɾ��Ԫ��
	EraseElement(&mapStu, E_Iter);
	EraseElement(&mapStu, E_Key);
	EraseElement(&mapStu, E_Range);

	//map�Ƿ�Ϊ��
	if (mapStu.empty())
		std::cout << "map is empty" << std::endl;
	else
		std::cout << "map is not empty" << std::endl;
}