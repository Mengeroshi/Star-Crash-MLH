#include <stdio.h>
#include <windows.h>
#include <conio.h>


#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwpos;
    dwpos.X = x; 
    dwpos.Y = y;

    SetConsoleCursorPosition(hCon,dwpos);
}
void ocultarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon,&cci);
}
void pintar_limites()
{
    for(int i =2; i<78; i++)
    {
        gotoxy(i,3); printf("%c",205);
        gotoxy(i,23); printf("%c",205 );
    }
    for(int i =2; i<23; i++)
    {
        gotoxy(2,i); printf("%c",186);
        gotoxy(77,i); printf("%c",186 );
    }
}

class NAVE
{
    int x;
    int y;
    
    public:
        NAVE(int _x, int _y): x(_x),y(_y){};
        void pintar();
        void borrar();
        void mover();
        

};
void NAVE::pintar()
{
    gotoxy(x,y);
    printf("   %c",30);
    gotoxy(x,y+1);
    printf("  %c%c%c",40, 207,41);
    gotoxy(x, y+2);
    printf(" %c%c %c%c",30,190,190,30);
}

void NAVE::borrar()
{
    gotoxy(x,y);
    printf("       ");
    gotoxy(x,y+1);
    printf("       ");
    gotoxy(x,y+2);
    printf("       ");
}
void NAVE::mover()
{
     if(kbhit())//se presiono una tecla
    {
        char tecla=getch();//guarda la letra que se presione en nuestra variable
           
           borrar();
           if(tecla == IZQUIERDA)
            x--;
            if(tecla == DERECHA)
            x++;
            if(tecla == ARRIBA) 
            y--;
            if(tecla == ABAJO)
            y++;
            pintar();
    }
}

int main()
{
    printf("STARCRASH!!!!!");
    ocultarCursor();
    pintar_limites();
    gotoxy(10, 10);
    printf("STARCRASH!!!!!");
    NAVE N(7,7);
    N.pintar();

bool gameover=false;
while(!gameover)
{
   N.mover(); 
   Sleep(30);
}
    

    return 0;
}
