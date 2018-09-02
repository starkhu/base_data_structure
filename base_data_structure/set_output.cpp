#include<iostream>
// io means input and output, manip means manipulator(操纵器)
#include<iomanip> 

void SetOutputFormat() {
	using std::cout;
	//操作字符一旦设定，它的作用将会持续到重新设置为止
	std::cout << std::showpoint << std::fixed << std::setprecision(2);
	int num = 28;
	cout << "28的八进制：" << std::oct << num << std::endl;
	cout << "28十进制：" << std::dec << num << std::endl;
	cout << "28的十六进制：" << std::hex << num << std::endl;
	
	// setfill(c) 把c做填充字符
	// setw(n) 设置字段宽度
	//setprecision(n) 设置浮点数精度为n位
	// left/right 左对齐、右对齐
	// fixed 以定点符号表示浮点数
	// scientific 以科学计数法表示浮点数
	// showpoint 打印小数点和尾随零
	// noshowpoint 不打印尾随零，若有可能，去掉小数点
	// showpos/noshowpos 在非负数面前显示/不显示加号
	// skipws/noskipws 忽略/不忽略输入前的空白
	// ws 删除空白
	float (*arr0)[4] = new float[3][4];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			arr0[i][j] = 4 * i + j +0.0001;
			//std::cout << std::showpoint << std::fixed << std::setprecision(2);
			std::cout << std::left << std::setw(6) << arr0[i][j] << " ";
		}
		std::cout << std::endl;
	}
}