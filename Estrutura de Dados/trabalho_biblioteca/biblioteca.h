#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

typedef struct point{
    double x;
    double y;
    double h;
}; Point;
//----------------------------CIRCULAR--------------------------------

/*a função area_circle faz o calculo da área de um circulo sendo necessários
apenas 2 parametros: um para o raio ao quadrado, e o outro para o valor de pi*/
double area_circle {
    Point x,
    Point y
};

//----------------------------3 LADOS--------------------------------

/*a função area_tri_esc faz o calculo da área de um triangulo escaleno
sendo necessários 3 parametros, por conta dos seus 3 lados diferentes*/
double area_tri_esc {
    Point x,
    Point y,
    Point h
};

/*a função area_tri_ret faz o calculo da area de um triangulo retângulo
sendo necessários 2 parametros, por conta do seu angulo reto, que não irá
interferir no cálculo. Os outros parâmetros são a altura e a hipotenusa*/

double area_tri_ret {
    Point x,
    Point y
};
/*os triângulos retângulos podem estar posicionados de maneiras diferentes
na tela, porém o valor da sua hipotenusa na função não irá variar*/

/*a função area_tri_iso faz o calculo da área de um triângulo isósceles
sendo necessários apenas 2 parãmetros. Para calcular a area do isósceles,
é necessário primeiro calcular a sua altura*/
double area_tri_iso {
    Point x,
    Point y
};

/*a função area_tri_eql faz o calculo da área de um triângulo equilátero
sendo necessário apenas 1 parâmetro. Para facilitar o calculo, o
triângulo é dividido em 2, automaticamente dividindo o valor da base por
dois também*/
double area_tri_eql {
    Point x
};

//----------------------------4 LADOS--------------------------------
//----------------------------ESPACIAL--------------------------------

/*a função volume_esfera faz o calculo do volume usando os valores de pi, e
do seu raio ao cubo*/
double volume_esfera {
        Point x
};

/*a função volume_cone faz o calculo do volume usando os valores de pi,
da area da base (Ab), do raio ao cubo e da altura */
double volume_cone {
    Point x,
    Point y,
    Point z
};

/*a função volume_cilindro faz o calculo do volume usando os valores de pi,
da altura e do raio ao quadrado*/
double volume_cilindro {
    Point x,
    Point y
};

#endif