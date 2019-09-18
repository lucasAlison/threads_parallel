#include<stdio.h>

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

void multiplicaMatriz() {
    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            matrizC[i][j] = matrizA[i][j] * matrizB[j][i];
            // printf("i = %d, j = %d | %d x %d = %d\n",i,j,matrizA[i][j],matrizB[j][i],matrizC[i][j]);
        }
    }
}

int main() {
    
    montarMatrizA();
    montarMatrizB();
    multiplicaMatriz();
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
    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            printf("matrizC[%d][%d] = %d \n",i,j,matrizC[i][j]);
        }
    }
}