 #include<conio.h>

#include<stdio.h>

#include<windows.h>

#include<string.h>

// Hàm tô màu.

void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.

void gotoxy(int x,int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x-1,y-1};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput , Cursor_an_Pos);
}

// Hàm xóa màn hình.

void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}
void Copy(char a[][100],int m,int n,int x)
{
    char S[]="XIN CHAO CAC BAN !!";
    int Size=strlen(S);
        int i,j,k=0;
        for(i=0;i<n;i++)
        {
            for(j=x;j<m;j++)
            {
                if(i==2)
                    {
                        a[i][j]=S[k++];
                        if(k==Size)
                            break;
                    }
            }
        }
}

void Le(char a[][100],int m, int n)
{
    int i,j;
            for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0&&j%2!=0)
                    a[i][j]=254;
              else  if(j==0&&i%2!=0)
                    a[i][j]=254;
              else if(i==n-1&&j%2==0)
                    a[i][j]=254;
              else  if(j==m-1&&i%2==0)
                    a[i][j]=254;
                else
                    a[i][j]=32;
            }
        }
}
void Chan(char a[][100],int m,int n)
{
    int i,j;
            for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0&&j%2==0)
                    a[i][j]=254;
              else  if(j==0&&i%2==0)
                    a[i][j]=254;
              else if(i==n-1&&j%2!=0)
                    a[i][j]=254;
              else  if(j==m-1&&i%2!=0)
                    a[i][j]=254;
                else
                    a[i][j]=32;
            }
        }

}

void Print(char a[][100], int m, int n)
{
    int i,j;
            for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%c",a[i][j]);
            }
            printf("\n");
        }
    Sleep(100);
    XoaManHinh();
}

int main()
{
    int x1=1;
        char a[100][100];
        int x=5,y=3;
    int i,j;
    while(1)
    {
PlaySound(TEXT("typewriter-2.wav"), NULL, SND_ASYNC);//CHAY SONG SONG VOI CAU LENH BEN DUOI CHO DEN KHI CAU LENH DUOI KET THUC
        Le(a,50,5);
        Print(a,50,5);
        textcolor(14);
//        gotoxy(x,y);
//         printf("NGUYEN THANH TAI");
//        Sleep(150);
        XoaManHinh();
        textcolor(7);// tra lai mau cu
        Chan(a,50,5);
        Print(a,50,5);
        Copy(a,50,5,x1);
        x1++;
        if(x1==49)
        x1=0;
        textcolor(14);
        Print(a,50,5);
      textcolor(7);
        x-=2;
        if(x==1)
            x=50-strlen("NGUYEN THANH TAI")-1;
}    getch();
    return 0;
}
