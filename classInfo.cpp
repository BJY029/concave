#include "head.h"

void gotoxy(int x, int y);
//-----------------------------------------------------------------
//�������̽� ĭ���� �������� �ϵ��� �����ϴ� Ŭ�������� ����

//�������̽� �Լ� ������, �������̽� ������ġ ����� ���� �� �ʱ�ȭ
interFace::interFace()
	:showInfoX(35), showInfoY(0) {
}

//�������̽� �Լ� �Ҹ���
interFace::~interFace() {}


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
	for (int i = 0; i < 40; i++) {
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

//���� �����ؾ� �ϴ� �÷��̾ �˷��ִ� �Լ�
void interFace::printMessage(string message) {
	gotoxy(38, 5);
	cout << message;
}

//�̹� ������ ���� ������ �õ��� ��� ���� �޽����� ����ϴ� �Լ�
void interFace::printWrongLand(string message) {
	gotoxy(38, 3);
	cout << message;
}

//�߸��� Ű�� �Է��� ��� ���� �޽����� ����ϴ� �Լ�
void interFace::printWrongKey(string message) {
	gotoxy(38, 2);
	cout << message;
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
checkerBoard::~checkerBoard() {}


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
	gotoxy(38, 5);
	cout << "�浹�� ���� �����Դϴ�";
	gotoxy(0, 0);

	//������� �Է��� �������� ��� ��� ���� ����
	while (1) {
		int direction; //��ɾ ������ ���� ����
		bool flag;
		bool state; //���� ���¸� ������ ���� ����
		direction = _getch(); //https://blockdmask.tistory.com/399, ����Է� �ޱ�

		flag = 1; //flag �� 1�� �ʱ�ȭ
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
			case 'h': gamm.getStone(gamm.getX(), gamm.getY());
				state = 1;
				break;
			default: //default�� �ش��ϴ� ���� �߸��� ���� �Է��ϴ� ���, �����ϱ� ���Ͽ� flag�� 0�� ����
				state = 0;
				flag = 0;
				break;
		}

		//���� ��ɿ� ���� ���°� ��(���� �ȿ� �ӹ� ���)�� ���
		if (state) {
			itf.printWrongKey("                           ");
			gotoxy(gamm.getX() * 2, gamm.getY()); //GameManager�Լ��� x�� y ������ ���� �ҷ��ͼ� Ŀ�� �̵�
		}
		else {
			if (flag == 0) { //�߸��� ������� ���� ������ ���
				itf.printWrongKey("�߸��� ��ɾ��Դϴ�.");
				gotoxy(gamm.getX() * 2, gamm.getY());
			}
			else { //�������� ����� �߻��� ������ ���
				itf.printWrongKey("�������� ������ϴ�.");
				gotoxy(gamm.getX() * 2, gamm.getY());
			}
		}
	}
}


//-------------------------------------------------------------------
//���� ������ �����ϴ� Ŭ������ ����

//���� �Ŵ����� x�� y�� 0���� �ʱ�ȭ
//�浹�� �������� ���ӽ���
//������ ��ġ�� ���� �ִ��� Ȯ���ϴ� check �迭�� 0 ����
GameManager::GameManager()
{
	posX = posY = 0;
	colorOfStone = 1;
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			check[i][j] = 0;
		}
	}
	checkError = false;
}
//�Ҹ���
GameManager::~GameManager() {}



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

//'h'�� �Է�������
//1
//�浹�� ������ �� '�鵹�� ���� �����Դϴ�.' �� �ٲٰ�
//Ŀ�� ��ġ�� �ٵ��� ���� ���
//�鵹�� ������ �� '�浹�� ���� �����Դϴ�.' �� �ٲٰ�
//Ŀ�� ��ġ�� �ٵ��� ���� ���
//2
//���� ���� ������ �˰����� ���� ������ �ϼ��Ǵ��� �Ǵ�.
//���� 5���� ���� ������ ������ �ϼ��Ǹ�
//'�浹�� �̰���ϴ�' ����ϰ� ���α׷�����
//3
//���� Ŀ����ġ�� ���� �̹� ������ ������
//"���� �ٸ� ���� �μ��� !!" ����� �� �̾��
void GameManager::getStone(int X, int Y) {
	checkError = check[X][Y] ? true : false;

	if (checkError) {
		itf.printWrongLand("���� �ٸ� ���� �μ���!!");
		gotoxy(X * 2, Y);
	}
	else {
		itf.printWrongLand("                       ");
		gotoxy(X * 2, Y);
		if (colorOfStone == true) {
			//����
			printf("��");
			//���� �ѱ�
			colorOfStone = false;
			itf.printMessage("�浹�� ���� �����Դϴ�.");
			/*gotoxy(38, 5);
			cout << "�浹�� ���� �����Դϴ�";*/
		}
		else {
			printf("��");
			colorOfStone = true;
			itf.printMessage("�鵹�� ���� �����Դϴ�.");
		}
		check[X][Y] = 1;
	}
}



//-------------------------------------------------------------------
//���� �Լ�, �ش� ��ġ�� Ŀ���� �̵��ϴ� �Լ�
void gotoxy(int x, int y) {
	COORD pos; //COORD Ŀ���� ��ġ�� �����ϴ� ����ü
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
