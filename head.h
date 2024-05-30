#pragma once
#include<Windows.h>
#include<cstdio>
#include<conio.h>
#include<array>
#include<cstring>
#include<iostream>
#define SIZE 15
#define LOCATION 15
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
	void printWrongKey(string message);
};


//���� ������ �����ϴ� Ŭ����
class GameManager {
private:
	interFace itf;
	// x��ǥ, y��ǥ
	int posX;
	int posY;
	//'h'�� �Է��� ��ġ�� ���� �ִ��� Ȯ��
	int check[15][15];
	// ���� ����(false = �浹, true = �鵹)
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
};

//gameManager Ŭ�������� �¸� ���� �Ǵ� �Լ� ����
//2���� �迭�� �¸� ���� �Ǵ�
//������ ��ü�� �迭�� �籸��
//2���� �迭�� 0������ �ʱ�ȭ
//�� �÷��̾ � ��ġ�� ������ �����ϸ�
//�ش� ��ġ�� 2�����迭 �ε����� �ش� �÷��̾��� ��ȣ �Է�
//ex) �÷��̾� 1�� �������� (10, 14)��ġ�� ���� -> ������ �迭[10][24] ��ġ�� 1 ����
//�� ��, ���� ��ġ ����,(������, �����밢��, �Ʒ�, �޴밢��)�� ���ʴ�� �˻��Ͽ���
//5���� ���ӵ� �� �߽߰� �¸� ���� �� ����

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