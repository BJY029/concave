#include "head.h"

void CursorLocation(int x, int y);

//-----------------------------------------------------------------
//�������̽� ĭ���� �������� �ϵ��� �����ϴ� Ŭ�������� ����
interFace::interFace()
	:showInfoX(35), showInfoY(0) {
}

interFace::~interFace(){}

void interFace::printGrid() {
	//��ɾ��� ������ �˷��ִ� �׸����� ĭ ���
	CursorLocation(showInfoX, showInfoY); //Ŀ�� ��ġ �̵�
	for (int i = 0; i < 40; i++) {
		cout << "-";
	}
	for (int i = 1; i < 14; i++) {
		CursorLocation(showInfoX, showInfoY + i);
		cout << "|";
		CursorLocation(showInfoX + 39, showInfoY + i);
		cout << "|";
	}
	CursorLocation(showInfoX, showInfoY + 14);
	for(int i = 0; i < 40; i++){
		cout << "-";
	}

	//��ɾ� ���� ������ �׸��� ���� ���
	CursorLocation(showInfoX + 3, showInfoY + 8);
	cout << "wŰ : ���� ��ĭ �̵�.";
	CursorLocation(showInfoX + 3, showInfoY + 9);
	cout << "aŰ : ���ʷ� ��ĭ �̵�.";
	CursorLocation(showInfoX + 3, showInfoY + 10);
	cout << "sŰ : �Ʒ��� ��ĭ �̵�.";
	CursorLocation(showInfoX + 3, showInfoY + 11);
	cout << "dŰ : ���������� ��ĭ �̵�.";
	CursorLocation(showInfoX + 3, showInfoY + 12);
	cout << "hŰ : ���� �ǿ� ����.";
}

void interFace::printMessage() {

}











//-----------------------------------------------------------------
//���� �ǿ��� �������� �ϵ��� �����ϴ� Ŭ�������� ����
checkerBoard::checkerBoard()
	:LandPositionX(0), LandPositionY(0) {

}

checkerBoard::~checkerBoard(){}

//������ ���
void checkerBoard::printCheckerBoard() {
	cout << "��";
	for (int i = 0; i < SIZE - 2; i++) {
		cout << "-��";
	}
	cout << "-��" << endl;

	for (int i = 0; i < SIZE - 2; i++) {
		cout << "��";
		for (int j = 0; j < SIZE - 2; j++) {
			cout << "-��";
		}
		cout << "-��" << endl;
	}

	cout << "��";
	for (int i = 0; i < SIZE - 2; i++) {
		cout << "-��";
	}
	cout << "-��" << endl;
}












//-------------------------------------------------------------------
//���� �Լ�, �ش� ��ġ�� Ŀ���� �̵��ϴ� �Լ�
void CursorLocation(int x, int y) {
	COORD pos; //COORD Ŀ���� ��ġ�� �����ϴ� ����ü
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
