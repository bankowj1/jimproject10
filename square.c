#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "square.h"
#include "points.h"
#include "piv_ge_solver.h"

//pts->x[n] 
//pts->y[n]

int m =4;
int n =pts->n;
int r=5;

void matrixa(){
	matrix_t * A = make_matrix(r,1);
}


void matrixB(points_t * pts){
	matrix_t * B = make_matrix(r,r);
	double * X;
	X = (double*)malloc ((2*m+1)*sizeof(double));
		for(int i=0; i < (2*m+1) ; i++)
		{
			X[i]=0;
			for(int j=0 ; j < n; j++)
			{
				X[i]=X[i]+pow(pts->x[j],(double)i);
			}
		}
		for(int i=0; i <(m+1);i++)
		{
			for(int j=0; j<(m+1);j++)
			{
				B->e[i*j+j]=X[i+j];
			}
		}
	
}


void matrixY(points_t * pts){
	matrix_t * Y = make_matrix(r,1);
	double yy;
		for(int i=0; i<(m+1);i++)
		{
		yy=0;
			for(int j=0; j<n;j++)
			{
				yy += ( pow(pts->x[j],(double)i) * (pts->y[j]));
			}
		Y->e[i]=yy;
		}
}







