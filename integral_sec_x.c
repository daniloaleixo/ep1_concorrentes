#include "integral_sec_x.h"


double integralSecX(double x, int s)
{
	int t = 0;
	int i;
	double x1, y1, sec_x, sec_1, sec_x1, res;

	srand( (unsigned) time(NULL) );



	
	sec_x = 1 / cos(x); 
	sec_1 = 1 / cos(1); 

	/* DEBUG
	printf("sec(1): %f\n", sec_1); 
	printf("sec(x): %f\n", sec_x); */


	for(i = 0; i < s; i++)
	{
		x1 = ((double)rand()/(double)RAND_MAX);
		y1 = ((double)rand()/(double)RAND_MAX)  *  sec_1;

		sec_x1 = 1 / cos(x1); 

		/* DEBUG 
		printf("x1: %f y1: %f sec(x): %f \n", x1, y1, sec_x);  */

		if(y1 <= sec_x) t++; 
	}

	/* DEBUG 
	printf("t>%d   s>%d\n", t, s); */

	res = t/(double)s * sec_1;

	printf("Integral of sec(%f) is %f\n", x, res);
	return res;
}