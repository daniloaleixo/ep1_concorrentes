#include "Heapsort.h"



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

/*
O código do heapsort foi tirado da página da wikipedia 
onde explica o metodo heapsort, que se encontra disponibilizado no seguinte link:
https://pt.wikipedia.org/wiki/Heapsort#C.C3.B3digo_em_C
*/
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