1. Este exercício é apenas para lembrar o uso do compilador. 

Crie o programa "print.c" abaixo utilizando um editor:

print.c

#include <stdio.h> 



int main()

{ 

  printf("Laboratorio 01\n"); 

  return 0; 

}

Utilizando um terminal de comandos, compile o programa:

$ gcc -o print print.c

E depois o execute:

$ ./print


2. Digite o comando “man gcc” no terminal para ver o manual do GCC.

Segundo a descrição, quando o GCC é invocado, o que ele faz?

Dica: para sair do manual, basta apertar a letra 'q' (quit) no teclado.

3. Quantas opções o GCC possui?

(   ) De 1 a 5 opções

(   ) De 5 a 10 opções

( X ) Mais de 10 opções

4. No entanto, o GCC não realiza todo o processo sozinho, ele delega parte do processo de criação do executável para dois outros programas: "as" e "ld".

Utilize o comando 'man' no terminal para ver a descrição do que cada um deles faz:

$ man as

$ man ld

Dica: para sair do manual, basta apertar a letra 'q' (quit) no teclado.

5. De acordo com o trecho abaixo retirado do manual do GCC:

When you invoke GCC, it normally does preprocessing, compilation, assembly and linking. The “overall options” allow you to stop this process at an intermediate stage.  For example, the -c option says not to run the linker.  Then the output consists of object files output by the assembler.

Podemos pedir que o processo de compilação pare em uma determinada fase da compilação.

Utilizando o comando “gcc --help”, quais opções são responsáveis por:

Parar o processo logo após o pré-processador.
	-E                       Preprocess only; do not compile, assemble or link.
	
Parar o processo logo após gerar as instruções assembly (e antes de compilar).
	-S                       Compile only; do not assemble or link.

Parar o processo logo depois de compilar e antes de gerar o executável.
	-c                       Compile and assemble, but do not link.

6. Execute o comando abaixo para ativar o modo verbose, ou seja, o GCC mostrará o que ele está fazendo para compilar o programa:

$ gcc -v  -Wl,-v  -o print  print.c

É possível identificar as fases de compilação nos logs exibidos?

7. Crie o programa macro.c com o código abaixo:

macro.c

#include <stdio.h>



#define inc(x, y)   x++; y++

#define dobro(x)   (x + x)

#define calc(x, y) (x + y * 2)



int main()

{

  int a = 10;

  int b = 20;

  if (a > 15)

     inc(a, b);



  printf("Linha 1: a = %d, b = %d\n", a, b);



  a = 10;

  b = 20;

  a = dobro(++b);



  printf("Linha 2: a = %d, b = %d\n", a, b);



  a = 10;

  b = 20;

  b = calc(a, 1 + 5);



  printf("Linha 3: a = %d, b = %d\n", a, b);



  return 0;

}

Execute o programa "no papel", depois compile e execute o programa, e compare os resultados:
    Resultados no papel:
        Linha 1: a = 10, b = 20
        Linha 2: a = 42, b = 20
        Linha 3: a = 10, b = 22
    Resultado no terminal:
        Linha 1: a = 10, b = 21
        Linha 2: a = 44, b = 22
        Linha 3: a = 10, b = 21

$ gcc -o macro macro.c

$ ./macro

8. Após executar o comando abaixo, pedindo que o GCC resolva apenas as macros, o que podemos dizer da diferença entre a função main() do arquivo macro.c e do arquivo macro.i?
    Dentro da função main() do arquivo macro.i a saída do terminal faz bem mais sentido

$ gcc -E -o macro.i macro.c

Consegue identificar comportamentos não esperados?
    Não, na função main() do arquivo macro.i eu consigo entender perfeitamente a saída do terminal

9. Execute o comando abaixo no terminal:

$ gcc -S -o print.S print.c

Qual é o conteúdo do arquivo print.s? Conseguimos fazer alguma correlação com o conteúdo do arquivo print.c?
    Assembly bruto, ainda não consigo

10. Crie os os dois arquivos C abaixo:

main.c

#include <stdio.h> 



void sayHello();



int main() 

{ 

  sayHello();

  return 0; 

}

say.c

#include <stdio.h> 



void sayHello() 

{ 

   printf("Hello!!!\n");

}

A diretiva "-c" faz com que o GCC transforme o arquivo C em código objeto (código binário, mas que não pode ser executado diretamente). Depois, podemos criar o executável a partir dos objetos.

Execute os comandos abaixo no terminal como exemplo:

$ gcc -c -o main.o  main.c

$ gcc -c -o say.o say.c

$ gcc -o main  main.o say.o

$ ./main

Atividade:

Altere o arquivo say.c, modificando o texto do printf().

Não altere main.c, nem main.o.

Transforme say.c novamente em código objeto (segundo comando mostrado acima).

Crie o programa main com o novo say.o e o antigo main.o (terceiro comando mostrado acima).

Execute novamente o programa main (quarto comando mostrado acima).

    Feito, agora o terminal printa:
        "Bom diaaaaaaaa!!!"