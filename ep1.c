/* ********************************
    EP1 - Programação Concorrente
    Prof. Marcel Jackowski

    Danilo Aleixo Gomes de Souza
    n USP: 7972370
  
********************************** */

#include "StringOps.h"
#include "Fibonacci.h"
#include "Heapsort.h"
#include "integral_sec_x.h"
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
	double x = 0.5;

	if(argc >= 4)
	{
		/* Atualiza os inteiros com as entradas */
		m = atoi(argv[1]);
		n = atoi(argv[2]);
		r = atoi(argv[3]);
		s = atoi(argv[4]);

		/* flags especiais */
		
		if(argv[5] != NULL) 
			if(argv[5][1] == 'x') /* --x <valor de x> */
				x = atof(argv[6]);



		/* primeira parte */
		v = criaVetor(m);
		imprimeVetor(v, m);
		heapsort(v, m);
		imprimeVetor(v, m);


		/* segunda parte */
		Fibonacci(n, 0);


		/* quarta parte */
		integralSecX(x, s);
	}
	else {
		printf("\n\nModo de uso\n\n");
        printf("ep1 <argumento heapsort> <argumento Fibonacci> <argumento> <argumento integral de sec x> <flags>\n\n");
        printf("Flags:\n");
        printf("-x <valor de x>\n");
        printf("para modificar o valor de x, no calculo da integral de sec x\n\n");
	}
	



  	return 0;
}



