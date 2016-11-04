//
//  main.c
//  compressed_sensing
//
//  Created by Carlos Alberto Salazar Herrera on 10/15/16.
//  Copyright © 2016 Carlos Alberto Salazar Herrera. All rights reserved.
//
// Propietaries
#include "mix_fun.h"

// C mix
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Spase
#include "blas_dense.h"
#include "blas_sparse.h"
// VP9
#include "vpx/vpx_encoder.h"
//#include "tools_common.h"
#include "video_writer.h"


/**
Algorithm for solving:
 
 0.5 * (y - X*beta)'*(y - X*beta) + lambda * ||beta||_1

Input:

    y = n by 1 response vector -> response  (X + noise)
    X = n by p design matrix -> dictionary
    lambda = regularization parameter for L1 penalty

**/

int main(int argc, const char **argv) {
    FILE *infile = NULL;
    vpx_image_t raw;
    VpxVideoInfo info = {0};
    const char *infile_arg='/Users/Carlos/Documents/PHD/sourceVideo/originals/4CIF/CROWDRUN_704x576_25.yuv';
    
    info.frame_width='704';
    info.frame_height='576';
    
    
    if(!vpx_img_alloc(&raw, VPX_IMG_FMT_I420, info.frame_width,info.frame_height, 1)){

        exit(0);
    }
    
    infile=fopen(infile_arg,"rb");
    
   vpx_img_read(&raw,infile);
    vpx_img_free(&raw);
    
    
    return(0);
  

}



void lasso(){
    
    void BLAS_uscr_end();
    double r2();
    
    const int N=4;
    const int nz=4;
    double val[] = {1, 1, 1, 1};
    int indx[] = {0, 1, 2, 3};
    int jndx[] = {0, 1, 2, 3};
    double x[] = {r2(), r2(), r2(), r2()};
    double y[] = {-1, -1, -1, -1};
    
    
    
    blas_sparse_matrix A;
    int i;
    double alpha = 1.0;
    
    A= BLAS_duscr_begin(N,N);
    
    for (i=0; i<nz; i++)
        BLAS_duscr_insert_entry(A,val[i], indx[i], jndx[i]);
    
    BLAS_duscr_end(A);
    
    BLAS_dusmv(blas_no_trans, alpha, A, x, 1, y, 1);
    
    for (i=0; i<N; i++ )
        printf("result:%f\n",y[i]);
    
    
    
    
}


void lambda_opt(){
    
    // cross-validation function (select patches) -cvpartition in matlab
}


void load_img(){
    
    // Load Image to process
}

double r2()
{
    return (double)rand() / (double)((unsigned)RAND_MAX +1) ;
}



/*int vpx_img_read2(vpx_image_t *img, FILE *file) {
    int plane;
    
    for (plane = 0; plane < 3; ++plane) {
        unsigned char *buf = img->planes[plane];
        const int stride = img->stride[plane];
        const int w = vpx_img_plane_width(img, plane) *
        ((img->fmt & VPX_IMG_FMT_HIGHBITDEPTH) ? 2 : 1);
        const int h = vpx_img_plane_height(img, plane);
        int y;
        
        for (y = 0; y < h; ++y) {
            if (fread(buf, 1, w, file) != (size_t)w) return 0;
            buf += stride;
        }
    }
    
    return 1;
}*/


