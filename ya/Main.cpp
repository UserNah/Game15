#include <iostream> 
#include <ctime> 

using namespace std;

enum EMove { keyUp = 'w', keyDown = 's', keyLeft = 'a', keyRight = 'd' };

void InitializeBoard(char[4][4]); //Инициализация доски
void PrintBoard(char[4][4]); //Вывод содержимое(changed type) доски на экран
void LocateSpace(int&, int&, char[4][4]); // возвращение координаты пустой клетки
void Randomize(char[4][4]);
void Move(char[4][4], const EMove);

int main()
{	cout << "Your mission is lead in a form:\n";
	cout << "1 2 3 4\n";
	cout << "5 6 7 8\n";
	cout << "9 A B C\n";
	cout << "D E F\n\n";
	cout << "Good Luck!\n\n\n\n\n";
	char caaBoard[4][4];
	InitializeBoard(caaBoard);
	Randomize(caaBoard);

	
	do
	{
		PrintBoard(caaBoard);
		cout << endl << "Enter w = Up, s = Down, a = Left, d = Right" << endl;
		char cNextMove;
		cin >> cNextMove;
		EMove eNextMove = (EMove)cNextMove;
		Move(caaBoard, eNextMove);
		cout << endl;
	} while (true);

	return EXIT_SUCCESS;
}

void InitializeBoard(char caaBoard[4][4])
{
	const char kcaaInitial[4][4] = 
	{
	{ '1', '2', '3', '4' },
	{ '5', '6', '7', '8' },
	{ '9', 'A', 'B', 'C' },
	{ 'D', 'E', 'F', ' ' } 
	};
	for (int iRow = 0; iRow < 4; ++iRow)
		for (int iCol = 0; iCol < 4; ++iCol)
			caaBoard[iRow][iCol] = kcaaInitial[iRow][iCol];
}

void PrintBoard(char caaBoard[4][4])
{
	for (int iRow = 0; iRow < 4; ++iRow)
	{
		for (int iCol = 0; iCol < 4; ++iCol)
			cout << caaBoard[iRow][iCol];
		cout << endl;
	}
}

void LocateSpace(int& irRow, int& irCol, char caaBoard[4][4])
{
	for (int iRow = 0; iRow < 4; ++iRow)
		for (int iCol = 0; iCol < 4; ++iCol)
			if (caaBoard[iRow][iCol] == ' ')
			{
				irRow = iRow;
				irCol = iCol;
			}
}

void Randomize(char caaBoard[4][4])
{
	srand((unsigned int)time(0));
	for (int iIndex = 0; iIndex < 1000; ++iIndex)
	{
		const int kiNextMove = (rand() % 4);
		switch (kiNextMove)
		{
			case 0:
			{
				Move(caaBoard, keyUp);
				break;
			}
			case 1:
			{
				Move(caaBoard, keyDown);
				break;
			}
			case 2:
			{
				Move(caaBoard, keyLeft);
				break;
			}	
			case 3:
			{
				Move(caaBoard, keyRight);
				break;
			}
		}
	}
}

void Move(char caaBoard[4][4], const EMove keyMove)
{
	int iRowSpace;
	int iColSpace;
	LocateSpace(iRowSpace, iColSpace, caaBoard);
	int iRowMove(iRowSpace);
	int iColMove(iColSpace);
	switch (keyMove)
	{
	case keyUp:
	{
		iRowMove = iRowSpace + 1;
		break;
	}
	case keyDown:
	{
		iRowMove = iRowSpace - 1;
		break;
	}
	case keyLeft:
	{
		iColMove = iColSpace + 1;
		break;
	}
	case keyRight:
	{
		iColMove = iColSpace - 1;
		break;
	}
	}
	// Make sure that the square to be moved is in bounds 

	if (iRowMove >= 0 && iRowMove < 4 && iColMove >= 0 && iColMove < 4)
	{
		caaBoard[iRowSpace][iColSpace] = caaBoard[iRowMove][iColMove];
		caaBoard[iRowMove][iColMove] = ' ';
	}
}