#pragma once
#include<Windows.h>
#include<cstdio>
#include<conio.h>
#include<array>
#include<cstring>
#include<iostream>
#define SIZE 15
using namespace std;

//�������̽� ĭ���� �Ͼ�� �ϵ��� �����ϴ� Ŭ����
class interFace {
private:
	int showInfoX; //�������̽� �ܰ� ���� ����ϱ� ���� x��ǥ ����
	int showInfoY; //�������̽� �ܰ� ���� ����ϱ� ���� y��ǥ ����
public:
	interFace();
	~interFace();
	void printGrid();
	void printMessage(string message);
	void printWrongLand(string message);
	void printWrongKey(string message);
};


//���� ������ �����ϴ� Ŭ����
class GameManager {
private:
	//�������̽� Ŭ������ ��ü ����
	interFace itf;
	//x��ǥ, y��ǥ
	int posX;
	int posY;
	//'h'�� �Է��� ��ġ�� ���� �ִ��� Ȯ��
	int check[15][15];
	//���� ����(true = �浹, false = �鵹)
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

//���� �ǿ��� �Ͼ�� �ϵ��� �����ϴ� Ŭ����
class checkerBoard {
private:
	GameManager gamm; //�߿�!
	interFace itf;
	int LandPositionX; //���� ��ġ x��ǥ
	int LandPositionY; //���� ��ġ y��ǥ
public:
	checkerBoard();
	~checkerBoard();
	void printCheckerBoard();
	void updateCheckerBoard();
};