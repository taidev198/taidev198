#include<conio.h>
#include<stdio.h>
#include<windows.h>
    char map[100][50*2];

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

void SetMap()

{
        int i,j;
    for(i=0;i<11*2;i++)
    {
        int x1=7,x2=7*2+1;
        int x3=7*2+1;

        for(j=0;j<100-36;j++)
        {
           int k=x1+x2+1;
           int h=x1+x3+1;
           if(i%2==1)
           {
            map[i][x1]=124;
            map[i][x2]=124;

            if(j==k)
            {
                map[i][k]=124;
                x2=k;
            }
            else map[i][j]='_';
           }
           else
           {
            map[i][x1]=124;
            map[i][x2]=124;
               if(j==h)
               {
                map[i][j]=124;
                x3=h;
               }
               else map[i][j]=255;
           }


        }


    }
}

void Set()
{
    char s[]="THU";

int i;
int gt=50;
int gt1=49;
    for(i=8;i<8*8;i+=8)
    {
    int k=0;
    map[0][i]=s[k++];
    map[0][i+1]=s[k++];
    map[0][i+2]=s[k++];
    map[0][i+4]=gt++;
    }
    for(i=2;i<10*2;i+=2)
    {
        map[i][0]=gt1++;
    }
}

void Set1()
{
    int n,i;
    char s[8];
    int k=2,Count=0;
    int x=30,y=23;
    int x1=9;
    while(k<=6)
    {
    gotoxy(x-10,y);
    printf("==============THU %d==============",k);
    gotoxy(x,y);
    printf("\nNHAP SO MON:");
    scanf("%d",&n);
    int count=n;
//    gotoxy(x,y);
//    printf("\n\nNHAP MON:");
    int gt=20,gt1=y;
    Count=0;
    for(i=1;i<2+2*n;i+=2)
    {
//        gotoxy(gt,gt1++);
//        printf("\n\n\tNHAP MON %d:",Count++);
        gotoxy(gt,gt1++);
        gets(s);
        gotoxy(x1,i);
        printf("%s",s);

    }
    x1+=7;
    x1++;
    k++;
    y+=count+1;
    }



}

void HUONGDAN()
{
    gotoxy(97,2);
    textcolor(15);
    printf("===HUONG DAN-SU DUNG===");
    gotoxy(97,3);
    textcolor(14);
    printf("-NHAP SO MON VAO O VA AN");
    gotoxy(97,4);
    printf("AN ENTER DE KET THUC");
    gotoxy(97,5);
    printf("-ROI TIEP TUC TUNG MON");
    gotoxy(97,6);
    printf("AN ENTER DE CHUYEN");
    gotoxy(97,7);
    printf("======THE END=====");
    textcolor(4);
}

void Print()
{
    int i,j;
    for(i=0;i<11*2;i++)
    {
        for(j=0;j<100;j++)
        {
            if(map[i][j]==124||map[i][j]=='_')
            {
                textcolor(10);
                printf("%c",map[i][j]);
                textcolor(7);
            }
            else if(map[i][j]!=124&&map[i][j]!='_')
            {
                textcolor(14);
                printf("%c",map[i][j]);
                textcolor(7);
            }
            else printf("%c",map[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    char S[10];
    int x=9,y=10;
    SetMap();
    Set();
    Print();
    HUONGDAN();
    Set1();

//    while(1)
//{
//        XoaManHinh();
//        SetMap();
//        Set();
//        Print();
//    gotoxy(x,y+1);
//    printf(" ");
//    if(GetAsyncKeyState(VK_RIGHT))
//    {
//    x+=7;
//    x++;
//    }
//    else     if(GetAsyncKeyState(VK_LEFT))
//    {
//    x-=7;
//    x--;
//
//    }
//    else     if(GetAsyncKeyState(VK_UP))
//    {
//
//    y--;
//
//    }
//    else     if(GetAsyncKeyState(VK_DOWN))
//    {
//
//    y++;
//    if(kbhit())
//        gets(S);
//    }
//     else     if(GetAsyncKeyState(VK_BACK))
//     {
//            gotoxy(x,y);
//            gets(S);
//            gotoxy(x,y);
//            puts(S);
//     }
//        Sleep(100);
//}
}
