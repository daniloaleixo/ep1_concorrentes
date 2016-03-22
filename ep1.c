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
#include "agulha.h"
#include <pthread.h>

#define TRUE 1
#define FALSE 0


int main(int argc, char *argv[])
{

	int *v;
	int m, n, r, s;
	double x = 0.5;
	pid_t pid;

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



		if((pid = fork()) < 0) {
	    	perror("falha na criação de processo!");
	        exit(1);
	    } else if(pid == 0) {
	    	
	    	v = criaVetor(m);
			printf("P1: Vetor:          "); imprimeVetor(v, m);

			sleep(1);

			heapsort(v, m);
			printf("P1: Vetor ordenado: "); imprimeVetor(v, m);

	    } else {
	        /*waitpid(pid, NULL, 0);*/

	        /* segunda parte */
			Fibonacci(n, 0);

			/* terceira parte */
			agulhaBuffon(r);

			/* quarta parte */
			integralSecX(x, s);

			waitpid(pid, NULL, 0);
	    }

		/* primeira parte *
		v = criaVetor(m);
		printf("P1: Vetor:          "); imprimeVetor(v, m);

		heapsort(v, m);
		printf("P1: Vetor ordenado: "); imprimeVetor(v, m); */


		/* segunda parte *
		Fibonacci(n, 0);

		/* terceira parte *
		agulhaBuffon(r);

		/* quarta parte *
		integralSecX(x, s);



		/* 
		primeiro aproach 
		forkProcess(1, m, 0);
		forkProcess(2, n, 0);
		forkProcess(3, r, 0);
		forkProcess(4, s, x); */
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


/*
void forkProcess (int process, int arg, double sec_arg)
 {
    int i;
    pid_t pid;
    int *v;

    pid = fork();

    if (pid == -1) {
        /* error handling here, if needed *
        return;
    }
    if (pid == 0) {
        printf("I am a child: %d PID: %d\n",i, getpid());
        switch(process)
        {
        	case 1:
        	v = criaVetor(arg);
			printf("P1: Vetor:          "); imprimeVetor(v, arg);
			heapsort(v, arg);
			printf("P1: Vetor ordenado: "); imprimeVetor(v, arg);
			waitpid(pid, NULL, 0);
			return;

			case 2:
			Fibonacci(arg, 0);
			waitpid(pid, NULL, 0);
			return;

			case 3:
			agulhaBuffon(arg);
			waitpid(pid, NULL, 0);
			return;

			case 4:
			integralSecX(sec_arg, arg);
			waitpid(pid, NULL, 0);
			return;
        }
    }

}*/


