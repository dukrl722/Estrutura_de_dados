#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

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

double area_tri_esc(double h, double l, double b) {

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
        valor = //função aqui
    }
    else if (n_base == 5) {
        double lado;
        scanf("%lf", & lado);
        valor = //função aqui
    }
    else if (n_base == 6) {
        double lado;
        scanf("%lf", & lado);
        valor = //função aqui
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
        valor = //função aqui
    }
    else if (n_base == 5) {
        double lado;
        scanf("%lf", & lado);
        valor = //função aqui
    }
    else if (n_base == 6) {
        double lado;
        scanf("%lf", & lado);
        valor = //função aqui
    }

    volume = valor * p_pri->esp.x;

    free(p_pri);
    return volume;
}