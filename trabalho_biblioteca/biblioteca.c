#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

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

struct _tri {
    TRI triangulo;
    double h;
    double b;
    double l;
};

struct _circle {
    CIRCLE cr;
    double r;
};

struct _espacial {
    ESPACIAL esp;
    double x;
    double y;
    double z;
};

TRI *alloc_tri() {
    return malloc (sizeof(TRI));
}

CIRCLE *alloc_circle() {
    return malloc (sizeof(CIRCLE));
}

ESPACIAL *alloc_espacial() {
    return malloc (sizeof(ESPACIAL));
}

POLI *alloc_poli ()
{
    return malloc (sizeof (POLI));
}

FINANCA *alloc_finan ()
{
    return malloc (sizeof (FINANCA));
}

double area_tri_eql(double lado) {
    TRI *p_eql = alloc_tri();
    double area;

    p_eql->triangulo.l = lado;

    area = (pow(p_eql->triangulo.l, 2) * sqrt(3)) / 4;

    free(p_eql);
    return area;
}

double area_tri_iso(double base, double altura) {
    TRI *p_iso = alloc_tri();
    double area;

    p_iso->triangulo.b = base;
    p_iso->triangulo.h = altura;

    area = ((p_iso->triangulo.b) * (p_iso->triangulo.h)) / 2;

    free(p_iso);
    return area;
}

double area_tri_ret(double base, double lado) {
    TRI *p_ret = alloc_tri();
    double altura;
    double area;

    p_ret->triangulo.b = base;
    p_ret->triangulo.l = lado;

    altura = pow(p_ret->triangulo.l, 2) - (pow(p_ret->triangulo.b , 2) / 2);
    area = (p_ret->triangulo.b * altura) / 2;

    free(p_ret);
    return area;
}

double  area_circle(double raio) {
    CIRCLE *p_circle = alloc_circle();
    double area;

    p_circle->cr.r = raio;

    area = PI * pow(p_circle->cr.r, 2);

    free(p_circle);
    return area;
}

double volume_esfera(double raio) {
    ESPACIAL *p_esf = alloc_espacial();
    double volume;

    p_esf->esp.x = raio;

    volume = (4/3) * PI * pow(p_esf->esp.x, 2);

    free(p_esf);
    return volume;
}

double volume_cone(double raio, double altura) {
    ESPACIAL *p_cone = alloc_espacial();
    double volume;

    p_cone->esp.x = raio;
    p_cone->esp.y = altura;

    volume = (PI * pow(p_cone->esp.x, 2) * p_cone->esp.y) / 3;

    free(p_cone);
    return volume;
}

double volume_cilindro(double raio, double altura) {
    ESPACIAL *p_cil = alloc_espacial();
    double volume;

    p_cil->esp.x = raio;
    p_cil->esp.y = altura;

    volume = (PI * pow(p_cil->esp.x, 2) * p_cil->esp.y);

    free(p_cil);
    return volume;
}

double volume_piramide(double altura, double n_base) {
    ESPACIAL *p_pir = alloc_espacial();
    double volume;
    double valor = 0;

    p_pir->esp.x = altura;

    if (n_base == 3) {
        double lado;
        scanf("%lf", & lado);
        valor = area_tri_eql(lado);
    }
    else if (n_base == 4) {
        double lado;
        scanf("%lf", & lado);
        valor = area_quadrado(lado);
    }
    else if (n_base >= 5) {
        double lado, n_lado, apot;
        scanf("%lf %lf %lf", & lado, & n_lado, & apot);
        valor = area_polig_regular(lado, n_lado, apot);
    }
    volume = (1/3) * valor * p_pir->esp.x;

    free(p_pir);
    return volume;
}

double volume_cubo(double lado) {
    ESPACIAL *p_cubo = alloc_espacial();
    double volume;

    p_cubo->esp.x = lado;

    volume = pow(p_cubo->esp.x, 3);

    free(p_cubo);
    return volume;
}
double volume_piramide(double altura, double n_base) {
    ESPACIAL *p_pri = alloc_espacial();
    double volume;
    double valor = 0;

    p_pri->esp.x = altura;

    if (n_base == 3) {
        double lado;
        scanf("%lf", & lado);
        valor = area_tri_eql(lado);
    }
    else if (n_base == 4) {
        double lado;
        scanf("%lf", & lado);
        valor = area_quadrado(lado);
    }
    else if (n_base >= 5) {
        double lado, n_lado, apot;
        printf ("Digite os dados da base da piramide: \n");
        scanf("%lf %lf %lf", & lado, & n_lado, & apot);
        valor = area_polig_regular(lado, n_lado, apot);
    }

    volume = valor * p_pri->esp.x;

    free(p_pri);
    return volume;
}

double area_quadrado (double lado)
{
    POLI *p_quadrado = alloc_poli ();
    double area;

    p_quadrado->quad.h = lado;
    area = (p_quadrado->quad.h) * (p_quadrado->quad.h);

    free (p_quadrado);
    return area;
}

double area_trapezio (double b1, double b2, double h)
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

double area_losango (double b1, double b2)
{
    POLI *p_losango = alloc_poli ();
    double area;

    p_losango->quad.b = b1;
    p_losango->quad.b2 = b2;

    area = (p_losango->quad.b + p_losango->quad.b2) / 2;

    free (p_losango);

    return area;
}

double area_polig_regular (double lados, double n_lado, double apot)
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

double juros_simp (double capital, double taxa, double tempo)
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

double mont_simp (double capital, double juros)
{
    FINANCA *p_mont = alloc_finan ();
    double result;

    p_mont->capital = capital;
    p_mont->juros = juros;

    result = p_mont->capital + p_mont->juros;

    free (p_mont);

    return result;
}

double mont_comp (double capital, double taxa, double tempo)
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