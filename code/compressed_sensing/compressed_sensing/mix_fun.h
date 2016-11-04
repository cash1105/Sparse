//
//  mix_fun.h
//  compressed_sensing
//
//  Created by Carlos Alberto Salazar Herrera on 10/15/16.
//  Copyright © 2016 Carlos Alberto Salazar Herrera. All rights reserved.
//

#ifndef mix_fun_h
#define mix_fun_h

#include <gsl/gsl_linalg.h>
#include <stdio.h>
#include <string.h>

int linear_solver(double *a_data, double *b_data,size_m,gsl_vector *x, FILE *file);


#endif /* mix_fun_h */
