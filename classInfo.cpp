#include "head.h"

void CursorLocation(int x, int y);

interFace::interFace()
	:showInfoX(35), showInfoY(0) {
}

interFace::~interFace(){}

void interFace::printGrid() {
	//명령어의 정보를 알려주는 그리드의 칸 출력
	CursorLocation(showInfoX, showInfoY); //커서 위치 이동
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

	//명령어 설명 내용을 그리드 내에 출력
	CursorLocation(showInfoX + 3, showInfoY + 8);
	cout << "w키 : 위로 한칸 이동.";
	CursorLocation(showInfoX + 3, showInfoY + 9);
	cout << "a키 : 왼쪽로 한칸 이동.";
	CursorLocation(showInfoX + 3, showInfoY + 10);
	cout << "s키 : 아래로 한칸 이동.";
	CursorLocation(showInfoX + 3, showInfoY + 11);
	cout << "d키 : 오른쪽으로 한칸 이동.";
	CursorLocation(showInfoX + 3, showInfoY + 12);
	cout << "h키 : 오목 판에 착수.";
}

void interFace::printMessage() {

}

//////////////////////////////////////////////////////////////////////////////////////
checkerBoard::checkerBoard()
	:LandPositionX(0), LandPositionY(0) {

}

checkerBoard::~checkerBoard(){}

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


//////////////////////////////////////////////////////////////////////////////////////
void CursorLocation(int x, int y) {
	COORD pos; //COORD 커서의 위치를 저장하는 구조체
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
