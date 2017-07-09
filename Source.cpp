#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include<conio.h>
#include<stdio.h>
using namespace std;

char map[50 ][50 ]; // Mảng 2 chiều các ký tự.
int nSnake;
int Tailx[100], Taily[100];
int nTail=1;
// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width,
		height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle

	(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,

		Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle

	(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void DrawSnake(int x, int y)
{	
		map[x][y] = '0';
}

void PrintMap(int x1,int y1)
{
	int i, j;
	for (i = 0; i < 50; i++)
	{
		for (j = 0; j < 50; j++)
		{
			if (map[i][j] == '*')
			{
				textcolor(14);
				cout << map[i][j];
				textcolor(7);
			}
			else if (map[i][j] == '8')
			{
				textcolor(10);
				cout << map[i][j];
				textcolor(7);
			}			
			else if(map[i][j]!='8'&&map[i][j]!='*')
			{
				cout << map[i][j];
			}
			//else 
			//{
			//	for (int k = 0; k < nTail; k++)
			//	{
			//		if(Tailx[k] == j&&Taily[k] == i)
			//		cout << "o";
			//	}
			//	cout << " ";
			//	
			//}
			else
			{
				bool print = false;
				for (int k = 0; k < nTail; k++)
				{
					if (Tailx[k] == j && Taily[k] == i)
					{
						cout << "0";
						print = true;
					}
				}
				if (!print)
					cout << " ";
			}

		}
		cout << "\n";
	}
}

void DrawMap()
{
	int i, j;
	for (j = 0; j<50; j++)

	{
		map[0][j] = 'x';
	}
	for (i = 1; i<50; i++)
	{
		map[i][50 - 1] = 'x';

	}
	for (j = 50 - 2; j >= 0; j--)
	{
		map[50 - 1][j] = 'x';

	}
	for (i = 50 - 2; i >= 1; i--)
	{
		map[i][0] = 'x';

	}
}

void DrawEm(int x1, int y1)
{
	map[x1][y1] = '8';

}

void DelEm(int x, int y)
{
	map[x][y] = ' ';
}

void DelSnake(int x, int y)
{
	map[x][y] = ' ';

}

void Logic(int &x, int &y,int &x1,int &y1)
{
	int prevX = Tailx[0];
	int PrevY = Taily[0];
	Tailx[0] = x;
	Taily[0] = y;
	int Prev2X, Prev2Y;

	for (int i = 1; i < nTail; i++)
	{
		Prev2X = Tailx[i];
		Prev2Y = Taily[i];
		Tailx[i] = prevX;
		Taily[i] = PrevY;
		prevX = Prev2X;
		PrevY = Prev2Y;
	}
	
	if (GetAsyncKeyState(VK_LEFT))
	{
		DelSnake(x, y);
		y--;
		DrawSnake(x, y);
	}
	else	if (GetAsyncKeyState(VK_RIGHT))
	{
		DelSnake(x, y);
		y++;
		DrawSnake(x, y);
	}
	else	if (GetAsyncKeyState(VK_UP))
	{
		DelSnake(x, y);
		x--;
		DrawSnake(x, y);
	}
	else	if (GetAsyncKeyState(VK_DOWN))
	{
		DelSnake(x, y);
		x++;
		DrawSnake(x, y);
	}
	//else if (map[x][y] == '8')
	//{
	//	DelEm(x1, y1);
	//	int x1 = rand() % 39, y1 =rand()%36;
	//	DrawEm(x1, y1);
	//}
}

void Proceed(int x, int y)
{
	if (map[x][y] == '*')
	{
		textcolor(14);
		gotoxy(52, 6);
		cout << "LOST";
	}
}

void Score(int Score1)
{
	XoaManHinh();
	gotoxy(51, 5);
	cout << "SCORE :";
	gotoxy(60, 5);
	cout << Score1;
}

int main()
{
	resizeConsole(700,2* 500);
	srand(time(NULL));
	int x =rand()%38,y = x + 2;
	int x1 = rand() % 39, y1 = x1;
	int Score1 = 0;
	while (true)
	{
		XoaManHinh();
		DrawSnake(x, y);

		DrawMap();
		DelEm(x1, y1);
		DrawEm(x1, y1);
		if (map[x][y] == '8')
		{
			DelEm(x1, y1);
			x1 = rand() % 39, y1 = rand() % 36;
			DelEm(x1, y1);
			DrawEm(x1, y1);
			Score1 += 10;
			nTail++;
		}
		Proceed(x, y);
		Logic(x, y,x1,y1);
		PrintMap(x1,y1);
		Score(Score1);
		Sleep(10);
	}

	_getch();
	return 0;
}
