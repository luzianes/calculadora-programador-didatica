/*
*Calculadora Programador Didática
*Autor: Luziane Pires dos Santos
*Revisões: (25/08/2024 00:24) (25/08/2024 07:05) (25/08/2024 07:15) (25/08/2024 09:07)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conversao_base (int dividendo, int base);
void conversao_bcd (int numeral);

int main (){

    int opcao;
    int numero;
    

    while (1){
        printf ("\n\nCALCULADORA PROGRAMADOR DIDATICA\n\n");
        printf ("================================\n\n");
        printf ("(1) Converter da base 10 para base 2\n\n");
        printf ("(2) Converter da base 10 para base 8\n\n");
        printf ("(3) Converter da base 10 para base 16\n\n");
        printf ("(4) Converter da base 10 para o codigo BCD\n\n");
        printf ("(5) Converter da base 10 para base 2 com 16 bits (complemento a 2)\n\n");
        printf ("(6) Converter real em decimal para float e double\n\n");
        printf ("(7) Sair\n\n");
        printf ("Digite a opcao desejada: ");
        scanf ("%d", &opcao);

        switch (opcao){
        
            case 1: //Conversão da base 10 para base 2

                printf ("\nDigite o numero para ser convertido: ");
                scanf ("%d", &numero);

                conversao_base (numero, 2);
                
                
                break;
            case 2: //Conversão da base 10 para base 8

                printf ("\nDigite o numero para ser convertido: ");
                scanf ("%d", &numero);

                conversao_base (numero, 8);
                break;
            case 3: //Conversão da base 10 para base 16

                printf ("\nDigite o numero para ser convertido: ");
                scanf ("%d", &numero);

                conversao_base (numero, 16);
                break;
            case 4: //Conversão da base 10 para código BCD
                printf ("\nDigite o numero para ser convertido: ");
                scanf ("%d", &numero);

                conversao_bcd (numero);
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

void conversao_base (int dividendo, int base){
    int resto = 0; 
    char resultado [65] = {'\0'};
    char temp [65] = {'\0'};
    int indice = 0;

    printf ("\nFormacao dos digitos a partir do resto de sucessivas divisoes por %d: \n\n", base);

    while (dividendo > 0){
        
        resto = dividendo % base;
        temp[indice] = resto + '0';
        indice++;
        printf ("Divisao de %d por %d =  %d; Resto = %d\n", dividendo, base, dividendo/base, resto);
        dividendo = dividendo/base;
    }
    temp[indice + 1] = dividendo + '0';

    for (int i = 0; i < indice; i++){
        resultado[i] = temp[indice - i - 1];
    }
    printf("\nResultado da conversao, considerando os restos em ordem inversa: ");
    int tamanho = sizeof(resultado) / sizeof(resultado[0]);
    for (int i = 0; i < tamanho; i++){
        if (resultado[i] != -1){
            printf ("%c", resultado[i]);
        }
    }
    printf ("\n\n");
    system ("pause");
   
};



void conversao_bcd (int numeral){

};