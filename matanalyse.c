//
// Created by vinanddrinks on 29/05/2021.
//
#include "matanalyse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        for(int j = 0 ; j < length; j++){
            printf("\nEnter the value at position [%d][%d] :",i+1,j+1);
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


// Matrix manipulation

void swap_rows(float ** Array, int row1, int row2, int nb_col){
    float* temprow[nb_col];
    memcpy(temprow,Array[row1-1],nb_col*sizeof(float));
    memcpy(Array[row1-1],Array[row2-1],nb_col*sizeof(float));
    memcpy(Array[row2-1],temprow,nb_col*sizeof(float));
}
void swap_col(float ** Array, int col1,int col2, int nb_row){
    float  tempcol[nb_row];
    for (int i = 0; i < nb_row;i++)
        tempcol[i] = Array[i][col1-1];
    for (int i = 0; i < nb_row;i++)
        Array[i][col1-1] = Array[i][col2-1];
    for (int i = 0; i < nb_row;i++)
        Array[i][col2-1] = tempcol[i];
}
void addition_row(float** Array,int rowdest,int rowop,int nb_col,float ratio) {
    for (int i = 0; i < nb_col; i++) {
        Array[rowdest-1][i] = Array[rowdest-1][i] + (ratio*Array[rowop-1][i]);
    }
}
void addition_col(float** Array,int coldest,int colop,int nb_row,float ratio) {
    for (int i = 0; i < nb_row; i++) {
        Array[i][coldest-1] = Array[i][coldest-1] + (ratio*Array[i][colop-1]);
    }
}

void row_factorisation(float** Array,int selected_row,int nb_col,float ratio) {
    selected_row = selected_row - 1;
    for(int i=0; i <nb_col;i++){
        Array[selected_row][i] = (1/ratio)*Array[selected_row][i];
    }
}

// determiants

float det2x2(float** Array){
    float det;
    det = Array[0][0]*Array[1][1] - Array[0][1]*Array[1][0];
    return det;
}

float det3x3(float** Array){
    float det;
    det = Array[0][0]*Array[1][1]*Array[2][2] + Array[1][0]*Array[2][1]*Array[0][2] + Array[2][0]*Array[0][1]*Array[1][2] - (Array[0][2]*Array[1][1]*Array[2][0] + Array[1][2]*Array[2][1]*Array[0][0] + Array[2][2]*Array[0][1]*Array[1][0]);
    return det;
}

// Multiplying functions

float** multiply2Mat(float** Mat1, float** Mat2, int rowsMat1, int colMat1, int rowsMat2, int colMat2){
    float** ResultMat;
    ResultMat = create_matrix(ResultMat, rowsMat1, colMat2);
    for (int i = 0; i<rowsMat1; i++){
        for (int j = 0; j<colMat2; j++){
            ResultMat[i][j] = 0;
            for (int k = 0; k<colMat1; k++) {
                ResultMat[i][j] = ResultMat[i][j] + Mat1[i][k] * Mat2[k][j];
            }
        }
    }
    return ResultMat;
}

float** MatSquare(float** Mat, int rowsMat, int colMat){
    float** ResultMat = multiply2Mat(Mat, Mat, rowsMat, colMat, rowsMat, colMat);
    return ResultMat;
}
