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
	int showInfoX; //�������̽� �ܰ� ���� ����ϱ� ���� x��ǥ ����
	int showInfoY; //�������̽� �ܰ� ���� ����ϱ� ���� y��ǥ ����
public:
	interFace();
	~interFace();
	void printGrid();
	void printMessage();
};

//���� �ǿ��� �Ͼ�� �ϵ��� �����ϴ� Ŭ����
class checkerBoard {
private:
	int LandPositionX; //���� ��ġ x��ǥ
	int LandPositionY; //���� ��ġ y��ǥ
public:
	checkerBoard();
	~checkerBoard();
	void printCheckerBoard();
};
 
//���� ������ �����ϴ� Ŭ����
class gameManager {
private:

public:

};


//2���� �迭�� �¸� ���� �Ǵ�
//������ ��ü�� �迭�� �籸��
//2���� �迭�� 0������ �ʱ�ȭ
//�� �÷��̾ � ��ġ�� ������ �����ϸ�
//�ش� ��ġ�� 2�����迭 �ε����� �ش� �÷��̾��� ��ȣ �Է�
//ex) �÷��̾� 1�� �������� (10, 14)��ġ�� ���� -> ������ �迭[10][24] ��ġ�� 1 ����
//�� ��, ���� ��ġ ����, ������, �����밢��, �Ʒ�, �޴밢���� ���ʴ�� �˻��Ͽ���
//5���� ���ӵ� �� �߽߰� �¸� ���� �� ����