#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct _tri TRI;
typedef struct _circle CIRCLE;
typedef struct _espacial ESPACIAL;
typedef struct _quadri QUADRI;
typedef struct _poli POLI;
typedef struct _financa FINANCA;

//---------------------  FUNÇÕES DE ALOCAÇÃO  -----------------------

POLI *alloc_poli ();
TRI *alloc_tri();
CIRCLE *alloc_circle();
ESPACIAL *alloc_espacial();
POLI *alloc_poli ();
FINANCA *alloc_finan ();

//----------------------------CIRCULAR--------------------------------

/*a função area_circle faz o calculo da área de um circulo sendo necessários
apenas 1 parametro: o raio ao quadrado, pois o valor de pi já é pré-definido*/
double area_circle (double x, CIRCLE *p_circle);

//----------------------------3 LADOS--------------------------------

/*a função area_tri_ret faz o calculo da area de um triangulo retângulo
sendo necessários 2 parametros, por conta do seu angulo reto, que não irá
interferir no cálculo. Os outros parâmetros são a altura e a hipotenusa*/

double area_tri_ret (double h, double l, TRI *p_triangulo);
/*os triângulos retângulos podem estar posicionados de maneiras diferentes
na tela, porém o valor da sua hipotenusa na função não irá variar*/

/*a função area_tri_iso faz o calculo da área de um triângulo isósceles
sendo necessários apenas 2 parãmetros. Para calcular a area do isósceles,
é necessário primeiro calcular a sua altura*/
double area_tri_iso (double h, double l, TRI *p_triangulo);

/*a função area_tri_eql faz o calculo da área de um triângulo equilátero
sendo necessário apenas 1 parâmetro. Para facilitar o calculo, o
triângulo é dividido em 2, automaticamente dividindo o valor da base por
dois também*/
double area_tri_eql (double l, TRI *p_triangulo);

//----------------------------4 LADOS--------------------------------

double area_quadrado (double lado, POLI *p_quadrado);

double area_trapezio (double b1, double b2, double h, POLI *p_trapezio);

double area_losango (double b1, double b2, POLI *p_losango);

double area_polig_regular (double lados, double n_lado, double apot, POLI *p_polig);

//----------------------------ESPACIAL--------------------------------

/*a função volume_esfera faz o calculo do volume usando os valores de pi, e
do seu raio ao cubo*/
double volume_esfera (double x, ESPACIAL *p_esf);

/*a função volume_cone faz o calculo do volume usando os valores de pi
 do raio ao quadrado e da altura */
double volume_cone (double x, double y, ESPACIAL *p_cone);

/*a função volume_cilindro faz o calculo do volume usando os valores de pi,
da altura e do raio ao quadrado*/
double volume_cilindro (double x, double y, ESPACIAL *p_cil);

/*a função volume_piramide faz o calculo do volume usando os valores da area da
base e da altura*/
double volume_piramide (double x, double y, ESPACIAL *p_piram);

/*a função volume_cubo faz o calculo do volume utilizando apenas o valor do lado,
pois o cubo possui todos os lados com valores iguais*/
double volume_cubo (double x, ESPACIAL *p_cubo);

/*a função volume_prisma faz o calculo do volume utilizando os valores da area da
base e da altura. Uma observação a ser feita, é o fato de que o paralelepipedo
 é, nada mais nada menos, do que um prisma quadrangular*/
double volume_prisma (double x, double y, ESPACIAL *p_volume);

//----------------------------FINANCEIRO--------------------------------

double juros_simp (double capital, double taxa, double tempo, FINANCA *p_jur_simp);

double mont_simp (double capital, double juros, FINANCA *p_mont_simp);

double mont_comp (double capital, double taxa, double tempo, FINANCA *p_mont_comp);

#endif