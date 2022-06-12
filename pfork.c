#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char* argv[]) {
    
    int id = 0;
    int id2 = 0;

    

    int VALOR = 8;
    int aux = 4;
    int matrizA [VALOR][VALOR];
    int matrizB [VALOR][VALOR];

    //printf("Imprimiendo matrizA y matrizB");

        //printf("\nMatriz A\n");

        for (int i = 0; i < VALOR; i++)
        {
            
            for (int j = 0; j < VALOR; j++)
            {
               matrizA[i][j] = 1;
               matrizB[i][j] = 1;
               printf(" %d ",matrizA[i][j]);
            }
            printf("\n");                        
        }

    id = fork();
    //id toma un valor y toma un 0
    id2 = fork();
    
    if(id == 0){
        if(id2 == 0){
            
            //Cuadrante 1
            printf("\nObteniendo cuadrante 1 en fork con id %d\n",id2);
            
            for (int i = 0; i < VALOR/2; i++)
            {
                
                for (int j = VALOR/2; j < VALOR; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                    }                    
                    printf("\t%d", sum);
                    sum = 0;                                                                        
                }
                printf("\n"); 
            }    
        }
        else{
            //Cuadrante 2
            printf("\nObteniendo cuadrante 2 en fork con id %d\n",id2);
            for (int i = 0; i < VALOR/2; i++)
            {
                for (int j = 0; j < VALOR/2; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                    }                    
                    printf("\t%d", sum);
                    sum = 0;       
                                 
                }
                printf("\n");
            }            
        }
    }
    else{
        if(id2 == 0){
            //Cuadrante 3
            printf("\nObteniendo cuadrante 3 en fork con id %d\n",id2);
            for (int i = VALOR/2; i < VALOR; i++)
            {
                for (int j = 0; j < VALOR/2; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                    }                    
                    printf("\t%d", sum);
                    sum = 0;       

                }
                printf("\n");
            }                       
        }        
        else{
             //Cuadrante 4
            printf("\nObteniendo cuadrante 4 en proceso padre con id %d\n",id);
            for (int i = VALOR/2; i < VALOR; i++)
            {
                for (int j = VALOR/2; j < VALOR; j++)
                {
                    int sum = 0;
                    for (int k = 0; k < VALOR; k++){
                        sum = sum + matrizA[i][k]*matrizB[k][j];
                    }                    
                    printf("\t%d", sum);
                    sum = 0;                     
                }
                printf("\n");
            }
        }
    }

    
    return 0;
}