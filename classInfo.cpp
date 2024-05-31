#include "head.h"

//전역함수 선언
void gotoxy(int x, int y);

/************************************************************************
   인터페이스 칸에서 벌어지는 일들을 통제하는 클래스들의 선언부 정의
*************************************************************************/

// 디폴트 생성자 : 인터페이스 격자위치 출력을 위해 값 초기화
interFace::interFace()
    :showInfoX(35), showInfoY(0) {
}

//인터페이스 소멸자
interFace::~interFace() {}

//멤버함수 정의
void interFace::printGrid() {
    //명령어의 정보를 알려주는 그리드의 칸 출력
    gotoxy(showInfoX, showInfoY); //커서 위치 이동
    for (int i = 0; i < 40; i++) {
        cout << "-";
    }
    for (int i = 1; i < 14; i++) {
        gotoxy(showInfoX, showInfoY + i);
        cout << "|";
        gotoxy(showInfoX + 39, showInfoY + i);
        cout << "|";
    }
    gotoxy(showInfoX, showInfoY + 14);
    for (int i = 0; i < 40; i++) {
        cout << "-";
    }

    //명령어 설명 내용을 그리드 내에 출력
    gotoxy(showInfoX + 3, showInfoY + 8);
    cout << "w키 : 위로 한칸 이동.";
    gotoxy(showInfoX + 3, showInfoY + 9);
    cout << "a키 : 왼쪽로 한칸 이동.";
    gotoxy(showInfoX + 3, showInfoY + 10);
    cout << "s키 : 아래로 한칸 이동.";
    gotoxy(showInfoX + 3, showInfoY + 11);
    cout << "d키 : 오른쪽으로 한칸 이동.";
    gotoxy(showInfoX + 3, showInfoY + 12);
    cout << "h키 : 오목 판에 착수.";
}

//현재 착수해야 하는 플레이어를 알려주는 멤버함수 정의
void interFace::printMessage(string message) {
    gotoxy(38, 5);
    cout << message;
}

//잘못된 키를 입력한 경우 오류 메시지를 출력하는 멤버함수 정의
void interFace::printWrongKey(string message) {
    gotoxy(38, 2);
    cout << message;
}

/************************************************************************
   오목 판에서 벌어지는 일들을 통제하는 클래스들의 선언부 정의
*************************************************************************/


//오목판 클래스 디폴트 생성자 : 착수 시작 위치는 0,0에서 시작, 착수할 오목판 생성 및 인터페이스 격자, 정보 생성
checkerBoard::checkerBoard()
{
    LandPositionX = LandPositionY = 0;
    printCheckerBoard();
    itf.printGrid();
}

//오목판 클래스 소멸자
checkerBoard::~checkerBoard() {}


//오목판 출력 멤버함수
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


//오목판 착수 멤버함수 : 각 입력에 따라 커서를 움직이고, 착수를 누르면 해당 위치에 오목알 배치
void checkerBoard::updateCheckerBoard() {
    //오목판 커서의 시작 위치 0.0
    gotoxy(38, 5);
    cout << "흑돌을 놓을 차례입니다";
    gotoxy(0, 0);

    //사용자의 입력이 오목판을 벗어날 경우 경고문 출력하고 게임 이어서 진행
    while (1) {
        int direction; //명령어를 저장할 변수 선언
        int flag;
        bool state; //현재 상태를 저장할 변수 선언
        direction = _getch(); //키보드로 명령 입력 하면 아스키코드로 변환되어 저장

        flag = 1; //flag 값 1로 초기화

        //각 입력에 따른 상태 초기화
        switch (direction) {
            case 'w': state = gamm.moveY(-1);
                break;
            case 'a': state = gamm.moveX(-1);
                break;
            case 's': state = gamm.moveY(1);
                break;
            case 'd': state = gamm.moveX(1);
                break;
            case 'h':
                flag = gamm.getStone(gamm.getX(), gamm.getY());
                if (flag == 1) state = true;
                else if (flag == 2) state = false;
                break;
            default: //default에 해당하는 값은 잘못된 값을 입력하는 경우, 구분하기 위하여 flag에 0값 대입
                state = 0;
                flag = 0;
                break;
        }

        //만약 명령에 따른 상태가 참(격자 안에 머문 경우)인 경우
        if (state) {
            itf.printWrongKey("                            \r");
            gotoxy(gamm.getX() * 2, gamm.getY()); //GameManager 멤버함수로부터 x와 y 값 불러와서 커서 이동
        }
        else {
            if (flag == 0) { //잘못된 명령으로 인한 오류인 경우
                itf.printWrongKey("잘못된 명령어입니다.    \r");
            }
            else if (flag == 1) { //오목판을 벗어나서 발생한 오류인 경우
                itf.printWrongKey("오목판을 벗어났습니다.  \r");
            }
            else if (flag == 2) { //이미 돌이 있는 위치에 착수한 경우
                itf.printWrongKey("돌을 다른 곳에 두세요!!\r");
            }
            gotoxy(gamm.getX() * 2, gamm.getY());
        }
    }
}

/************************************************************************
   게임 동작을 통제하는 클래스의 선언부 정의
*************************************************************************/

