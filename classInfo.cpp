#include "head.h"

void gotoxy(int x, int y);

//-----------------------------------------------------------------
//�������̽� ĭ���� �������� �ϵ��� �����ϴ� Ŭ�������� ����

//�������̽� �Լ� ������, �������̽� ������ġ ����� ���� �� �ʱ�ȭ
interFace::interFace()
	:showInfoX(35), showInfoY(0) {
}

//�������̽� �Լ� �Ҹ���
interFace::~interFace(){}


void interFace::printGrid() {
	//��ɾ��� ������ �˷��ִ� �׸����� ĭ ���
	gotoxy(showInfoX, showInfoY); //Ŀ�� ��ġ �̵�
	for (int i = 0; i < 40; i++) {
		cout << "-";
	}
	for (int i = 1; i < 14; i++) {
		gotoxy(showInfoX, showInfoY + i);
		cout << "|";
		gotoxy(showInfoX + 39, showInfoY + i);
		cout << "|";
	}
	gotoxy(showInfoX, showInfoY + 14);
	for(int i = 0; i < 40; i++){
		cout << "-";
	}

	//��ɾ� ���� ������ �׸��� ���� ���
	gotoxy(showInfoX + 3, showInfoY + 8);
	cout << "wŰ : ���� ��ĭ �̵�.";
	gotoxy(showInfoX + 3, showInfoY + 9);
	cout << "aŰ : ���ʷ� ��ĭ �̵�.";
	gotoxy(showInfoX + 3, showInfoY + 10);
	cout << "sŰ : �Ʒ��� ��ĭ �̵�.";
	gotoxy(showInfoX + 3, showInfoY + 11);
	cout << "dŰ : ���������� ��ĭ �̵�.";
	gotoxy(showInfoX + 3, showInfoY + 12);
	cout << "hŰ : ���� �ǿ� ����.";
}

void interFace::printMessage() {

}











//-----------------------------------------------------------------
//���� �ǿ��� �������� �ϵ��� �����ϴ� Ŭ�������� ����

//������ Ŭ���� ������, ���� ���� ��ġ�� 0,0���� ����, ������ ������ ���� �� �������̽� ����, ���� ����
checkerBoard::checkerBoard()
{
	LandPositionX = LandPositionY = 0;
	printCheckerBoard();
	itf.printGrid();
}

//������ Ŭ���� �Ҹ���
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


//������ ���� �Լ�. �� �Է¿� ���� Ŀ���� �����̰�, ������ ������ �ش� ��ġ�� ����� ��ġ(���� ���� �ȵ�)
void checkerBoard::updateCheckerBoard() {
	//���� ��ġ 0.0
	gotoxy(0, 0);

	//������� �Է��� �������� ��� ��� ���� ����
	while (1) { 
		int direction; //��ɾ ������ ���� ����
		bool state; //���� ���¸� ������ ���� ����
		direction = _getch(); //https://blockdmask.tistory.com/399, ����Է� �ޱ�

		//�� �Է¿� ���� ���� �ʱ�ȭ
		switch (direction) {
			case 'w': state = gamm.moveY(-1);
				break;
			case 'a': state = gamm.moveX(-1);
				break;
			case 's': state = gamm.moveY(1);
				break;
			case 'd': state = gamm.moveX(1);
				break;
			default:
				gotoxy(0, 17);
				cout << "incorrect input!" << endl;
				state = 0;
				break;
		}

		//���� ��ɿ� ���� ���°� ��(���� �ȿ� �ӹ� ���)�� ���
		if (state) {
			gotoxy( gamm.getX() * 2, gamm.getY()); //GameManager�Լ��� x�� y ������ ���� �ҷ��ͼ� Ŀ�� �̵�
		}
		else break;//������� ���� ���� ������ �̵��� ��� ���� ����
	}
}




//-------------------------------------------------------------------
//���� ������ �����ϴ� Ŭ������ ����

//���� �Ŵ����� x�� y�� 0���� �ʱ�ȭ
GameManager::GameManager()
{
	posX = posY = 0;
}

//�Ҹ���
GameManager::~GameManager(){}

//���ӸŴ����� x���� ��ȯ
int GameManager::getX() {
	return posX;
}

//���� �Ŵ����� y���� ��ȯ
int GameManager::getY() {
	return posY;
}

//���� x�� �̵��� ��ɹ޾��� ��, �ش� �̵��� ���� ���� ����� ������, �ش� ���� �ݿ��ϰ� 1�� ��ȯ
bool GameManager::moveX(int direction) {
	if (posX + direction < 0 || posX + direction >= SIZE) {
		return false;
	}
	posX += direction;
	return true;
}

//���� y�� �̵��� ��ɹ޾��� ��, �ش� �̵��� ���� ���� ����� ������, �ش� ���� �ݿ��ϰ� 1�� ��ȯ
bool GameManager::moveY(int direction) {
	if (posY + direction < 0 || posY + direction >= SIZE) {
		return false;
	}
	posY += direction;
	return true;
}





//-------------------------------------------------------------------
//���� �Լ�, �ش� ��ġ�� Ŀ���� �̵��ϴ� �Լ�
void gotoxy(int x, int y) {
	COORD pos; //COORD Ŀ���� ��ġ�� �����ϴ� ����ü
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
