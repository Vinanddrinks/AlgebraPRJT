//
// Created by vinanddrinks on 29/05/2021.
//
#include "matanalyse.h"
#include <stdio.h>
#include <stdlib.h>

float** create_matrix(float** Array,int height,int length){
    // allocation des lignes
    Array=(float **)calloc(height,sizeof (float*));
    // allocation des colonnes
    for(int i = 0; i < height;i++){
        Array[i] = (float*) calloc(length,sizeof(float));
    }
    // fin de la creation
    return Array;
}

void free_matrix(float** Array,int height){
    for(int i = 0; i < height; i++)
        free(Array[i]);
    free(Array);
}

void fill_user_matrix(float** Array,int height,int length){
    for(int i = 0; i < height;i ++){
        printf("\n%d th line from the top",i+1);
        for(int j = 0 ; j < length; j++){
            printf("\nEnter the %d th value in the line from the left:",j+1);
            scanf("%f",&Array[i][j]);

        }
    }
}

void display_usermatrix(float** Array,int height,int lenght) {
    for (int i = 0; i < height; i++) {
        printf("\n");
        for (int j = 0; j < lenght; j++) {
            printf("%f\t", Array[i][j]);
        }
        printf("\n\n");
    }
}
