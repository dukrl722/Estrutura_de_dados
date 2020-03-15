#include <stdio.h>
#include <stdlib.h>
#include "quadrilateros.h"



int main ()
{
    printf ("quadrado = %lf\n", calc_quadrado (3));
    printf ("trapezio = %lf\n", calc_trapezio (2, 2, 2));
    printf ("losango  = %lf\n", calc_losango (2, 2));
    printf ("hexagono = %.1lf\n", calc_polig_regular (6, 2, 1.73));
    printf ("juros simples = %lf\n", calc_juros_simp (2, 6, 4));
    printf ("montante simples = %lf\n", calc_mont_simp (2, 4));
    printf ("montante composto = %lf\n", calc_mont_comp (2, 6, 4));
}