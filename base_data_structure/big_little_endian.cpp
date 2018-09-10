/*********************************************************************************
*大小端的定义
*小端：低位字节排放在内存的低地址处，高位字节排放在内存的高地址处
*大端：高位字节排放在内存的低地址处，低位字节排放在内存的高地址处
举一个例子，比如数字0x12 34 56 78在内存中的表示形式为：
1)大端模式：

低地址 -----------------> 高地址
0x12  |  0x34  |  0x56  |  0x78
2)小端模式：

低地址 ------------------> 高地址
0x78  |  0x56  |  0x34  |  0x12
可见，大端模式和字符串的存储模式类似。
*********************************************************************************
一般操作系统都是小端，通信协议是大端
大端：PowerPC IBM Sun 网络通信
小端： x86 DEC
ARM既可以工作在大端模式，也可以工作在小端模式
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