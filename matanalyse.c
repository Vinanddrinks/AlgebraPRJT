//
// Created by vinanddrinks on 29/05/2021.
//
#include "matanalyse.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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

float ** multiplyMat(float ** Mat, int rowsMat, int colMat,  float factor){
    float ** matrix = create_matrix(matrix, rowsMat, colMat);
    for (int rows = 0; rows < rowsMat; rows++){
        for (int col=0; col<colMat; col++){
            matrix[rows][col] = factor * Mat[rows][col];
        }
    }
    return matrix;
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

float ** TransposeMat(float ** Mat, int rowsMat, int colMat){
    float** Transpose = create_matrix(Transpose, rowsMat, colMat);
    for (int rows = 0; rows<colMat; rows++){
        for (int col = 0; col<rowsMat; col++){
            Transpose[rows][col]=Mat[col][rows];
        }
    }
    return Transpose;
}


float ** comatrix3x3(float **Mat, int rowsMat, int colMat) {
    float **comatrix = create_matrix(comatrix, rowsMat, colMat);
    float **temp = create_matrix(temp, 2, 2);
    for (int rows = 0; rows < rowsMat; rows++) {
        for (int col = 0; col < colMat; col++) {
            int x = 0;
            int y = 0;
            int cpt = 0;
            for (int rowsBis = 0; rowsBis < rowsMat; rowsBis++) {
                for (int colBis = 0; colBis < colMat; colBis++) {
                    if ((rowsBis != rows) && (colBis != col)) {
                        temp[x][y] = Mat[rowsBis][colBis];
                        cpt++;
                        if (cpt==1){
                            y=1;
                        }
                        if (cpt==2){
                            x=1;
                            y=0;
                        }
                        if(cpt==3){
                            y=1;
                            x=1;
                        }
                    }
                }
            }
            comatrix[rows][col] = pow(-1, (rows + col)) * det2x2(temp);
        }
    }
    return comatrix;
}

float** inverse3x3(float ** Mat, int rowsMat, int colMat){
    float det = det3x3(Mat);
    if (det == 0){
        return Mat;
    }
    float **comatrix = comatrix3x3(Mat, rowsMat, colMat);
    comatrix = TransposeMat(comatrix, rowsMat, colMat);
    float **inverse = create_matrix(inverse, rowsMat, colMat);
    inverse = multiplyMat(comatrix,rowsMat, colMat, (1/det));
    return inverse;
}


// Echellonage de matrice

float ** EchelonMat(float** Mat,  int rowsMat, int colMat){
    int rank = colMat;
    for(int row=0; row<rowsMat; row++) {
        if (Mat[row][row]) {
            for (int col = 0; col < rowsMat; col++) {
                if (col != row) {
                    // This makes all entries of current
                    // column as 0 except entry 'mat[row][row]'
                    double mult = (double) Mat[col][row] /
                                  Mat[row][row];
                    for (int i = 0; i < rank; i++)
                        Mat[col][i] -= mult * Mat[row][i];
                }
            }
        } else {
            Boolean reduce = True;
            for (int i = row + 1; i < rowsMat; i++) {
                if (Mat[i][row]) {
                    swap_rows(Mat, row, i, colMat);
                    reduce = False;
                    break;
                }
            }
            if (reduce) {
                rank--;
                for (int i = 0; i < rowsMat; i++) {
                    Mat[i][row] = Mat[i][rank];
                }
                row--;
            }

        }
    }
    return Mat;
}
