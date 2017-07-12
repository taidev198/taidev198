#include <iostream>
#include <string>
#include <Windows.h>
#include <ctime>
#include<conio.h>
#include<stdio.h>
using namespace std;

char map[50*2][50*2]; // Mảng 2 chiều các ký tự.
int Score = 0;
void Draw(int x, int y);
void DrawPlayer(int x, int y);
void Print();
void DrawEm(int x, int y);
void Draw(int x, int y);
void DrawMap();
void DrawBound(int x, int y);
void DelBound(int x, int y);
void Procced();

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


void DrawPlayer(int x, int y)
{

	int i, j;
	for (i = x+2; i >=x+1 ; i--)
	{
		for (j=y;j<y+3;j++)
			map[i][j] = '*';
	}
	map[x ][y +1] = '*';
	//Draw(x + 1, y + 2);
}


void Print()
{
	int i, j;
	for(i=0;i<50;i++)
	{
		for (j = 0; j < 50; j++)
		{
			if (map[i][j] == '*')
			{
				textcolor(14);
				cout << map[i][j];
				textcolor(7);
			}
			else if(map[i][j]=='0')
			{
				textcolor(10);
				cout << map[i][j];
				textcolor(7);
			}
			else
			{
				cout << map[i][j];
			}
		}
			
		cout << "\n";
	}
}

void DrawEm(int x, int y)
{

	int i, j;
	for (i = x; i < x + 2; i++)
	{
		for (j = y; j<y + 3; j++)
			map[i][j] = '0';
	}
	map[x+2][y + 1] = '0';
}

void DrawBound(int x, int y)
{
	map[x-1][y + 1] = 'o';
}

void DrawBoundLeft(int x, int y)
{
			map[x ][y - 2] = 'o';
}

void DrawBoundRight(int x, int y)
{
	map[x ][y + 2] = 'o';
}

void DelBoundLeft(int x, int y)
{
	map[x ][y - 2] = ' ';
}

void DelBoundRight(int x, int y)
{
	map[x ][y + 2] = ' ';
}

void DelBound(int x, int y)
{
	map[x-1][y+1] = ' ';
}


void Draw(int x, int y)
{
	map[x][y] = '*';
}


void DrawMap()
{
	int i, j;
	for (j = 0; j<50; j++)

	{
		map[0][j] = '*';
	}
	for (i = 1; i<50; i++)
	{
		 map[i][50 - 1]='*';
		
	}
	for (j = 50 - 2; j >= 0; j--)
	{
		 map[50 - 1][j]='*';
		
	}
	for (i = 50 - 2; i >= 1; i--)
	{
		 map[i][0]='*';
	
	}
}



void Proceed(int x,int y)
{
	int i, j;
	for (i = x; i < x + 2; i++)
	{
		for (j = y; j < y + 3; j++)
		{
			if (map[i][j] == '*')
			{
				gotoxy(20, 20);
				textcolor(10);
				cout << "LOST\n";
				textcolor(7);
				system("pause");
			}
		}
	}
	if(map[x + 2][y + 1] == '*')
	{
		gotoxy(20, 20);
		textcolor(10);
		cout << "LOST\n";
		textcolor(7);
		system("pause");
	}
}

void Proceed1(int x, int y)
{

	int i, j;
	for (i = x; i < x + 2; i++)
	{
		for (j = y; j<y + 3; j++)
		{
			if (map[i][j] == 'o')
			{
				gotoxy(20, 20);
				textcolor(10);
				cout << "LOST\n";
				textcolor(7);
				system("pause");
			}
		}
	}
	if(map[x+2][y + 1] == 'o')
		{
		gotoxy(20, 20);
		textcolor(10);
		cout << "LOST\n";
		textcolor(7);
		system("pause");
	}
}

void Point()
{
	//XoaManHinh();
	Score++;
	gotoxy(60, 70);
	textcolor(10);
	cout << Score;
	textcolor(7);
}

