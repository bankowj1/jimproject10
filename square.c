#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "square.h"

//pts->x[n] 
//pts->y[n]

int m =4;
int n =pts->n;
int r=5;
matrix_t * matrixB(points_t * pts){
	matrix_t * M = make_matrix(r,r+1);
	double * X;
	X = (double*)malloc ((2*m+1)*sizeof(double));
		for(int i=0; i < (2*m+1) ; i++)
		{
			X[i]=0;
			for(int j=0 ; j < n; j++)
			{
				X[i] += pow(pts->x[j],(double)i);
			}
		}
	double *B;
	B = (double*)malloc ((m+1)*(m+1)*sizeof(double));
		for(int i=0; i <(m+1);i++)
		{
			for(int j=0; j<(m+1);j++)
			{
				B[i*j+j]=X[i+j];
			}
		}
	double* Y;
	Y = (double*)malloc ((m+1)*sizeof(double));
		for(int i=0; i<(m+1);i++)
		{
		Y[i]=0;
			for(int j=0; j<n;j++)
			{
				Y[i] += ( pow(pts->x[j],(double)i) * (pts->y[j]) );
			}
		}
	for(int i=0; i <m+1;i++)
	{
		for(int j=0; j<m+2;j++)
		{	
			if(j!=m+1)
			{
				M->e[i*j+j]=B[i*(j-1)+j];	
			}else{
				M->e[i*j+j]=Y[i];
			}
		}
	}
	return M;
}







