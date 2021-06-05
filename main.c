//
// Created by vinanddrinks on 29/05/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include "matanalyse.h"
float** manipmat(float** Array,int height, int length, int* sol[2]){
    int choice = 0;
    int row1, row2;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Swap rows | 2. Swap columns | 3. Enter a new array | 4. Exit \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    do{scanf("%d",&choice);}while(choice <= 0 || choice >= 5);
    switch (choice){
        default:
            break;
        case 1:
                printf("Position of row 1: \n");
                scanf("%d", &row1);
                printf("Position of row 2: \n");
                scanf("%d", &row2);
                swap_rows(Array, row1, row2, length);
                break;
        case 2:
            printf("Position of column 1: \n");
            scanf("%d", &row1);
            printf("Position of column 2: \n");
            scanf("%d", &row2);
            swap_col(Array, row1, row2, length);
            break;

        case 3:
            free_matrix(Array,*sol[0]);
            printf("Enter how many rows are in the matrix:");
            scanf("%d",sol[0]);
            printf("\nEnter how many columns are in the matrix:");
            scanf("%d",sol[1]);
            Array = create_matrix(Array,*sol[0],*sol[1]);
            fill_user_matrix(Array,*sol[0],*sol[1]);
            break;

    }
    return Array;
}
void LinAl(float** Array,int size[2]){
    float** Matrix = create_matrix(Matrix,size[0],size[1]);
    int choice;
    float det;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Find the determinant of the matrix | 2. Find the inverse of the matrix | 3. Echellon Matrix | 4. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    do{scanf("%d",&choice);}while(choice <= 0 || choice >= 5);

    switch (choice) {
        default:
            break;
        case 1:
            if(size[0]==size[1] && size[0] > 1 && size[0] < 4){
                if (size[1]==2){
                    det = det2x2(Array);
                }
                if (size[1]==3){
                    det = det3x3(Array);
                }
                printf("determinant is : %d",det);
            }else printf("Matrix not supported\n");
            break;
        case 2:
            if(size[0]==size[1] && size[0] == 3){
                if (det3x3(Array) != 0){
                    printf("Inverse matrix is:\n");
                    Matrix = inverse3x3(Array,3,3);
                    display_usermatrix(Matrix,3,3);
                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                }else printf("Determinant equal to Zero matrix not invertible\n");
            }else printf("Matrix not supported\n");
            break;
        case 3:
            printf("Echeloned matrix is: \n");
            Matrix = EchelonMat(Array, size[0], size[1]);
            display_usermatrix(Matrix,size[0], size[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            break;
    }
}
float** Compmatrix(float** Array,int size[2]){
    float** Matrix = create_matrix(Matrix,size[0],size[1]);
    float** Add = create_matrix(Matrix,size[0],size[1]);
    int sizebis[2],factor;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Multiply a matrix by one entered | 2. Multiply a matrix by a factor | 3. Add a matrix with another one entered | 4. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int choice;
    do{scanf("%d",&choice);}while(choice <= 0 || choice >= 5);
    switch(choice){
        default:
            return Array;
            break;
        case 1:
            printf("Enter how many rows are in the matrix: (must be equal to the number of columns of main matrix)");
            do{scanf("%d",&sizebis[0]);}while(sizebis[0]!=size[1]);
            printf("\nEnter how many columns are in the matrix:");
            scanf("%d",&sizebis[1]);
            float** Matrix1 = create_matrix(Matrix1,size[0],sizebis[1]);
            float ** Mult = create_matrix(Mult,sizebis[0],sizebis[1]);
            fill_user_matrix(Mult,sizebis[0],sizebis[1]);
            display_usermatrix(Mult,sizebis[0],sizebis[1]);
            Matrix1 = multiply2Mat(Array, Mult, size[0],size[1],sizebis[0], sizebis[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display_usermatrix(Matrix1,size[0],sizebis[1]);
            printf("Do you want to save this matrix as the main matrix? (1 = yes | 2 = no) \n");
            do{scanf("%d",&choice);}while(choice <= 0 || choice >= 3);
            if(choice == 1){
                return Matrix1;
            }
            break;
        case 2:
            printf("\nWhat is the factor you want to use?  ");
            scanf("%d", &factor);
            Matrix = multiplyMat(Array, size[0], size[1], factor);
            display_usermatrix(Matrix,size[0],size[1]);
            printf("Do you want to save this matrix as the main matrix? (1 = yes | 2 = no) \n");
            do{scanf("%d",&choice);}while(choice <= 0 || choice >= 3);
            if(choice == 1){
                return Matrix;
            }
            break;
        case 3:
            fill_user_matrix(Add,size[0],size[1]);
            display_usermatrix(Add,size[0],size[1]);
            Matrix = addMatrix(Array, Add, size[0], size[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display_usermatrix(Matrix,size[0],size[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Do you want to save this matrix as the main matrix? (1 = yes | 2 = no) \n");
            do{scanf("%d",&choice);}while(choice <= 0 || choice >= 3);
            if(choice == 1){
                return Matrix;
            }
            break;
    }
}
float** extra(float** Array,int size[2]){
    float** Matrix = create_matrix(Matrix,size[0],size[1]);

    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Find the transpose | 2. Find the comatrix | 3. Put the matrix to the square | 4. Exit\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int choice;
    do{scanf("%d",&choice);}while(choice <= 0 || choice >= 5);
    switch (choice) {
        default:
            return Array;
        case 2:
            if((size[0]==size[1]) && (size[0]==3)) {
                Matrix = comatrix3x3(Array, size[0], size[1]);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                display_usermatrix(Matrix, size[0], size[1]);
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Do you want to save this matrix as the main matrix? (1 = yes | 2 = no) \n");
                do{scanf("%d",&choice);}while(choice <= 0 || choice >= 3);
                if(choice == 1){
                    return Matrix;
                }else{return Array;}
            }else{printf("Matrix not supported\n");return Array;}

        case 1:

            Matrix = TransposeMat(Array, size[0], size[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display_usermatrix(Matrix, size[0], size[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Do you want to save this matrix as the main matrix? (1 = yes | 2 = no) \n");
            do{scanf("%d",&choice);}while(choice <= 0 || choice >= 3);
            if(choice == 1){
                return Matrix;
            }else return Array;
        case 3:
            Matrix = MatSquare(Array, size[0], size[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            display_usermatrix(Matrix, size[0], size[1]);
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("Do you want to save this matrix as the main matrix? (1 = yes | 2 = no) \n");
            do{scanf("%d",&choice);}while(choice <= 0 || choice >= 3);
            if(choice == 1){
                return Matrix;
            }else return Array;


    }
}
int main(){
    int size[2],choice=0;// 0 => Row number 1 => column number
    int * adsize[2]={&size[0],&size[1]};
    printf("Enter how many rows are in the matrix:");
    scanf("%d",&size[0]);
    printf("\nEnter how many columns are in the matrix:");
    scanf("%d",&size[1]);
    float ** Array = create_matrix(Array,size[0],size[1]);
    fill_user_matrix(Array,size[0],size[1]);
    Boolean Run = True;
    while(Run == True){
        printf("Main matrix is:\n");
        display_usermatrix(Array,size[0],size[1]);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("1. Manipulate the matrix | 2. Linear Algebra studies inside the matrix | 3. Computations between matrices |4. Extra | 5. Exit \n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        do{scanf("%d",&choice);}while(choice <= 0 || choice >= 6);
        switch(choice){
            default:
                break;
            case 1:
                Array = manipmat(Array, size[0], size[1],adsize);
                break;
            case 2:
                LinAl(Array,size);
                break;
            case 3:
                Array = Compmatrix(Array,size);
                break;
            case 4:
                Array = extra(Array,size);
                break;
            case 5:
                Run = False;
                break;

        }
    }
    return 0;
}
