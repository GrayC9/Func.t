#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"MSO.h"
int main(){
    int N=0;
    int S;
    int w;
    int t;
    int **array,s,v,a;
    printf("Введите количество строк:");
    scanf("%d",&s);
    printf("Введите количество столбцов");
    scanf("%d", &v);
    array = IInitArray(s,v);
    system("clear");
    printf("|**************************|\n");
    printf("|--------------------------|\n");
    printf("|С консоли 1.              |\n");
    printf("|--------------------------|\n");
    printf("|С файла 2.                |\n");
    printf("|--------------------------|\n");
    printf("|С помощью рандомайзера 3. |\n");
    printf("|--------------------------|\n");
    printf("|Выйти в главное меню 0    |\n");
    printf("|**************************|\n");
    printf("Выберите метод: ");
    scanf("%d", &a);

    if (a==1)
    {
        IFillConsole(array,s,v);

    }
    if (a==2)
    {
        IFillFile(array,s,v);
    }
    if(a==3)
    {
        IFillRandom(array,s,v);
    }
    if(a==0)
    {
        exit(0);
    }
    system("clear");
    printf("Массив: \n");
    IPrintConsole(array, s, v);
    getchar();
    getchar();
}
