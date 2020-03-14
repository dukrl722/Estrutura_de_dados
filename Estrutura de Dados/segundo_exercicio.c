#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x, j, i, w;
    int troca = 0, z = 0;
    scanf("%i", & x);
    int vet[x];
    for(w = 0; w < x; w++)
    {
        int valores;
        scanf("%i", &valores);
    }
    
    for(j = 0; j < i; j++)
    {
        for(i = j-1; i < j; i--)
        {
            if(vet[j] < vet[j-1])
            {
                z = cerot[j];
                vet[j] = vet[j-1];
                vet[j-1] = z;
                troca = 1;
            }
            if(troca != 1){
                break;
            }
        }
        printf("%i", vet[j]);
    }
    return 0;