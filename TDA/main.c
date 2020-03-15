#include <stdio.h>
#include <stdlib.h>
#include "math2.h"
#include <time.h>


int main ()
{
    int opc;
    double a, b, c, d;

    while (1)
    {

    puts ("Digite '1' para calcular a area de um quadrado");
    puts ("Digite '2' para calcular a area de um trapezio");
    puts ("Digite '3' para calcular a area de um losango");
    puts ("Digite '4' para calcular a area de um poligono (5 lados ou mais)");
    puts ("Digite '5' para calcular um juros simples");
    puts ("Digite '6' para calcular um montante de juros simples");
    puts ("Digite '7' para calcular um montande de juros compostos");
    puts ("Digite '0' para sair");

    scanf ("%d", &opc);

    switch (opc)
    {
    case 1: //calcula quadrado
        printf ("Digite o lado do quadrado: ");
        scanf ("%lf", &a);
        printf ("\n");
        printf ("O valor do quadrado eh: %.2lf\n", calc_quadrado (a));
        sleep (2);
        puts ("\n");
        break;
    
    case 2: //calcula trapezio
        printf ("Digite as duas bases do trapezio: ");
        scanf ("%lf %lf", &a, &b);
        printf ("Digite a altura do trapezio: ");
        scanf ("%lf", &c);
        printf ("\n");
        printf ("O valor do trapezio eh: %.2lf\n", calc_trapezio (a, b, c));
        sleep (2);
        puts ("\n");
        break;
        
    case 3: //calcula losango
        printf ("Digite as duas diagonais do losango: ");
        scanf ("%lf %lf", &a, &b);
        printf ("\n");
        printf ("O valor do losango eh: %.2lf\n", calc_losango (a, b));
        sleep (2);
        puts ("\n");        
        break;
       
    case 4: //calcula poligono
        printf ("Digite a medida de um lado do poligono: ");
        scanf ("%lf", &a);
        printf ("\n");
        printf ("Digite a quantidade de lados do poligono: ");
        scanf ("%lf", &b);
        printf ("\n");
        printf ("Digite o tamanho da apotema: ");
        scanf ("%lf", &c);
        printf ("\n");
        printf ("O valor do poligono eh: %.2lf\n", calc_polig_regular (a, b, c));
        sleep (2);
        puts ("\n");
        break;

    case 5: //calcula juros simples
        printf ("Digite o capital aplicado, a taxa e o tempo de aplicacao: ");
        scanf ("%lf %lf %lf", &a, &b, &c);
        printf ("\n");
        printf ("Juros simples: %.3lf\n", calc_juros_simp (a, b, c));
        sleep (2);
        break;

    case 6: //calcula montante simples
        printf ("Digite o capital aplicado e o juros simples da aplicacao: ");
        scanf ("%lf %lf", &a, &b);
        printf ("\n");
        printf ("Montante simples: %.3lf\n", calc_mont_simp (a, b));
        sleep (2);
        break;

    case 7:
        printf ("Digite o capital aplicado, a taxa e o tempo de aplicacao: ");
        scanf ("%lf %lf %lf", &a, &b, &c);
        printf ("\n");
        printf ("Montante composto: %.3lf\n", calc_mont_comp (a, b, c));
        sleep (2);
        break;

    case 0:
        return 0;

    default:
        printf ("Entrada invalida");
        puts ("\n");

        sleep (2);
        break;
    
    }
    }

    printf ("quadrado = %lf\n", calc_quadrado (3));
    printf ("trapezio = %lf\n", calc_trapezio (2, 2, 2));
    printf ("losango  = %lf\n", calc_losango (2, 2));
    printf ("hexagono = %.1lf\n", calc_polig_regular (6, 2, 1.73));
    printf ("juros simples = %lf\n", calc_juros_simp (2, 6, 4));
    printf ("montante simples = %lf\n", calc_mont_simp (2, 4));
    printf ("montante composto = %lf\n", calc_mont_comp (2, 6, 4));
}