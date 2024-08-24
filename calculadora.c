/*
*Calculadora Programador Didática
*
*Autor: Luziane Pires dos Santos
*
*Revisões: 
*(24/08/2024 00:24): implementação da função de conversão para base 2;
*(24/08/2024 07:05): implementação da função de conversão para base 8;
*(24/08/2024 07:15): implementação da função de conversão para base 16;
*(24/08/2024 09:07): unificação das funções de conversão na função conversao_base;
*(24/08/2024 16:45): implementação da conversão para código BCD;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void conversao_base (int dividendo, int base);
char* conversao_base_simplificada (int dividendo);
void conversao_bcd (int dividendo);

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

//Função para conversão de um número na base especificada
void conversao_base (int dividendo, int base){
    int resto = 0; 
    char resultado [65] = {'\0'};
    char temp [65] = {'\0'};
    int indice = 0;

    printf ("\nFormacao dos digitos a partir do resto de sucessivas divisoes por %d: \n\n", base);

    //Sucessivas divisões pela base e extração do resto
    while (dividendo > 0){
        
        resto = dividendo % base;
        temp[indice] = resto + '0';
        indice++;
        printf ("Divisao de %d por %d =  %d; Resto = %d\n", dividendo, base, dividendo/base, resto);
        dividendo = dividendo/base;
    }
    //Converte o número em char e armazena no array temp
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

//Função para converter 1 algarismo para a base 2, sem impressão
char* conversao_base_simplificada(int dividendo) {
    int resto = 0;
    char temp[5] = {'\0'};  
    int indice = 0;

    //Sucessivas divisões pela base 2 e extração do resto
    while (dividendo > 0) {
        resto = dividendo % 2;
        temp[indice] = resto + '0';
        indice++;
        dividendo = dividendo / 2;
    }

    //Completa os bits restantes com '0' para formar 4 bits
    while (indice < 4) {
        temp[indice] = '0';
        indice++;
    }

    //Alocação de memória para a string (array) que vai receber o resultado da conversão
    char* resultado = (char*)malloc((indice + 1) * sizeof(char));
    if (resultado == NULL) {
        return NULL;  
    }

    //Inversão de temp e atribuição à variável resultado
    for (int i = 0; i < indice; i++) {
        resultado[i] = temp[indice - i - 1];
    }
    resultado[indice] = '\0';

    return resultado;
};

void conversao_bcd(int dividendo) {
    char resultado[150] = {'\0'};
    char* temp_resultados[10];
    int digitos = 0;

    printf("\nFormacao dos digitos a partir do resto de sucessivas divisoes por 2:\n\n");

    // Separação dos algarismos do número na base 10
    while (dividendo > 0) {
        int digito = dividendo % 10;  //Extrai o último algarismo e armazena na variável digito
        dividendo = dividendo / 10;   //Remove o último dígito do número a ser convertido

        //Conversao do dígito em binário através da função conversao_base_simplificada    
        char* binario = conversao_base_simplificada(digito);
        printf("Conversao do digito %d: %s\n", digito, binario);
        if (binario != NULL) {
            temp_resultados[digitos] = binario;
            digitos++;
        }
    }

    //Concatenação da conversão atual (temp) na string resultado
    for (int i = digitos - 1; i >= 0; i--) {
        strcat(resultado, temp_resultados[i]);
        strcat(resultado, " ");
        free(temp_resultados[i]); 
    }

    printf("\nResultado da conversao em codigo BCD de 4 bits, completando os bits vazios com zero (0): ");
    printf("%s\n", resultado);

    printf("\n\n");
    system("pause");
};