// mpicc mpi_matriz.c -o mpi_matriz
// mpirun -n 1 mpi_matriz

#include <stdio.h>
#include <mpi.h>
#include <time.h>

int matrizA[2][3],matrizB[3][2],matrizC[2][3];
struct timespec t, t_inicio;

int main(int argc, char *argv[]) 
{
    int myrank, nprocs;

    matrizA[0][0] = 1;
    matrizA[0][1] = 2;
    matrizA[0][2] = 3;
    matrizA[1][0] = 6;
    matrizA[1][1] = 5;
    matrizA[1][2] = 4;
    matrizB[0][0] = 1;
    matrizB[0][1] = 2;
    matrizB[1][0] = 3;
    matrizB[1][1] = 4;
    matrizB[2][0] = 5;
    matrizB[2][1] = 6;   
    clock_gettime(CLOCK_MONOTONIC ,&t);
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);

        for (int i = 0; i<2; i++){
            for (int j = 0; j<3; j++){
                matrizC[i][j] = matrizA[i][j] * matrizB[j][i];
            }
        }

    MPI_Finalize();
    clock_gettime(CLOCK_MONOTONIC ,&t_inicio);
    for (int i = 0; i<2; i++){
        for (int j = 0; j<3; j++){
            printf("matrizC[%d][%d] = %d \n",i,j,matrizC[i][j]);
        }
    }
    printf("inicio: %ld, fim: %ld = %ld",t.tv_nsec,t_inicio.tv_nsec,(t_inicio.tv_nsec-t.tv_nsec));
    return 0;
}
