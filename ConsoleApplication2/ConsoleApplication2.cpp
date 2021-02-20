#include <stdio.h>
#include <stdlib.h>



int lenght_i(int A[100][100]) {
    for (int i = 0; i < 100; i++) {
        if (A[i][0] < 0) {
            return i;
        }
    }
}



int length_j(int A[100][100]) {
    for (int j = 0; j < 100; j++) {
        if (A[0][j] < 0) {
            return j;
        }
    }
}




void print_matrix(int A[100][100]) {


    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {

            printf("%d", Array[i][j]);
            printf(" ");

        }
        printf("\n");
    }


}




void flip(int A[100][100],int M, int N) {
    int tmp;

    int counter = N / 2;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < counter; j++) {
            tmp = A[i][j];
            A[i][j] = A[i][N - j - 1];
            A[i][N - j - 1] = tmp;
        }

}





void trans(int A[100][100], int M, int N) {

    for (int i = 0; i < M; i++)
        for (int j = i; j < N; j++) {

            int tmp = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = tmp;
        }
}



void fliplr(int A[100][100], int M, int N) {
    flip(A, M, N);
    printf("Разворот:\n");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (A[i][j] >= 0) {
                printf("%d", A[i][j]);
                printf(" ");
            }

        }
        if (A[i][0] >= 0)
        printf("\n");

    }

}
void transpose(int A[100][100], int M, int N) {
    trans(A, M, N);
    printf("Транспонирование:\n");
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (A[i][j] >= 0) {
                printf("%d", A[i][j]);
                printf(" ");
            }

        }
        if (A[i][0] >= 0)
        printf("\n");

    }

}









void rotate(int A[100][100], int M, int N) {
    

    if (N == M) {
        trans(A, M, N);
        flip(A, M, N);
    }
  

    
}


void rot90(int A[100][100], int M, int N,int times) {
    if (times < 0) { times = times * (-1);
    times = times % 4;
    times = 4 - times;
    }
    else {
        if (times > 4)times = times % 4;
    }
for (int i = 0;i<times;i++)
    rotate(A, M, N);

printf("Поворот:\n");
for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
        if (A[i][j] >= 0) {
            printf("%d", A[i][j]);
            printf(" ");
        }

    }
    if (A[i][0] >= 0)
    printf("\n");

}



}





    




int test() {
    int case0 = 4;
    int tmp;
    int Array[100][100];
    int M;
    int N;


    while (case0 != 5) {
        if (case0 == 4) {
            printf("ВВедите длинну массива: ");
            scanf_s("%d", &N);
            printf("ВВедите ширину массива: ");
            scanf_s("%d", &M);
            for (int i = 0; i < M; i++)
                for (int j = 0; j < N; j++) {
                    Array[i][j] = rand() % 100;

                }
            printf("Исходный массив:\n");
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {

                    printf("%d", Array[i][j]);
                    printf(" ");

                }
                printf("\n");
            }



            case0 = 0;
        }


        printf("1 - Отражение матрицы по вертикали\n ");
        printf("2 - Транспонирование матрицы\n ");
        printf("3 - Поворот матрицы\n ");
        printf("5 - Выход\n ");
        scanf_s("%d", &case0);



        

        if (case0 == 1) {
            fliplr(Array, M, N);
            
        }
        if (case0 == 2) {
            transpose(Array, M, N);
            
        }
        if (case0 == 3) {
            int spin = 0;
            printf("Сколько раз повернуть матрицу?\n ");
            scanf_s("%d", &spin);
            rot90(Array, M, N, spin);
            

        }
        
        


       


    }
    return(0);
}


int main()
{
    system("chcp 1251");        // Текущая кодовая страница 1251
    system("cls");              // Очистка консоли
    test();
    getchar();
    return 0;
}