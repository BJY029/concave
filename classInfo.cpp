#include "head.h"

//�����Լ� ����
void gotoxy(int x, int y);


/************************************************************************
   �������̽� ĭ���� �������� �ϵ��� �����ϴ� Ŭ�������� ����� ����
*************************************************************************/

// ����Ʈ ������ : �������̽� ������ġ ����� ���� �� �ʱ�ȭ
interFace::interFace()
    :showInfoX(35), showInfoY(0) {
}

//�������̽� �Ҹ���
interFace::~interFace() {}



//����Լ� ����
void interFace::printGrid() {


    //��ɾ��� ������ �˷��ִ� �׸����� ĭ ���
    gotoxy(showInfoX, showInfoY); //Ŀ�� ��ġ �̵�
    for (int i = 0; i < 31; i++) {
        cout << "-";
    }
    for (int i = 1; i < 14; i++) {
        gotoxy(showInfoX, showInfoY + i);
        cout << "|";
        gotoxy(showInfoX + 30, showInfoY + i);
        cout << "|";
    }
    gotoxy(showInfoX, showInfoY + 14);
    for (int i = 0; i < 31; i++) {
        cout << "-";
    }

    //��ɾ� ���� ������ �׸��� ���� ���
    gotoxy(showInfoX + 2, showInfoY + 8);
    cout << "wŰ : ���� ��ĭ �̵�.";
    gotoxy(showInfoX + 2, showInfoY + 9);
    cout << "aŰ : ���ʷ� ��ĭ �̵�.";
    gotoxy(showInfoX + 2, showInfoY + 10);
    cout << "sŰ : �Ʒ��� ��ĭ �̵�.";
    gotoxy(showInfoX + 2, showInfoY + 11);
    cout << "dŰ : ���������� ��ĭ �̵�.";
    gotoxy(showInfoX + 2, showInfoY + 12);
    cout << "hŰ : ���� �ǿ� ����.";
    gotoxy(showInfoX + 2, showInfoY + 13);
    cout << "rŰ : �� �� ������.";


}

//���� �����ؾ� �ϴ� �÷��̾ �˷��ִ� ����Լ� ����
void interFace::printMessage(string message) {
    gotoxy(38, 5);
    cout << message;
}

//�߸��� Ű�� �Է��� ��� ���� �޽����� ����ϴ� ����Լ� ����
void interFace::printWrongKey(string message) {
    gotoxy(38, 2);
    cout << message;
}

/************************************************************************
   ���� �ǿ��� �������� �ϵ��� �����ϴ� Ŭ�������� ����� ����
*************************************************************************/


//������ Ŭ���� ����Ʈ ������ : ���� ���� ��ġ�� 0,0���� ����, ������ ������ ���� �� �������̽� ����, ���� ����
checkerBoard::checkerBoard()
{
    LandPositionX = LandPositionY = 0;
    printCheckerBoard();
    itf.printGrid();
}

//������ Ŭ���� �Ҹ���
checkerBoard::~checkerBoard() {}


//������ ��� ����Լ�
void checkerBoard::printCheckerBoard() {

    cout << "��";
    for (int i = 0; i < SIZE - 2; i++) {
        cout << "-��";
    }
    cout << "-��";


    for (int i = 0; i < SIZE - 2; i++) {
        gotoxy(0, i + 1);
        cout << "��";
        for (int j = 0; j < SIZE - 2; j++) {
            cout << "-��";
        }
        cout << "-��";

    }
    gotoxy(0, 14);
    cout << "��";
    for (int i = 0; i < SIZE - 2; i++) {
        cout << "-��";
    }
    cout << "-��" << endl;


}

