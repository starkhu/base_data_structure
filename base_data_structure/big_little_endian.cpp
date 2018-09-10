/*********************************************************************************
*��С�˵Ķ���
*С�ˣ���λ�ֽ��ŷ����ڴ�ĵ͵�ַ������λ�ֽ��ŷ����ڴ�ĸߵ�ַ��
*��ˣ���λ�ֽ��ŷ����ڴ�ĵ͵�ַ������λ�ֽ��ŷ����ڴ�ĸߵ�ַ��
��һ�����ӣ���������0x12 34 56 78���ڴ��еı�ʾ��ʽΪ��
1)���ģʽ��

�͵�ַ -----------------> �ߵ�ַ
0x12  |  0x34  |  0x56  |  0x78
2)С��ģʽ��

�͵�ַ ------------------> �ߵ�ַ
0x78  |  0x56  |  0x34  |  0x12
�ɼ������ģʽ���ַ����Ĵ洢ģʽ���ơ�
*********************************************************************************
һ�����ϵͳ����С�ˣ�ͨ��Э���Ǵ��
��ˣ�PowerPC IBM Sun ����ͨ��
С�ˣ� x86 DEC
ARM�ȿ��Թ����ڴ��ģʽ��Ҳ���Թ�����С��ģʽ
*********************************************************************************/

#include<iostream>
bool isBigEndian() {
	union NUM {
		int a;
		char b;
	}un;
	un.a = 0x11223344;
	std::cout << un.b << std::endl;
	std::cout << std::dec << (int)un.b << std::endl;
	std::cout << std::hex << (int)un.b << std::endl;
	if (un.b == 0x11) {
		std::cout << "big endian" << std::endl;
		return true;
	}
	if (un.b == 0x44) {
		std::cout << "little endian" << std::endl;
		return true;
	}
	
	return false;
}

void BigEndianTest() {
	if (isBigEndian())
		std::cout << "this operation is big endian pattern" << std::endl;
	else
		std::cout << "this operation is little endian pattern" << std::endl;
}