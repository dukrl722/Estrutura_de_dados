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
    double h;
    double b;
    double l;
};

struct _circle {
    double r;
};

struct _espacial {
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

double area_tri_eql(double lado, TRI *p_eql) {
    double area;

    p_eql->l = lado;

    area = (pow(p_eql->l, 2) * sqrt(3)) / 4;

    return area;
}

double area_tri_iso(double base, double altura, TRI *p_iso) {
    double area;

    p_iso->b = base;
    p_iso->h = altura;

    area = ((p_iso->b) * (p_iso->h)) / 2;

    return area;
}

double area_tri_ret(double base, double lado, TRI *p_ret) {
    double altura;
    double area;

    p_ret->b = base;
    p_ret->l = lado;

    altura = pow(p_ret->l, 2) - (pow(p_ret->b , 2) / 2);
    area = (p_ret->b * altura) / 2;

    return area;
}

double  area_circle(double raio, CIRCLE *p_circle) {
    double area;

    p_circle->r = raio;

    area = PI * pow(p_circle->r, 2);

    return area;
}

double volume_esfera(double raio, ESPACIAL *p_esf) {
    double volume;

    p_esf->x = raio;

    volume = (4/3) * PI * pow(p_esf->x, 2);

    return volume;
}

double volume_cone(double raio, double altura, ESPACIAL *p_cone) {
    double volume;

    p_cone->x = raio;
    p_cone->y = altura;

    volume = (PI * pow(p_cone->x, 2) * p_cone->y) / 3;

    return volume;
}

double volume_cilindro(double raio, double altura, ESPACIAL *p_cil) {
    double volume;

    p_cil->x = raio;
    p_cil->y = altura;

    volume = (PI * pow(p_cil->x, 2) * p_cil->y);

    return volume;
}

double volume_cubo(double lado, ESPACIAL *p_cubo) {
    double volume;

    p_cubo->x = lado;

    volume = pow(p_cubo->x, 3);

    return volume;
}
double volume_piramide(double altura, double n_base, ESPACIAL *p_pri) {
     double volume;
     double valor = 0;
     POLI *p_quadrado = alloc_poli ();
     TRI *p_eql = alloc_tri ();
     POLI *p_polig = alloc_poli ();

     p_pri->x = altura;

     if (n_base == 3) {
         double lado;
         scanf("%lf", & lado);
         valor = area_tri_eql(lado, p_eql);
     }
     else if (n_base == 4) {
         double lado;
         scanf("%lf", & lado);
         valor = area_quadrado(lado, p_quadrado);
     }
     else if (n_base >= 5) {
         double lado, n_lado, apot;
         printf ("Digite os dados da base da piramide: \n");
         scanf("%lf %lf %lf", & lado, & n_lado, & apot);
         valor = area_polig_regular(lado, n_lado, apot, p_polig);
     }

     volume = valor * p_pri->x;

    free (p_quadrado);
    free (p_eql);
    free (p_polig);

     return volume;
}

double area_quadrado (double lado, POLI *p_quadrado)
{
    double area;

    p_quadrado->quad.h = lado;
    area = (p_quadrado->quad.h) * (p_quadrado->quad.h);

    return area;
}

double area_trapezio (double b1, double b2, double h, POLI *p_trapezio)
{
    double area;

    p_trapezio->quad.b = b1;
    p_trapezio->quad.b2 = b2;
    p_trapezio->quad.h = h;
    area = (( (p_trapezio->quad.b) + (p_trapezio->quad.b2) ) * p_trapezio->quad.h) / 2;

    return area;
}

double area_losango (double b1, double b2, POLI *p_losango)
{
    double area;

    p_losango->quad.b = b1;
    p_losango->quad.b2 = b2;

    area = (p_losango->quad.b + p_losango->quad.b2) / 2;

    return area;
}

double area_polig_regular (double lados, double n_lado, double apot, POLI *p_polig)
{
    double area;

    p_polig->n = lados;
    p_polig->comp_n = n_lado;
    p_polig->h = apot;

    area = (p_polig->n * p_polig->comp_n * p_polig->h) / 2;

    return area;
}

double juros_simp (double capital, double taxa, double tempo, FINANCA *p_juros)
{
    double result;

    p_juros->capital = capital;
    p_juros->taxa = taxa;
    p_juros->tempo = tempo;

    result = p_juros->tempo * p_juros->taxa * p_juros->capital;

    return result;
}

double mont_simp (double capital, double juros, FINANCA *p_mont)
{
    double result;

    p_mont->capital = capital;
    p_mont->juros = juros;

    result = p_mont->capital + p_mont->juros;

    return result;
}

double mont_comp (double capital, double taxa, double tempo, FINANCA *p_mont)
{
    double result;

    p_mont->capital = capital;
    p_mont->taxa = taxa;
    p_mont->tempo = tempo;

    result = p_mont->capital * pow ( 1 + p_mont->taxa, p_mont->tempo);

    return result;
}