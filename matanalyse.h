//
// Created by vinanddrinks on 29/05/2021.
//

#ifndef ALGEBRAPRJT_MATANALYSE_H
#define ALGEBRAPRJT_MATANALYSE_H
//Enum and structure
typedef enum{True,False}Boolean;

// end structure
// matrix base functions
float** create_matrix(float** Array,int height,int length);
void free_matrix(float** Array,int height);
void fill_user_matrix(float** Array,int height, int length);

// end matrix bfx

// display
void display_usermatrix(float** Array,int height,int lenght);

//end display

// mathematical matrix opération
void swap_rows(float ** Array, int row1, int row2, int nb_col);
void swap_col(float ** Array, int col1,int col2, int nb_row);
void addition_row(float** Array,int rowdest,int rowop,int nb_col,float ratio);
void addition_col(float** Array,int coldest,int colop,int nb_row,float ratio);
void row_factorisation(float** Array,int selected_row,int nb_col,float ratio);

// determinant functions
float det2x2(float** Array);

#endif //ALGEBRAPRJT_MATANALYSE_H
