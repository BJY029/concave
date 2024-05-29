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
	int showInfoX;
	int showInfoY;
public:
	interFace();
	~interFace();
	void printGrid();
	void printMessage();
};

//오목 판에서 일어나는 일들을 통제하는 클래스
class checkerBoard {
private:
	int LandPositionX;
	int LandPositionY;
public:
	checkerBoard();
	~checkerBoard();
	void printCheckerBoard();
};