GameManager::GameManager()
{
    //게임 매니져의 x와 y값 0으로 초기화
    //흑돌이 선공으로 게임 시작
    //착수할 위치에 돌이 있는지 확인하는 check 배열 0으로 초기화
    posX = posY = 0;
    colorOfStone = 1;
    for (int i = 0; i < 15; ++i) {
        for (int j = 0; j < 15; ++j) {
            check[i][j] = 0;
        }
        checkError = false;
    }
}

//소멸자
GameManager::~GameManager() { }

//게임매니져의 x값(커서 위치 x값)을 반환
int GameManager::getX() {
    return posX;
}

//게임 매니져의 y(커서 위치 y값)값을 반환
int GameManager::getY() {
    return posY;
}

//x축 이동
bool GameManager::moveX(int direction) {
    //방어코드 : 해당 이동이 오목판 밖으로 나가게되면, 0을 반환
    if (posX + direction < 0 || posX + direction >= SIZE) {
        return false;
    }
    //해당 이동이 오목판 내에 존재하면, 해당 값을 반영하고 1을 반환
    posX += direction;
    return true;
}

//y축 이동 
bool GameManager::moveY(int direction) {
    //방어코드 : 해당 이동이 오목판 밖으로 나가게되면, 0을 반환
    if (posY + direction < 0 || posY + direction >= SIZE) {
        return false;
    }
    //해당 이동이 오목판 내에 존재하면, 해당 값을 반영하고 1을 반환
    posY += direction;
    return true;
}

/*
'h'를 입력했을때
(1)흑돌 착수 -> 안내문 출력, 커서 위치의 바둑판에 ○을 출력
   백돌 착수 -> 안내문 출력, 커서 위치에 바둑판 ●을 출력
(2)만약 커서위치에 돌이 이미 놓여져 있으면
   "돌을 다른 곳에 두세요 !!" 출력후 턴 이어가기
(3)돌을 놓을 때마다 알고리즘을 돌려 오목이 완성되는지 판단.
   만약 5개의 돌이 놓여져 오목이 완성되면 안내문 출력하고 프로그램종료
*/
int GameManager::getStone(int X, int Y) {
    checkError = check[X][Y] ? true : false;

    if (checkError) {
        return 2;
    }
    else {
        gotoxy(X * 2, Y);
        if (colorOfStone == true) { //흑돌부터 게임 시작
            //착수
            check[X][Y] = 1;
            printf("○");
            //턴을 넘김
            colorOfStone = false;
            if (getWin(X, Y)) { //흑돌의 오목이 완성된 경우
                itf.printMessage("흑돌이 이겼습니다. !!!");
                gotoxy(0, 20);
                Sleep(1000);
                exit(0); //게임종료
            }
            else itf.printMessage("백돌을 놓을 차례입니다.");
        }
        else { //백돌 시작
            check[X][Y] = 2;
            printf("●");
            //턴을 넘김
            colorOfStone = true;
            if (getWin(X, Y)) { //백돌의 오목이 완성된 경우
                itf.printMessage("백돌이 이겼습니다. !!!");
                gotoxy(0, 20);
                Sleep(1000);
                exit(0);
            }
            else itf.printMessage("흑돌을 놓을 차례입니다.");
        }

        return 1;
    }
}

//오목 완성 검사
bool GameManager::getWin(int X, int Y) {
    int cnt;
    int color = check[X][Y]; // 1:흑돌, 2:백돌

    // 가로 방향으로 돌이 5개 있는지 판별
    cnt = 1;
    int row = 1;
    while (check[X + row++][Y] == color) { cnt++; } //동쪽으로 이동(->)하며 검사
    row = 1;
    while (check[X - row++][Y] == color) { cnt++; } //서쪽으로 이동(<-)하며 검사
    if (cnt == 5) return true;

    // 세로 방향으로 돌이 5개 있는지 판별
    cnt = 1;
    int col = 1;
    while (check[X][Y + col++] == color) { cnt++; } //남쪽으로 이동하며 검사
    col = 1;
    while (check[X][Y - col++] == color) { cnt++; } //북쪽으로 이동하며 검사
    if (cnt == 5) return 1;

    //대각선(왼쪽아래 ~ 오른쪽 위) 방향으로 돌이 5개 있는지 판별
    cnt = 1;
    int diag = 1;
    while (check[X - diag][Y + diag] == color) { //왼쪽 아래로 이동하며 검사
        cnt++;
        diag++;
    }
    diag = 1;
    while (check[X + diag][Y - diag] == color) { //오른쪽 위로 이동하며 검사
        cnt++;
        diag++;
    }
    if (cnt == 5) return 1;

    //대각선(왼쪽위 ~ 오른쪽 아래) 방향으로 돌이 5개 있는지 판별
    cnt = 1;
    diag = 1;
    while (check[X + diag][Y + diag] == color) { //오른족 아래로 이동하며 검사
        cnt++;
        diag++;
    }
    diag = 1;
    while (check[X - diag][Y - diag] == color) { //왼쪽 위로 이동하며 검사
        cnt++;
        diag++;
    }
    if (cnt == 5) return 1;

    return false;
}

/************************************************************************
   전역 함수 정의 : 해당 위치로 커서를 이동하는 함수
*************************************************************************/

//windows.h 헤더파일에 있음
void gotoxy(int x, int y) {
    COORD pos; //COORD 커서의 위치를 저장하는 구조체
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}