#include "head.h"

int main() {
	system("mode con:cols=150 lines=150");
	checkerBoard start; //���ӽ���(�����ڷ� ���� �ֿܼ� �����ǰ� �������̽� �׸��� ���)
	start.updateCheckerBoard();//���� ���� ����
	//Sleep(3000);
	return 0;
}