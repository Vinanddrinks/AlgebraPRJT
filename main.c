//
// Created by vinanddrinks on 29/05/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "matanalyse.h"
int main(){
    printf("Hello World !\n");
    int size[2];
    printf("Enter the height of the matrix in row number:");
    scanf("%d",&size[0]);
    printf("\nEnter length of the matrix in column number:");
    scanf("%d",&size[1]);
    float ** Array = create_matrix(Array,size[0],size[1]);
    fill_user_matrix(Array,size[0],size[1]);
    display_usermatrix(Array,size[0],size[1]);
    return 0;
}
