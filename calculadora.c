/*
*Calculadora Programador Didática
*Autor: Luziane Pires dos Santos
*Revisões: (24/08/2024 00:24)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conversao_base_2 (int dividendo);

int main (){

    int opcao;
    int numero;
    int dividendo, resto;
    

    while (1){
        printf ("\n\nCALCULADORA PROGRAMADOR DIDATICA\n\n");
        printf ("================================\n\n");
        printf ("Digite a opcao desejada: \n\n");
        printf ("(1) Converter da base 10 para base 2\n\n");
        printf ("(2) Converter da base 10 para base 8\n\n");
        printf ("(3) Converter da base 10 para base 16\n\n");
        printf ("(4) Converter da base 10 para o codigo BCD\n\n");
        printf ("(5) Converter da base 10 para base 2 com 16 bits (complemento a 2)\n\n");
        printf ("(6) Converter real em decimal para float e double\n\n");
        printf ("(7) Sair\n\n");

        scanf ("%d", &opcao);

        switch (opcao){
        
            case 1: //Conversão da base 10 para base 2

                printf ("\nDigite o numero para ser convertido: ");
                scanf ("%d", &numero);

                conversao_base_2 (numero);
                
                
                break;
            case 2: //Conversão da base 10 para base 8
            /* code */
                break;
            case 3: //Conversão da base 10 para base 16
            /* code */
                break;
            case 4: //Conversão da base 10 para código BCD
            /* code */
                break;
            case 5: //Conversão da base 10 para base 2 com 16 bits (complemento a 2)
            /* code */
                break;
            case 6: //Conversão de real em decimal para float e double
            /* code */
                break;
            case 7: //Sair
                return 0;
                break;
        
            default:
                printf ("Opcao invalida!");
                break;
        }
    }

    return 0;

}

void conversao_base_2 (int dividendo){
    int resto = 0; 
    char base2 [65] = {'\0'};
    char temp [65] = {'\0'};
    int indice = 0;

    printf ("\nFormacao dos digitos a partir do resto de sucessivas divisoes por 2: \n\n");

    while (dividendo > 0){
        
        resto = dividendo % 2;
        temp[indice] = resto + '0';
        indice++;
        printf ("Divisao de %d por 2 =  %d; Resto = %d\n", dividendo, dividendo/2, resto);
        dividendo = dividendo/2;
    }
    temp[indice + 1] = dividendo + '0';

    for (int i = 0; i < indice; i++){
        base2[i] = temp[indice - i - 1];
    }
    printf("\nResultado da conversao, considerando os restos em ordem inversa: ");
    int tamanho = sizeof(base2) / sizeof(base2[0]);
    for (int i = 0; i < tamanho; i++){
        if (base2[i] != -1){
            printf ("%c", base2[i]);
        }
    }
    printf ("\n");
    system ("pause");
   
};