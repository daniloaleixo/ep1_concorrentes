#include "Fibonacci.h"

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