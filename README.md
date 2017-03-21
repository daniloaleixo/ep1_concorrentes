#  EP1 - Programação Concorrente

## Introdução 
Este exercı́cio-programa tem o objetivo de tornar natural o uso de algumas system calls do Linux, particularmente fork() e wait(), relacionadas a controle de processos.
O seu programa deverá receber quatro inteiros positivos m, n, r e s da linha de comando. Deverá, então, iniciar quatro processos (fork()), esperar que eles terminem (wait()) e encerrar. Os processos a serem criados serão descritos a seguir.
Você deverá imprimir na tela quando um processo iniciou e quando ele terminou, bem como quando o programa principal começou a espera e quando ele foi encerrado. (Rodando o programa várias vezes, você irá notar que essa ordem é imprevisı́vel!)


## Execução

Para rodar o EP basta descompactar o arquivo e dar um make pelo terminal 
```sh
make
```
O que irá gerar o arquivo ep1, depois é só rodá-lo usando ./ep1 e os argumentos.
Inseri uma flag para modificar o valor de x que é calculado na integral por simulação para usar basta colocar:
```sh
./ep1 <args> -x <valor de x>
```
Por exemplo 
```sh
./ep1 10 2 3 4 -x 0.5
```

## Modularização

O EP foi modularizado para tornar mais simples o entendimento portanto todos os processos estão separados em arquivos separados:
P1 - Ordenação 					-> heapsort.c
P2 - Numeros de Fibonacci 		-> fibonacci.c
P3 - Agulha de Buffon 			-> agulha.c
P4 - Integração por simulaçãp 	-> integral_sec_x.c