//������ ���� ����Լ� : �� �Է¿� ���� Ŀ���� �����̰�, ������ ������ �ش� ��ġ�� ����� ��ġ
void checkerBoard::updateCheckerBoard() {
    //������ Ŀ���� ���� ��ġ 0.0
    gotoxy(38, 5);
    cout << "�浹�� ���� �����Դϴ�";
    gotoxy(0, 0);

    int drawCount = 0;
    //������� �Է��� �������� ��� ��� ��� ����ϰ� ���� �̾ ����
    while (1) {
        int direction; //��ɾ ������ ���� ����
        bool cancle_check;
        int flag;
        bool state; //���� ���¸� ������ ���� ����
        direction = _getch(); //Ű����� ��� �Է� �ϸ� �ƽ�Ű�ڵ�� ��ȯ�Ǿ� ����

        flag = 1; //flag �� 1�� �ʱ�ȭ

        //�� �Է¿� ���� ���� �ʱ�ȭ
        switch (direction) {
            case 'w': state = gamm.moveY(-1);
                break;
            case 'a': state = gamm.moveX(-1);
                break;
            case 's': state = gamm.moveY(1);
                break;
            case 'd': state = gamm.moveX(1);
                break;
            case 'r':
                cancle_check = gamm.cancel(); //������ �Լ� �ߵ�
                if (cancle_check) drawCount--;//���� �����Ⱑ �����ϸ�, drawCount�� -1
                state = false; //state�� �ʱ�ȭ ���� ������ ���� �߻�
                flag = 4; //�ƹ��͵� �������� �ʱ� ���� flag �� ����
                break;
            case 'h':
                flag = gamm.getStone(gamm.getX(), gamm.getY());
                if (flag == 1) {
                    drawCount++;
                    state = true;
                }
                else if (flag == 2) state = false;
                break;
            default: //default�� �ش��ϴ� ���� �߸��� ���� �Է��ϴ� ���, �����ϱ� ���Ͽ� flag�� 0�� ����
                state = 0;
                flag = 0;
                break;
        }

        //���� ��ɿ� ���� ���°� ��(���� �ȿ� �ӹ� ���)�� ���
        if (state) {
            itf.printWrongKey("                          \r");
            gotoxy(gamm.getX() * 2, gamm.getY()); //GameManager ����Լ��κ��� x�� y �� �ҷ��ͼ� Ŀ�� �̵�
            if (drawCount == 225) {
                itf.printWrongKey("���º�! ����Ŀ� ����� �մϴ�.\r");
                Sleep(2000);
                gotoxy(38, 2);
                cout << "                              ";
                gamm.initAll();
            }
        }
        else {
            if (flag == 0) { //�߸��� ������� ���� ������ ���
                itf.printWrongKey("�߸��� ��ɾ��Դϴ�.    \r");
                gotoxy(gamm.getX() * 2, gamm.getY());
            }
            else if (flag == 1) { //�������� ����� �߻��� ������ ���
                itf.printWrongKey("�������� ������ϴ�.  \r");
                gotoxy(gamm.getX() * 2, gamm.getY());
            }
            else if (flag == 2) { //�̹� ���� �ִ� ��ġ�� ������ ���
                itf.printWrongKey("���� �ٸ� ���� �μ���!!\r");
                gotoxy(gamm.getX() * 2, gamm.getY());
            }

        }
    }
}



/************************************************************************
   ���� ������ �����ϴ� Ŭ������ ����� ����
*************************************************************************/

GameManager::GameManager()
{
    //���� �Ŵ����� x�� y�� 0���� �ʱ�ȭ
    //�浹�� �������� ���� ����
    //������ ��ġ�� ���� �ִ��� Ȯ���ϴ� check �迭 0���� �ʱ�ȭ
    posX = posY = 0;
    colorOfStone = 1;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            check[i][j] = 0;
        }
        checkError = false;
    }
    moveWHistory.clear();
    moveBHistory.clear();
}

//�Ҹ���
GameManager::~GameManager() { }

//���ӸŴ����� x���� ��ȯ
int GameManager::getX() {
    return posX;
}

//���� �Ŵ����� y���� ��ȯ
int GameManager::getY() {
    return posY;
}

//x�� �̵�
bool GameManager::moveX(int direction) {
    //����ڵ� : �ش� �̵��� ������ ������ �����ԵǸ�, 0�� ��ȯ
    if (posX + direction < 0 || posX + direction >= SIZE) {
        return false;
    }
    //�ش� �̵��� ������ ���� �����ϸ�, �ش� ���� �ݿ��ϰ� 1�� ��ȯ
    posX += direction;
    return true;
}

