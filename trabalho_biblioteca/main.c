#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"
#include <time.h>

int main ()
{
    int opc;
    double a, b, c, d;

    while (1)
    {
        puts ("Digite '1' para calcular a area de um triangulo\n");
        puts ("Digite '2' para calcular a area de um circulo\n");
        puts ("Digite '3' para calcular a area de um quadrilatero\n");
        puts ("Digite '4' para calcular a area de um poligono (5 lados ou mais)\n");
        puts ("Digite '5' para calcular um juros simples\n");
        puts ("Digite '6' para calcular um montante de juros simples\n");
        puts ("Digite '7' para calcular um montande de juros compostos\n");
        puts ("Digite '8' para calcular o volume de uma geometria\n");
        puts ("Digite '0' para sair\n");

        scanf ("%d", &opc);

        switch (opc)
        {
            case 1: //calcula triangulo
                printf ("Quer calcular qual triangulo?\n");
                printf ("equilatero - 1\n");
                printf ("isosceles - 2\n");
                printf ("reto - 3\n");
                int numero;
                scanf ("%i", &numero);
                if (numero == 1) {
                    scanf ("%lf", &a);
                    printf ("Area do triangulo equilatero = %lf\n", area_tri_eql(a));
                }
                else if (numero == 2)
                {
                    scanf ("%lf %lf", &a, &b);
                    printf ("Area do triangulo isosceles = %lf\n", area_tri_iso(a, b));
                }
                else if (numero == 3)
                {
                    scanf ("%lf %lf", &a, &b);
                    printf ("Area do triangulo reto = %lf\n", area_tri_ret(a, b));
                }
                break;

            case 2: //calcula circulo
                scanf ("%lf", &a);
                printf ("Area do circulo = %lf\n", area_circle(a));
                break;

            case 3: //calcula quadrilatero
                printf ("Quer calcular qual quadrilatero?\n");
                printf ("quadrado - 1\n");
                printf ("trapezio - 2\n");
                printf ("losango - 3\n");
                int numero;
                scanf ("%i", &numero);
                if (numero == 1) {
                    scanf ("%lf", &a);
                    printf ("Area do quadrado = %lf\n", area_quadrado(a));
                }
                else if (numero == 2)
                {
                    scanf ("%lf %lf %lf", &a, &b, &c);
                    printf ("Area do trapezio = %lf\n", area_trapezio(a, b, c));
                }
                else if (numero == 3)
                {
                    scanf ("%lf %lf", &a, &b);
                    printf ("Area do losango = %lf\n", area_losango(a, b));
                }
                break;
            case 4: //calcula poligono
                scanf ("%lf %lf %lf", &a, &b, &c);
                printf ("Area do poligono de %lf lados = %lf\n", b, area_polig_regular(a, b, c));
                break;

            case 5: //calcula juros simples
                printf ("Digite o capital aplicado, a taxa e o tempo de aplicacao: ");
                scanf ("%lf %lf %lf", &a, &b, &c);
                printf ("\n");
                printf ("Juros simples: %.3lf\n", juros_simp (a, b, c));
                sleep (2);
                break;

            case 6: //calcula montante simples
                printf ("Digite o capital aplicado e o juros simples da aplicacao: ");
                scanf ("%lf %lf", &a, &b);
                printf ("\n");
                printf ("Montante simples: %.3lf\n", mont_simp (a, b));
                sleep (2);
                break;

            case 7:
                printf ("Digite o capital aplicado, a taxa e o tempo de aplicacao: ");
                scanf ("%lf %lf %lf", &a, &b, &c);
                printf ("\n");
                printf ("Montante composto: %.3lf\n", mont_comp (a, b, c));
                sleep (2);
                break;

            case 8: //espacial    
                printf ("Quer calcular qual figura espacial?");
                printf ("piramide - 1\n");
                printf ("cubo - 2\n");
                printf ("cilindro - 3\n");
                printf ("cone - 4\n");
                printf ("esfera - 5\n");
                int numero;
                scanf ("%i", &numero);
                if (numero == 1) {
                    scanf ("%lf %lf", &a, &b);
                    printf ("Volume da piramide = %lf\n", volume_piramide(a, b));
                }
                else if (numero == 2)
                {
                    scanf ("%lf", &a);
                    printf ("Volume do cubo = %lf\n", volume_cubo(a));
                }
                else if (numero == 3)
                {
                    scanf ("%lf %lf", &a, &b);
                    printf ("Volume do cilindro = %lf\n", volume_cilindro(a, b));
                }
                else if (numero == 4)
                {
                    scanf ("%lf %lf", &a, &b);
                    printf ("Volume do cone = %lf\n", volume_cone(a, b));
                }
                else if (numero == 5)
                {
                    scanf ("%lf", &a);
                    printf ("Volume da esfera = %lf\n", volume_esfera(a));
                }
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
}