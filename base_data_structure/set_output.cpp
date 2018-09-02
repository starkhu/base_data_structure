#include<iostream>
// io means input and output, manip means manipulator(������)
#include<iomanip> 

void SetOutputFormat() {
	using std::cout;
	//�����ַ�һ���趨���������ý����������������Ϊֹ
	std::cout << std::showpoint << std::fixed << std::setprecision(2);
	int num = 28;
	cout << "28�İ˽��ƣ�" << std::oct << num << std::endl;
	cout << "28ʮ���ƣ�" << std::dec << num << std::endl;
	cout << "28��ʮ�����ƣ�" << std::hex << num << std::endl;
	
	// setfill(c) ��c������ַ�
	// setw(n) �����ֶο��
	//setprecision(n) ���ø���������Ϊnλ
	// left/right ����롢�Ҷ���
	// fixed �Զ�����ű�ʾ������
	// scientific �Կ�ѧ��������ʾ������
	// showpoint ��ӡС�����β����
	// noshowpoint ����ӡβ���㣬���п��ܣ�ȥ��С����
	// showpos/noshowpos �ڷǸ�����ǰ��ʾ/����ʾ�Ӻ�
	// skipws/noskipws ����/����������ǰ�Ŀհ�
	// ws ɾ���հ�
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