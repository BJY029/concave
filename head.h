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

//�������̽� ĭ���� �Ͼ�� �ϵ��� �����ϴ� Ŭ����
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

//���� �ǿ��� �Ͼ�� �ϵ��� �����ϴ� Ŭ����
class checkerBoard {
private:
	int LandPositionX;
	int LandPositionY;
public:
	checkerBoard();
	~checkerBoard();
	void printCheckerBoard();
};