//y�� �̵� 
bool GameManager::moveY(int direction) {
    //����ڵ� : �ش� �̵��� ������ ������ �����ԵǸ�, 0�� ��ȯ
    if (posY + direction < 0 || posY + direction >= SIZE) {
        return false;
    }
    //�ش� �̵��� ������ ���� �����ϸ�, �ش� ���� �ݿ��ϰ� 1�� ��ȯ
    posY += direction;
    return true;
}

/*
'h'�� �Է�������
(1)�浹 ���� -> �ȳ��� ���, Ŀ�� ��ġ�� �ٵ��ǿ� ���� ���
   �鵹 ���� -> �ȳ��� ���, Ŀ�� ��ġ�� �ٵ��� ���� ���
(2)���� Ŀ����ġ�� ���� �̹� ������ ������
   "���� �ٸ� ���� �μ��� !!" ����� �� �̾��
(3)���� ���� ������ �˰����� ���� ������ �ϼ��Ǵ��� �Ǵ�.
   ���� 5���� ���� ������ ������ �ϼ��Ǹ� �ȳ��� ����ϰ� ���α׷�����
*/
int GameManager::getStone(int X, int Y) {
    checkError = check[X][Y] ? true : false;
    static int b_victory = 0, w_victory = 0;
    moveHistory.push_back(make_pair(X * 2, Y));
    if (checkError) {
        return 2;
    }
    else {
        gotoxy(X * 2, Y);
        if (colorOfStone == true) { //�浹���� ���� ����
            //����
            check[X][Y] = 1;
            printf("��");

            if (getWin(X, Y)) { //�浹�� ������ �ϼ��� ���
                itf.printMessage("�浹�� �̰���ϴ�. !!!");
                b_victory++;
                gotoxy(0, 18);
                cout << "�浹 " << b_victory << " : " << "�鵹 " << w_victory << endl;
                if (b_victory == 3) {
                    gotoxy(0, 19);
                    cout << "�浹�� ���� 3���� �޼��߽��ϴ�!\n" << "������ �����մϴ�." << endl;
                    exit(0);
                }
                else {
                    gotoxy(0, 19);
                    cout << "�浹�� �¸��߽��ϴ�.\n" << "����� ������ ����۵˴ϴ�." << endl;
                    Sleep(2000);
                    gotoxy(0, 19);
                    cout << "                         \n" << "                              " << endl;
                }
                initAll(); //�ʱ�ȭ �Լ� �ҷ�����
            }
            else {
                //���� �ѱ�
                itf.printMessage("�鵹�� ���� �����Դϴ�.");
                colorOfStone = false;
            }
        }
        else { //�鵹 ����
            check[X][Y] = 2;
            printf("��");
            //���� �ѱ�
            colorOfStone = true;
            if (getWin(X, Y)) { //�鵹�� ������ �ϼ��� ���
                itf.printMessage("�鵹�� �̰���ϴ�. !!!");
                w_victory++;
                gotoxy(0, 18);
                cout << "�浹 " << b_victory << " : " << "�鵹 " << w_victory << endl;
                if (w_victory == 3) {
                    gotoxy(0, 19);
                    cout << "�鵹�� ���� 3���� �޼��߽��ϴ�!\n" << "������ �����մϴ�." << endl;
                    exit(0);
                }
                else {
                    gotoxy(0, 19);
                    cout << "�鵹�� �¸��߽��ϴ�.\n" << "����� ������ ����۵˴ϴ�." << endl;
                    Sleep(2000);
                    gotoxy(0, 19);
                    cout << "                         \n" << "                              " << endl;
                }
                initAll(); //�ʱ�ȭ �Լ� �ҷ�����
            }
            else itf.printMessage("�浹�� ���� �����Դϴ�.");
        }
    }


    return 1;
}

