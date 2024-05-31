#pragma once	//다중 선언되는 것을 방지
#include<Windows.h> //커서이동 기능을 위해 선언
#include<conio.h>  //getch을 사용하기 위해 선언
#include<cstring> //문자열 사용을 위한 선언
#include<iostream> //기본 헤더 파일
#define SIZE 15  //오목판 크기를 매크로 상수로 선언
using namespace std;

//인터페이스 칸에서 일어나는 일들을 통제하는 클래스
class interFace {
private:
	int showInfoX; //인터페이스 외곽 선을 출력하기 위한 x좌표 선언
	int showInfoY; //인터페이스 외곽 선을 출력하기 위한 y좌표 선언
public:
	interFace();
	~interFace();
	void printGrid();
	void printMessage(string message);
	void printWrongLand(string message);
	void printWrongKey(string message);
};


//게임 동작을 통제하는 클래스
class GameManager {
private:
	//인터페이스 클래스의 객체 생성
	interFace itf;
	//x좌표, y좌표
	int posX;
	int posY;
	//'h'를 입력한 위치에 돌이 있는지 확인
	int check[15][15];
	//돌의 색깔(true = 흑돌, false = 백돌)
	bool colorOfStone;
	bool checkError;
public:
	GameManager();
	~GameManager();
	int getX();
	int getY();
	bool moveX(int direction);
	bool moveY(int direction);
	int getStone(int X, int Y);
	bool getWin(int X, int Y);
};

//오목 판에서 일어나는 일들을 통제하는 클래스
class checkerBoard {
private:
	GameManager gamm; //중요!
	interFace itf;
	int LandPositionX; //착수 위치 x좌표
	int LandPositionY; //착수 위치 y좌표
public:
	checkerBoard();
	~checkerBoard();
	void printCheckerBoard();
	void updateCheckerBoard();
};