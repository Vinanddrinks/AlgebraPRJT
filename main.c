//
// Created by vinanddrinks on 29/05/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "matanalyse.h"
int main(){
    printf("Hello World !\n");
    int size[2];// 0 => Row number 1 => column number
    printf("Enter how many rows are in the matrix:");
    scanf("%d",&size[0]);
    printf("\nEnter how many columns are in the matrix:");
    scanf("%d",&size[1]);
    float ** Array = create_matrix(Array,size[0],size[1]);
    fill_user_matrix(Array,size[0],size[1]);

//    int size1[2];// 0 => Row number 1 => column number
//    printf("Enter how many rows are in the matrix:");
//    scanf("%d",&size1[0]);
//    printf("\nEnter how many columns are in the matrix:");
//    scanf("%d",&size1[1]);
//    float ** Array1 = create_matrix(Array1,size1[0],size1[1]);
//    fill_user_matrix(Array1,size1[0],size1[1]);


    display_usermatrix(Array,size[0],size[1]);
//    printf("The determinant of your matrix is : %f\n", det3x3(Array));
//    printf("---------------------------------------------------------------------------\n");
//    display_usermatrix(Array1,size1[0],size1[1]);
    printf("---------------------------------------------------------------------------\n");

//    float** ArrayRes = MatSquare(Array, size[0], size[1]);
//    display_usermatrix(ArrayRes, size[0], size[1]);

    float** Echelon = inverse3x3(Array, size[0],size[1]);
    display_usermatrix(Echelon, size[0],size[1]);
//    display_usermatrix(Array,size[0],size[1]);
    return 0;
}