int main()
{
	//1 so ngau nhien [a,b] a+rand()%(b-a+1)
	tt: int i, j;
	srand(time(NULL));
	resizeConsole(1200, 950);
	int x = 42, y = 45;
	int x1=  2+ rand() % 30, y1=x1+3;
	int x3 = 2 + rand() % 29, y3 = x3 + 3;
	int x4 = 2 + rand() % 29, y4 = x4 + 3;
	int x2 = x, y2 = y;//  bound 
		
	while (1)
	{
		XoaManHinh();
		DrawPlayer(x, y);	
		DelBound(x2, y2);		
		x2--;
	
		DrawBound(x2, y2);	
			DelBound(x2, y2);
			if(x2==10)
			x2=x;
				DrawBound(x2, y2);
				
		DrawMap();
		//Score++;
		if (GetAsyncKeyState(VK_RIGHT))
		{

			for (j = y + 1; j<y + 3; j++)
			{
				for (i = x; i < x + 3; i++)
					map[i][j] = ' ';
			}
			map[x + 1][y] = ' ';
			for (j = y; j < y + 2; j++)
			{
				for (i = x; i < x + 3; i++)
					map[i][j] = ' ';
			}

			map[x + 1][y + 2] = ' ';
			DelBound(x2, y2);//xoa vi tri hien tai
			DelBoundRight(x2, y);
			y++;
			DrawBoundRight(x2, y);
			DelBoundRight(x2, y);
			map[x][y2] = ' ';
			DrawPlayer(x, y);
		}
		else	if (GetAsyncKeyState(VK_LEFT))
		{
			for (j = y + 1; j<y + 3; j++)
			{
				for (i = x; i < x + 3; i++)
					map[i][j] = ' ';
			}
			map[x + 1][y] = ' ';
			for (j = y + 2; j >= y + 1; j--)
			{
				for (i = x; i < x + 3; i++)
					map[i][j] = ' ';
			}
			map[x + 1][y] = ' ';
			DelBound(x2, y2);
			map[x][y] = ' ';
				map[x2][y]=' ';
			y--;
			map[x2][y2]=' ';
			map[x2][y]=' ';
			map[x][y2] = ' ';
			DrawPlayer(x, y);
		}
		else	if (GetAsyncKeyState(VK_UP))
		{
			for (j = y + 1; j<y + 3; j++)
			{
				for (i = x; i < x + 3; i++)
					map[i][j] = ' ';
			}
			map[x + 1][y] = ' ';

			for (i = x + 2; i >= x + 1; i--)
			{
				for (j = y; j<y + 3; j++)
					map[i][j] = ' ';
			}
			map[x][y + 1] = ' ';
			map[x][y] = ' ';
			x--;
			if (x <1)
				x = 1;
			DrawPlayer(x, y);
		}
		else	if (GetAsyncKeyState(VK_DOWN))
		{
			for (j = y + 1; j<y + 3; j++)
			{
				for (i = x; i < x + 3; i++)
					map[i][j] = ' ';
			}
			map[x + 1][y] = ' ';
			for (i = x; i < x + 2; i++)
			{
				for (j = y; j<y + 3; j++)
					map[i][j] = ' ';
			}
			map[x + 2][y + 1] = ' ';
			x++;
			if (x > 46)
				x = 50-4;
			DrawPlayer(x, y);
		}
		//xu ly va cham
		Proceed(x1, y1);
			Proceed1(x1, y1);
		for (i = x1; i < x1 + 2; i++)
		{
			for (j = y1; j<y1 + 3; j++)
				map[i][j] = ' ';
		}
		map[x1 + 2][y1 + 1] = ' ';
		x1++;
		if (x1 == 47)
		{
			x1 = 2 + rand() % 35;
			y1 = x1 + 3;
		}
		DrawEm(x1, y1);
		//xu ly va cham
		Proceed(x3, y3);
		Proceed1(x3, y3);
		for (i = x3; i < x3 + 2; i++)
		{
			for (j = y3; j<y3 + 3; j++)
				map[i][j] = ' ';
		}
		map[x3 + 2][y3 + 1] = ' ';
		x3++;
		
		if (x3 == 47)
		{
			x3 = 2 + rand() % 35;
			y3 = x3 + 3;
		}
			
		DrawEm(x3, y3);
		//xu ly va cham
		Proceed(x4, y4);
			Proceed1(x4, y4);
		for (i = x4; i < x4 + 2; i++)
		{
			for (j = y4; j<y4 + 3; j++)
				map[i][j] = ' ';
		}
		map[x4 + 2][y4 + 1] = ' ';
		
		x4++;
		
		if (x4 == 47)
		{
			x4 = 2 + rand() % 35;
			y4 = x4 + 3;
		}
		
		DrawEm(x4, y4);
		Print();		
		Sleep(0);
	}
	char key;
	textcolor(17);
	gotoxy(21, 21);

	cout << "TIEP TUC?ENTER:";
	textcolor(7);
	key = _getch();
	if (key == 'c')
		goto tt;
	system("pause");
	return 0;
}
