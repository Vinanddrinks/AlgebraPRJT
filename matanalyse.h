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
#endif //ALGEBRAPRJT_MATANALYSE_H
