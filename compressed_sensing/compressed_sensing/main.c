//
//  main.c
//  compressed_sensing
//
//  Created by Carlos Alberto Salazar Herrera on 10/15/16.
//  Copyright © 2016 Carlos Alberto Salazar Herrera. All rights reserved.
//
#include "mix_fun.h"


//"/Users/Carlos/Documents/PHD/compressed_sensing/compressed_sensing/test.dat"

// solution Ax=b

int main(int argc, const char * argv[]) {

    double *a_data, *b_data;
    int size_m=3;
    gsl_vector *x = gsl_vector_alloc (size_m);
    
    double a[]= {0.18, 0.60, 0.57,
                 0.41, 0.24, 0.99,
                 0.14, 0.30, 0.97};
    
    double b[] = { 1.0, 2.0, 3.0};
    
    a_data=a;
    b_data=b;
    
    linear_solver(a_data,b_data,size_m,x);
    
    printf ("x = \n");
    gsl_vector_fprintf (stdout, x, "%g");
    gsl_vector_free (x);
    return(0);


}

