#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
int a[4][4], b[4][4];
void *matrixeval(void *val) {
    int *thno = (int*)val;
    for (int i = 0; i < 4; i++)
        b[(*thno)][i] = a[(*thno)][i];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < (*thno); j++)
            b[(*thno)][i] = b[(*thno)][i] * a[(*thno)][i];
    }
    printf("(%d) thread \n", (*thno + 1));
}
int main() {
    pthread_t tid[4];
    for (int i = 0; i < 4; i++) {
        printf("Enter elements of row %d: ", i + 1);
        for (int j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);
    }
    printf("Before processing: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    for (int i = 0; i < 4; i++) {
        pthread_create(&tid[i], NULL, matrixeval, (void*)&i);
        sleep(1);
    }
    for (int i = 0; i < 4; i++) {
        pthread_join(tid[i], NULL);
        sleep(1);
    }
    printf("After processing: \n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    pthread_exit(NULL);
    return 0;
}
/*
    $ gcc ThreadManage.c -pthread
    $ ./a.out 
 */