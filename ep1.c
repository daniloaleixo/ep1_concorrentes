/* ********************************
    EP1 - Programação Concorrente
    Prof. Marcel Jackowski

    Danilo Aleixo Gomes de Souza
    n USP: 7972370
  
********************************** */

#include "StringOps.h"
#include "Fibonacci.h"
#include "Heapsort.h"
#include <pthread.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

/* funcoes */
int Fibonacci(int n, int soma);
void imprimeVetor(int *v, int n);
void heapsort(int a[], int n);
int *criaVetor(int n);
double integralSecX(double x, int s);
/*------------------------------*/


int main(int argc, char *argv[])
{

	int *v;
	int m, n, r, s;
	double x;

	/* Atualiza os inteiros com as entradas */
	m = atoi(argv[1]);
	n = atoi(argv[2]);
	r = atoi(argv[3]);
	s = atoi(argv[4]); 



	/* primeira parte */
	v = criaVetor(m);
	imprimeVetor(v, m);
	heapsort(v, m);
	imprimeVetor(v, m);


	/* segunda parte */
	Fibonacci(n, 0);


	integralSecX(1.0, s);




  	return 0;
}

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
		/* printf("%f %f\n", x1, y1); */
		sec_x1 = 1 / cos(x1);
		if(sec_x1 >= y1) t++;
	}

	printf("t>%d\n", t);

	res = t/(double)s * sec_1;

	printf("integral of sec(%f) is %f\n", x, res);
	return res;
}



