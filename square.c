#include "makespl.h"
#include "piv_ge_solver.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>


void
make_spl(points_t * pts, spline_t * spl)
{

	matrix_t       *eqs= NULL;
	double         *x = pts->x;
	double         *y = pts->y;
	double		a = x[0];
	double		b = x[pts->n - 1];
	int		i, j, k;
	double 		v[5];
	int		nb = 5;
	eqs = make_matrix(nb, nb + 1);


	for (j = 0; j < nb; j++) {
		for (i = 0; i < nb; i++)
			for (k = 0; k < pts->n; k++)
				add_to_entry_matrix(eqs, j, i,pow(pts->x[k],(double)(j+i));

		for (k = 0; k < pts->n; k++)
			add_to_entry_matrix(eqs, j, nb, pts->y[k] * pow(pts->x[k],(double)(j));
	}

	if (piv_ge_solver(eqs)) {
		spl->n = 0;
		return;
	}
	for(i = 0; i < nb; i++)
	{
		v[i]=get_entry_matrix(eqs, i, nb);
	}

	if (alloc_spl(spl, nb) == 0) {
		for (i = 0; i < spl->n; i++) {
			double xx = spl->x[i] = a + i*(b-a)/(spl->n-1);
			xx+= 10.0*DBL_EPSILON; 
			spl->f[i] = 0;
			spl->f1[i] = 0;
			spl->f2[i] = 0;
			spl->f3[i] = 0;
			spl->f4[i] = 0;
			spl->f[i]  += ck * fi  (a, b, nb, k, xx);
			spl->f1[i] += ck * dfi (a, b, nb, k, xx);
			spl->f2[i] += ck * d2fi(a, b, nb, k, xx);
			spl->f3[i] += ck * d3fi(a, b, nb, k, xx);
			spl->f4[i] += ck * d3fi(a, b, nb, k, xx);
		}
	}


}
