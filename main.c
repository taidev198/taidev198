#include<conio.h>

#include<stdio.h>

#include<string.h>

#include<Windows.h>

#include<stdlib.h>

#include<mmsystem.h>

#include<time.h>
//enum TrangThai {UO,DOWN,LEFT,RIGHT};
// Hàm tô màu.


void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

 //Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Hàm xóa màn hình.
//void XoaManHinh()
//{
//	HANDLE hOut;
//	COORD Position;
//	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//	Position.X = 0;
//	Position.Y = 0;
//	SetConsoleCursorPosition(hOut, Position);
//}

int main()
{
    srand(time(NULL));
	FILE *fp,*fp1,*fp2,*fp3,*fp4;
	system("color 7");
	fp1 = fopen("nguyen.txt", "rt");
	fp2 = fopen("thanh.txt", "rt");
		fp3 = fopen("tai.txt", "rt");
				fp = fopen("beautiful text.txt", "rt");
srand(time(0));
while(1)
{
    system("cls");
    textcolor(rand()%16);
    rewind(fp1);
    	while(!feof(fp1))
	{
        char c;
		c=fgetwc(fp1);
		Sleep(0);//;PlaySound(TEXT("typewriter-key-1.wav"),NULL,SND_SYNC);
		putchar(c);
	}

	Sleep(400);
	system("cls");
	textcolor(rand()%16);
	//printf("\t");
	 rewind(fp2);
		while(!feof(fp2))
	{
        char c;
		c=fgetwc(fp2);
		Sleep(0);//;PlaySound(TEXT("typewriter-key-1.wav"),NULL,SND_SYNC);
		putchar(c);
	}

	Sleep(400);

	system("cls");

	textcolor(rand()%16);
	rewind(fp3);
		while(!feof(fp3))
	{
        char c;
		c=fgetwc(fp3);
		Sleep(0);//;PlaySound(TEXT("typewriter-key-1.wav"),NULL,SND_SYNC);
		putchar(c);
	}
	Sleep(400);
	system("cls");
	textcolor(rand()%16);
    rewind(fp);
			while(!feof(fp))
	{
        char c;
		c=fgetwc(fp);
		Sleep(0);//;PlaySound(TEXT("typewriter-key-1.wav"),NULL,SND_SYNC);
		putchar(c);
	}
	Sleep(500);
}
	fclose(fp1);
    fclose(fp);
	fclose(fp2);
	fclose(fp3);
	system("pause");
	getch();
	return 0;
}
