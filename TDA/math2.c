#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "math2.h"

/* 
j = capital * taxa * tempo; <juros simples>
M = capital + juros simples;
M = capital * (1 + taxa)^tempo; <montante de juros compostos>
*/

struct _financa
{
    double mont;
    double juros;
    double taxa;
    double tempo;
    double capital;
}; //Tipo _financa definido como FINANCA no arquivo .h


struct _quadri
{
    double b;
    double b2;
    double h;
}; //Tipo _quadri definido como QUADRI no arquivo .h

struct _poli
{
    QUADRI quad;
    double comp_n;
    double n;
    double h;
}; //Tipo _poli definido como POLI no arquivo .h

POLI *alloc_poli ()
{
    return malloc (sizeof (POLI));
}

FINANCA *alloc_finan ()
{
    return malloc (sizeof (FINANCA));
}

double calc_quadrado (double lado)
{
    POLI *p_quadrado = alloc_poli ();
    double area;

    p_quadrado->quad.h = lado;
    area = (p_quadrado->quad.h) * (p_quadrado->quad.h);

    free (p_quadrado);
    return area;
}

double calc_trapezio (double b1, double b2, double h)
{
    POLI *p_trapezio = alloc_poli ();
    double area;

    p_trapezio->quad.b = b1;
    p_trapezio->quad.b2 = b2;
    p_trapezio->quad.h = h;
    area = (( (p_trapezio->quad.b) + (p_trapezio->quad.b2) ) * p_trapezio->quad.h) / 2;

    free (p_trapezio);

    return area;
}

double calc_losango (double b1, double b2)
{
    POLI *p_losango = alloc_poli ();
    double area;

    p_losango->quad.b = b1;
    p_losango->quad.b2 = b2;

    area = (p_losango->quad.b + p_losango->quad.b2) / 2;

    free (p_losango);

    return area;
}

double calc_polig_regular (double lados, double n_lado, double apot)
{
    POLI *p_polig = alloc_poli ();
    double area;

    p_polig->n = lados;
    p_polig->comp_n = n_lado;
    p_polig->h = apot;

    area = (p_polig->n * p_polig->comp_n * p_polig->h) / 2;

    free (p_polig);

    return area;
}

double calc_juros_simp (double capital, double taxa, double tempo)
{
    FINANCA *p_juros = alloc_finan ();
    double result;

    p_juros->capital = capital;
    p_juros->taxa = taxa;
    p_juros->tempo = tempo;

    result = p_juros->tempo * p_juros->taxa * p_juros->capital;

    free (p_juros);

    return result;
}

double calc_mont_simp (double capital, double juros)
{
    FINANCA *p_mont = alloc_finan ();
    double result;

    p_mont->capital = capital;
    p_mont->juros = juros;

    result = p_mont->capital + p_mont->juros;

    free (p_mont);

    return result;
}

double calc_mont_comp (double capital, double taxa, double tempo)
{
    FINANCA *p_mont = alloc_finan ();
    double result;

    p_mont->capital = capital;
    p_mont->taxa = taxa;
    p_mont->tempo = tempo;

    result = p_mont->capital * pow ( 1 + p_mont->taxa, p_mont->tempo);

    free (p_mont);

    return result;
}
