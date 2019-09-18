#include	<pthread.h>
#include	<stdio.h>
#include	<unistd.h>

int matrizA[2][3],matrizB[3][2],matrizC[2][3];



void montarMatrizA() {
    matrizA[0][0] = 1;
    matrizA[0][1] = 2;
    matrizA[0][2] = 3;
    matrizA[1][0] = 6;
    matrizA[1][1] = 5;
    matrizA[1][2] = 4;    
}

void montarMatrizB() {
    matrizB[0][0] = 1;
    matrizB[0][1] = 2;
    matrizB[1][0] = 3;
    matrizB[1][1] = 4;
    matrizB[2][0] = 5;
    matrizB[2][1] = 6;    
}

void* tarefa_1(void *p)
{
    printf("\nThread1\n");      
    for (int i = 0; i<3; i++){        
        matrizC[0][i] = matrizA[0][i] * matrizB[i][0];        
        // printf("i = %d, j = %d | %d x %d = %d\n",i,j,matrizA[0][j],matrizB[j][i],matrizC[0][j]);            
    }
}

void* tarefa_2(void *p)
{
    printf("\nThread2\n");
    for (int i = 0; i<3; i++){        
        matrizC[1][i] = matrizA[1][i] * matrizB[i][1];        
        // printf("i = %d, j = %d | %d x %d = %d\n",i,j,matrizA[0][j],matrizB[j][i],matrizC[0][j]);            
    }
     
}

int main() {
    pthread_t t1, t2;
    montarMatrizA();
    montarMatrizB();

    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            printf("matrizA[%d][%d] = %d\n",i,j,matrizA[i][j]);
        }
    }
    for (int i = 0; i<3; i++){
        for (int j = 0; j<2; j++){
            printf("matrizB[%d][%d] = %d\n",i,j,matrizB[i][j]);
        }
    }
    
    pthread_create(&t1, NULL, (void *) tarefa_1, NULL);
    pthread_create(&t2, NULL, (void *) tarefa_2, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            printf("matrizC[%d][%d] = %d \n",i,j,matrizC[i][j]);
        }
    }
}