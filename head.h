#pragma once
#include<Windows.h>
#include<cstdio>
#include<conio.h>
#include<array>
#include<cstdio>
#include<cstring>
#include<iostream>
#define SIZE 15
#define LOCATION 15
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
	void printMessage();
};

//오목 판에서 일어나는 일들을 통제하는 클래스
class checkerBoard {
private:
	int LandPositionX; //착수 위치 x좌표
	int LandPositionY; //착수 위치 y좌표
public:
	checkerBoard();
	~checkerBoard();
	void printCheckerBoard();
};
 
//게임 동작을 통제하는 클래스
class gameManager {
private:

public:

};


//2차원 배열로 승리 조건 판단
//오목판 자체를 배열로 재구현
//2차원 배열을 0값으로 초기화
//각 플레이어가 어떤 위치에 착수를 진행하면
//해당 위치의 2차원배열 인덱스에 해당 플레이어의 번호 입력
//ex) 플레이어 1이 오목판의 (10, 14)위치에 착수 -> 이차원 배열[10][24] 위치에 1 대입
//그 후, 착수 위치 기준, 오른쪽, 오른대각선, 아래, 왼대각선을 차례대로 검사하여서
//5개의 연속된 돌 발견시 승리 판정 후 종료