#include "head.h"

void gotoxy(int x, int y);

//-----------------------------------------------------------------
//인터페이스 칸에서 벌어지는 일들을 통제하는 클래스들의 정의

//인터페이스 함수 생성자, 인터페이스 격자위치 출력을 위해 값 초기화
interFace::interFace()
	:showInfoX(35), showInfoY(0) {
}

//인터페이스 함수 소멸자
interFace::~interFace(){}


void interFace::printGrid() {
	//명령어의 정보를 알려주는 그리드의 칸 출력
	gotoxy(showInfoX, showInfoY); //커서 위치 이동
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

	//명령어 설명 내용을 그리드 내에 출력
	gotoxy(showInfoX + 3, showInfoY + 8);
	cout << "w키 : 위로 한칸 이동.";
	gotoxy(showInfoX + 3, showInfoY + 9);
	cout << "a키 : 왼쪽로 한칸 이동.";
	gotoxy(showInfoX + 3, showInfoY + 10);
	cout << "s키 : 아래로 한칸 이동.";
	gotoxy(showInfoX + 3, showInfoY + 11);
	cout << "d키 : 오른쪽으로 한칸 이동.";
	gotoxy(showInfoX + 3, showInfoY + 12);
	cout << "h키 : 오목 판에 착수.";
}

void interFace::printMessage() {

}











//-----------------------------------------------------------------
//오목 판에서 벌어지는 일들을 통제하는 클래스들의 정의

//오목판 클래스 생성자, 착수 시작 위치는 0,0에서 시작, 착수할 오목판 생성 및 인터페이스 격자, 정보 생성
checkerBoard::checkerBoard()
{
	LandPositionX = LandPositionY = 0;
	printCheckerBoard();
	itf.printGrid();
}

//오목판 클래스 소멸자
checkerBoard::~checkerBoard(){}


//오목판 출력
void checkerBoard::printCheckerBoard() {
	cout << "┌";
	for (int i = 0; i < SIZE - 2; i++) {
		cout << "-┬";
	}
	cout << "-┐" << endl;

	for (int i = 0; i < SIZE - 2; i++) {
		cout << "├";
		for (int j = 0; j < SIZE - 2; j++) {
			cout << "-┼";
		}
		cout << "-┤" << endl;
	}

	cout << "└";
	for (int i = 0; i < SIZE - 2; i++) {
		cout << "-┴";
	}
	cout << "-┘" << endl;
}


//오목판 착수 함수. 각 입력에 따라 커서를 움직이고, 착수를 누르면 해당 위치에 오목알 배치(아직 구현 안됨)
void checkerBoard::updateCheckerBoard() {
	//시작 위치 0.0
	gotoxy(0, 0);

	//사용자의 입력이 오목판을 벗어날 경우 게임 종료
	while (1) { 
		int direction; //명령어를 저장할 변수 선언
		bool state; //현재 상태를 저장할 변수 선언
		direction = _getch(); //https://blockdmask.tistory.com/399, 명령입력 받기

		//각 입력에 따른 상태 초기화
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

		//만약 명령에 따른 상태가 참(격자 안에 머문 경우)인 경우
		if (state) {
			gotoxy( gamm.getX() * 2, gamm.getY()); //GameManager함수의 x와 y 값으로 부터 불러와서 커서 이동
		}
		else break;//명령으로 인해 격자 밖으로 이동한 경우 게임 종료
	}
}




//-------------------------------------------------------------------
//게임 동작을 통제하는 클래스의 정의

//게임 매니져의 x와 y값 0으로 초기화
GameManager::GameManager()
{
	posX = posY = 0;
}

//소멸자
GameManager::~GameManager(){}

//게임매니져의 x값을 반환
int GameManager::getX() {
	return posX;
}

//게임 매니져의 y값을 반환
int GameManager::getY() {
	return posY;
}

//만약 x축 이동을 명령받았을 때, 해당 이동이 격자 밖을 벗어나지 않으면, 해당 값을 반영하고 1을 반환
bool GameManager::moveX(int direction) {
	if (posX + direction < 0 || posX + direction >= SIZE) {
		return false;
	}
	posX += direction;
	return true;
}

//만약 y축 이동을 명령받았을 때, 해당 이동이 격자 밖을 벗어나지 않으면, 해당 값을 반영하고 1을 반환
bool GameManager::moveY(int direction) {
	if (posY + direction < 0 || posY + direction >= SIZE) {
		return false;
	}
	posY += direction;
	return true;
}





//-------------------------------------------------------------------
//전역 함수, 해당 위치로 커서를 이동하는 함수
void gotoxy(int x, int y) {
	COORD pos; //COORD 커서의 위치를 저장하는 구조체
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
