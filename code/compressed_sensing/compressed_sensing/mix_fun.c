//
//  mix_fun.c
//  compressed_sensing
//
//  Created by Carlos Alberto Salazar Herrera on 10/15/16.
//  Copyright © 2016 Carlos Alberto Salazar Herrera. All rights reserved.
//
#include "mix_fun.h"

int example(char * word){
    
    printf("Example: %s\n",word);
    return(1);
}


int linear_solver(double *a_data, double *b_data,int size_m, gsl_vector *x, FILE *file){

    gsl_matrix_view m = gsl_matrix_view_array(a_data,size_m,size_m);
    gsl_vector_view b = gsl_vector_view_array (b_data, size_m);
    int s;
    gsl_permutation * p = gsl_permutation_alloc (size_m);
    gsl_linalg_LU_decomp (&m.matrix, p, &s);
    gsl_linalg_LU_solve (&m.matrix, p, &b.vector, x);
    //printf ("x = \n");
    //gsl_vector_fprintf (stdout, x, "%g");
    gsl_permutation_free (p);
    return (0);
}