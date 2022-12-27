#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
 
void init() {
    setlocale(0, "");
    srand(time(NULL));
    printf( "Программа сортировки строк двухмерного динамического массива по возрастанию\n\n");
 
}
 
int **alloc_array(int n_row, int n_col) {
    int **a =(int**)malloc (n_row*sizeof(int*));
    for (int i = 0; i < n_row; i++) {
        a[i] = (int*)malloc(n_col*sizeof(int));
    }
    return a;
}
// int ***a, чтобы вернуть из функции адрес массива
void case1(int ***a, int *n_col, int *n_row) {
    do {
        //1\fflush(stdin);
        printf("Введите размерность массива: ");
        printf("\nШирина:> ");
        scanf("%d", n_col);
        printf("Высота:> ");
        scanf("%d", n_row);
        //system("cls");
    } while (*n_row <= 0 || *n_col <= 0);
    //здесь отдаем адрес наружу
    *a = alloc_array(*n_row, *n_col);
}
 
void case2(int **a, int n_row, int n_col) {
    int vybor;
    if (a != NULL) {
        do {
            //fflush(stdin);
            printf("Выберите:\n 1. С клавиатуры\n 2. Рандомно\n");
            scanf("%d", &vybor);
            system("cls");
        } while (vybor != 1 && vybor != 2);
        switch (vybor) {
        case 1: {
            printf("Заполните массив:\n");
            for (int i = 0; i < n_row; i++) {
                for (int j = 0; j < n_col; j++) {
                    printf("Введите элемент %d-ой строчки %d-ого столбца: ",
                            i + 1, j + 1);
                    scanf("%d", &a[i][j]);
                }
                system("cls");
            }
            break;
        }
        case 2: {
            printf("Массив заполнен случайными числами");
            getchar();
            getchar();
            system("cls");
            for (int i = 0; i < n_row; i++) {
                for (int j = 0; j < n_col; j++) {
                    a[i][j] = rand() % 50 - 25;
                }
            }
            break;
        }
        }
    } else {
        printf("Сделайте предыдущий шаг");
        getchar();
        getchar();
        system("cls");
    }
}
 
void case3(int **a, int n_row, int n_col) {
    if (a != NULL) {
        printf("Вот сам массив:\n");
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
        getchar();
        getchar();
        system("cls");
    } else {
        printf("Сделайте предыдущий шаг");
        getchar();
        getchar();
        system("cls");
    }
}
 
void case4(int **a, int n_row, int n_col) {
    if (a != NULL) {
        int x = 0;
        for (int i = 0; i < n_row; ++i) {
            for (int j = 0; j < n_col; ++j) {
                {
                    // тут разобраться в вашем коде
                    a[i][i] = 0;
                }
            }
        }
        printf("Массив обработан\n");
        getchar();
        getchar();
        //system("cls");
    } else {
        printf("Сделайте предыдущий шаг");
        getchar();
        getchar();
        system("cls");
    }
}
 
void case5(int **a, int n_row, int n_col) {
    if (a != NULL) {
        printf("Вот обработанный массив\n");
        for (int i = 0; i < n_row; i++) {
            for (int j = 0; j < n_col; j++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
        getchar();
        getchar();
        system("cls");
 
    } else {
        printf("Сделаете предыдущие шаги");
        getchar();
        getchar();
        system("cls");
    }
}
 
void destroy(int **a, int n_row) {
    for (int i = 0; i < n_row; i++) {
        free(a[i]);
    }
    free(a);
}
void menu() {
    int n_row = 0;
    int n_col = 0;
    int **a = NULL;
    init();
    int vybor = 0;
    do {
        //fflush(stdin);
        printf("1. Задать размерность двухмерного массива\n");
        printf("2. Выбор заполнения массива\n");
        printf("3. Вывод необработанного массива\n");
        printf("4. Обработка массива\n");
        printf("5. Вывод обработанного массива на экран\n");
        printf("0. Выход и программы\n");
        scanf("%d", &vybor);
        system("cls");
        switch (vybor) {
        case 1: {
            case1(&a, &n_row, &n_col);
            break;
        }
        case 2: {
            case2(a, n_row, n_col);
            break;
        }
        case 3: {
            case3(a, n_row, n_col);
            break;
        }
        case 4: {
            case4(a, n_row, n_col);
            break;
        }
        case 5: {
            case5(a, n_row, n_col);
            break;
        }
        }
    } while (vybor != 0);
    destroy(a, n_row);
}
 
int main() {
    menu();
    return 0;
}