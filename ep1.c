/* ********************************
    EP1 - Programação Concorrente
    Prof. Marcel Jackowski

    Danilo Aleixo Gomes de Souza
    n USP: 7972370
  
********************************** */

#include "StringOps.h"
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


int Fibonacci(int n, int soma)
{
   	if ( n == 0 )
      return 0;
   	else if ( n == 1 )
      return 1;
   	else
   		soma = ( Fibonacci(n-1, soma) + Fibonacci(n-2, soma) );
   		printf("O Fibonacci de %d eh %d\n", n, soma );
      	return soma;
} 




void imprimeVetor(int *v, int n)
{
	int i; 

	printf("imprimindo vetor: ");
	printf("%d", v[0]);
	for(i = 1; i < n; i++)
	{
		printf(", %d", v[i]);
	}
	printf("\n");
}


int *criaVetor(int m)
{
	int i;
	int *v = mallocSafe(m * sizeof(int));
	srand( (unsigned) time(NULL) );

	for(i = 0; i < m; i++)
	{
		v[i] = rand() % 100;
	}

	return v;

}


void heapsort(int a[], int n) {

   int i = n / 2, pai, filho, t;

   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }

      pai = i;

      //Primeiro será feita a comparação com o filho da esquerda.
      filho = i * 2 + 1;

      while (filho < n) {

         //Se o filho da esquerda for menor do que o filho da direita,então será feita a troca do filho que será comparado.
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}
