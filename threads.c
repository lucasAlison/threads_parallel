#include<stdio.h>

int matrizA[2][3],matrizB[3][2];

void montarMatrizA() {
    int count = 1;
    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            matrizA[i][j] = count++;
        }
    }
}

int main() {
    
    montarMatrizA();

    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            printf("%d\n",matrizA[i][j]);
        }
    }

    
}