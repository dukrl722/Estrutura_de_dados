#include <stdio.h>
#include "quadrilateros.h"

typedef struct
{
    double b;
    double b2;
    double h;
} QUADRI;

typedef struct
{
    double comp_n;
    double n;
    double h;
} POLI;

double calc_quadrado () //também calcula retangulo
{
    QUADRI quadrado;
    double area;

    scanf ("%d %d", &quadrado.b, &quadrado.h);

    area = quadrado.b * quadrado.h;

    return area;
}

double calc_trapezio ()
{
    QUADRI trapezio;

    scanf ("%d %d %d", &trapezio.b, &trapezio.b2, &trapezio.h);

    double area = ( (trapezio.b + trapezio.b2) * trapezio.h ) / 2;

    return area;
}

double calc_losango ()
{
    QUADRI losango;
    double area;

    scanf ("%d %d", &losango.b, &losango.b2);

    area = (losango.b + losango.b2) / 2;

    return area;
}

double calc_polig_regular ()
{
    double area;
    POLI poligono;
    int n;

    scanf ("%d", &poligono.n);
    scanf ("%d", &poligono.comp_n);
    scanf ("%d", &poligono.h);

}