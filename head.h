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
	void printMessage();
};


 
//���� ������ �����ϴ� Ŭ����
class GameManager {
private:
	int posX;
	int posY;

public:
	GameManager();
	~GameManager();
	int getX();
	int getY();
	bool moveX(int direction);
	bool moveY(int direction);
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