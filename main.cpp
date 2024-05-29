#include "head.h"

int main() {
	system("mode con: cols=150 lines=150");
	interFace iF;
	checkerBoard cB;
	cB.printCheckerBoard();
	iF.printGrid();
	Sleep(3000);
	return 0;
}