//������ �Լ�
bool GameManager::cancel() {

    if (moveHistory.size() == 0) { //���� ���ÿ� �ƹ��͵� ������, ������ ���� ����ϰ� false ��ȯ
        itf.printWrongKey("�����⸦ �� �� �����ϴ�!!\r");
        gotoxy(getX() * 2, getY());
        return false;
    }
    DoAJob(moveHistory.back());
    check[moveHistory.back().first / 2][moveHistory.back().second] = 0; //check �迭 �ʱ�ȭ
    moveHistory.pop_back(); //�浹 ���� pop
    if (colorOfStone == true) {
        colorOfStone = false;
        itf.printMessage("�鵹�� ���� �����Դϴ�.");
    }
    else {
        colorOfStone = true;
        itf.printMessage("�浹�� ���� �����Դϴ�.");
    }
    //������ ������ ��� ���������� �����ϴ� �ڵ��
    itf.printWrongKey("������ ����!!         \r"); //������ ���� ���
    gotoxy(getX() * 2, getY()); //���� Ŀ�� ��ġ�� �̵�
    return true; //true ��ȯ
}

//���� �ϼ� �˻�
bool GameManager::getWin(int X, int Y) {
    int cnt;
    int color = check[X][Y]; // 1:�浹, 2:�鵹

    // ���� �������� ���� 5�� �ִ��� �Ǻ�
    cnt = 1;
    int row = 1;
    while (check[X + row++][Y] == color && X + row <= 15  ) { cnt++; } //�������� �̵�(->)�ϸ� �˻�
    row = 1;
    while (check[X - row++][Y] == color && X - row >= -1) { cnt++; } //�������� �̵�(<-)�ϸ� �˻�
    if (cnt == 5) return true;

    // ���� �������� ���� 5�� �ִ��� �Ǻ�
    cnt = 1;
    int col = 1;
    while (check[X][Y + col++] == color && Y + col <= 15) { cnt++; } //�������� �̵��ϸ� �˻�
    col = 1;
    while (check[X][Y - col++] == color && Y - col >= -1) { cnt++; } //�������� �̵��ϸ� �˻�
    if (cnt == 5) return 1;

    //�밢��(���ʾƷ� ~ ������ ��) �������� ���� 5�� �ִ��� �Ǻ�
    cnt = 1;
    int diag = 1;
    while (check[X - diag][Y + diag] == color) { //���� �Ʒ��� �̵��ϸ� �˻�
        cnt++;
        diag++;
    }
    diag = 1;
    while (check[X + diag][Y - diag] == color) { //������ ���� �̵��ϸ� �˻�
        cnt++;
        diag++;
    }
    if (cnt == 5) return 1;

    //�밢��(������ ~ ������ �Ʒ�) �������� ���� 5�� �ִ��� �Ǻ�
    cnt = 1;
    diag = 1;
    while (check[X + diag][Y + diag] == color) { //������ �Ʒ��� �̵��ϸ� �˻�
        cnt++;
        diag++;
    }
    diag = 1;
    while (check[X - diag][Y - diag] == color) { //���� ���� �̵��ϸ� �˻�
        cnt++;
        diag++;
    }
    if (cnt == 5) return 1;

    return false;
}

void GameManager::initAll() {
    gotoxy(0, 0);
    GameManager; //check�迭, �Ŵ����� x,y �ʱ�ȭ
    checkerBoard ckboard; //checkerBoard ���� ���� �� ������ ȣ��
    ckboard.updateCheckerBoard(); //���� �����
}

void GameManager::DoAJob(pair<int, int> info) {
    pair<int, int> lastXY = info;

    if (lastXY.first == 0) {
        if (lastXY.second == 0) {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
        else if (lastXY.second == 14) {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
        else {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
    }
    else if (lastXY.first == 28) {
        if (lastXY.second == 0) {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
        else if (lastXY.second == 14) {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
        else {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
    }
    else {
        if (lastXY.second == 0) {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
        else if (lastXY.second == 14) {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
        else {
            gotoxy(lastXY.first, lastXY.second);
            cout << "��";
        }
    }
}

/************************************************************************
   ���� �Լ� ���� : �ش� ��ġ�� Ŀ���� �̵��ϴ� �Լ�
*************************************************************************/

void gotoxy(int x, int y) {
    COORD pos; //COORD Ŀ���� ��ġ�� �����ϴ� ����ü
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}