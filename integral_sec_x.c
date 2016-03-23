#include "integral_sec_x.h"


double integralSecX(double x, int s)
{
	int t = 0;
	int i;
	double x1, y1, sec_x, sec_1, sec_x1, res;

	srand( (unsigned) time(NULL) );



	
	sec_x = 1 / cos(x); 
	sec_1 = 1 / cos(1); 


	for(i = 0; i < s; i++)
	{
		x1 = ((double)rand()/(double)RAND_MAX);
		y1 = ((double)rand()/(double)RAND_MAX)  *  sec_1;

		sec_x1 = 1 / cos(x1); 

		if(y1 <= sec_x) t++; 
	}

	res = t/(double)s * sec_1;

	printf("\t\tP4: Numero de pontos s: %d, numero de pontos t: %d, Valor da area estimada: %f\n", s, t, res);
	return res;
}