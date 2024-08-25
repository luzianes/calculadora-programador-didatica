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
*(25/08/2024 00:19): implementação da conversão em complemento a 2;
*(25/08/2024 12:46): correção de bugs nas funções conversao_base e conversao_bcd;
*(25/08/2024 15:33): iniciada a implementação da função de conversão para float e double;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void conversao_base (int dividendo, int base);
char* conversao_base_simplificada (int dividendo);
void conversao_bcd (int dividendo);
void conversao_complemento2 (int dividendo);
void conversao_float_double (double decimal);
int contar_digitos_fracionarios(double parte_fracionaria);

int main (){

    int opcao;
    int numero;
    double numero_real;
    

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
                printf ("\nDigite o numero (sem sinal) para ser convertido em binário negativo: ");
                scanf ("%d", &numero);
                conversao_complemento2 (numero);
                break;
            case 6: //Conversão de real em decimal para float e double
                printf ("\nDigite o numero real para ser convertido em float e double (Ex.: 100.375): ");
                scanf ("%lf", &numero_real);
                conversao_float_double (numero_real);              
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
    printf ("\n====================================================================");
    printf ("\nFormacao dos digitos a partir do resto de sucessivas divisoes por %d", base);
    printf ("\n--------------------------------------------------------------------");
    if (dividendo == 0){

        resto = dividendo % base;
        printf ("\n# Divisao de %d por %d = %d; Resto = %d.", dividendo, base, dividendo/base, resto);
        printf ("\n--------------------------------------------------------------------");
        printf("\nResultado da conversao: %d", dividendo/base);
        printf ("\n====================================================================");
    } else {
    
        //Sucessivas divisões pela base e extração do resto
        while (dividendo > 0){
            
            resto = dividendo % base;
            if (base == 16){
                if (resto == 10){
                    temp[indice] = 'A';
                } else if (resto == 11){
                    temp[indice] = 'B';
                } else if (resto == 12){
                    temp[indice] = 'C';
                } else if (resto == 13){
                    temp[indice] = 'D';
                } else if (resto == 14){
                    temp[indice] = 'E';
                } else if (resto == 15){
                    temp[indice] = 'F';
                } else {
                temp[indice] = resto + '0';
                }
            } else {
                temp[indice] = resto + '0';
            }
            indice++;
            printf ("\n# Divisao de %d por %d = %d; Resto = %d", dividendo, base, dividendo/base, resto);
            dividendo = dividendo/base;
            
        }
        printf ("\n--------------------------------------------------------------------");
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
        printf ("\n====================================================================");
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

//Função para converter o número em código BCD
void conversao_bcd(int dividendo) {
    char resultado[150] = {'\0'};
    char* temp_resultados[10];
    int digitos = 0;

    printf("\nFormacao dos digitos a partir do resto de sucessivas divisoes por 2:\n\n");

    if (dividendo == 0){
        printf ("Divisao de %d por 2 =  %d; Resto = %d.", dividendo, dividendo / 2, dividendo % 2);
        resultado[3] = dividendo / 2 + '0';
        for (int i = 0; i < 3; i++){
            resultado [i] = '0';
        }
        resultado[4] = '\0';

    } else {
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
    }
        printf("\n\nResultado da conversao em codigo BCD de 4 bits, completando os bits vazios com zero (0): ");
        printf("%s\n", resultado);
    
    printf("\n\n");
    system("pause");
};

//Função para conversão de um número em complemento a 2
void conversao_complemento2 (int dividendo){
    int resto = 0; 
    char resultado [17] = {'\0'};
    char temp [17] = {'\0'};
    int indice = 0;

    printf ("\nFormacao dos digitos a partir do resto de sucessivas divisoes por %d: \n\n", 2);

    //Sucessivas divisões pela base e extração do resto
    while (dividendo > 0){
        
        resto = dividendo % 2;
        temp[indice] = resto + '0';
        indice++;
        printf ("Divisao de %d por %d =  %d; Resto = %d\n", dividendo, 2, dividendo/2, resto);
        dividendo = dividendo/2;
    }

    //Completa os bits restantes com '0' para formar 16 bits
    while (indice < 17) {
        temp[indice] = '0';
        indice++;
    }
    //Converte o número em char e armazena no array temp
    temp[indice + 1] = dividendo + '0';

    for (int i = 0; i < indice; i++){
        resultado[i] = temp[indice - i - 1];
    }
    
    printf("\n\nResultado da conversao na base 2 considerando os restos em ordem inversa: ");
    int tamanho = sizeof(resultado) / sizeof(resultado[0]);

    for (int i = 1; i < tamanho; i++){
        printf ("%c", resultado[i]);
        if (i % 4 == 0){
            printf (" ");
        }
    }

    //Cálculo do complemento de 2
    int encontrou1 = 0;
    for (int i = 16; i > 0; i--) {

        if (encontrou1) {
            // Inversão dos bits após o primeiro '1'
            if (resultado[i] == '0') {
                resultado[i] = '1';
            } else {
                resultado[i] = '0';
            }
        } else if (resultado[i] == '1') {
            encontrou1 = 1; 
        }
    }
    printf ("\n\nResultado da conversao em complemento a 2 (inversao dos bits apos o primeiro 1): ");
    for (int i = 1; i < tamanho; i++){
        printf ("%c", resultado[i]);
        if (i % 4 == 0){
            printf (" ");
        }
    }
    printf ("\n\n");
    system ("pause");
   
};

//Função para converter um número decimal em float e double
void conversao_float_double (double decimal){
    //Separação da parte inteira da parte fracionária em duas variáveis
    printf ("\n=============================================================================================");
    printf ("\nSeparacao da parte inteira da parte fracionaria: ");
    double parte_fracionaria = modf(decimal, &decimal);
    int parte_inteira = (int)decimal;
    printf ("\n---------------------------------------------------------------------------------------------");
    printf ("\nParte inteira: %d", parte_inteira);
    printf ("\nParte fracionaria: %g", parte_fracionaria);
    printf ("\n---------------------------------------------------------------------------------------------");
    int resto = 0; 
    char resultado [65] = {'\0'};
    char temp [65] = {'\0'};
    int indice = 0;

    //Conversão da parte inteira
    printf ("\nFormacao dos digitos da parte inteira a partir do resto de sucessivas divisoes por %d", 2);
    printf ("\n---------------------------------------------------------------------------------------------");
    if (parte_inteira == 0){

        resto = parte_inteira % 2;
        printf ("\n# Divisao de %d por %d = %d; Resto = %d.", parte_inteira, 2, parte_inteira/2, resto);
        printf ("\n---------------------------------------------------------------------------------------------");
        printf("\nResultado da conversao da parte inteira: %d", parte_inteira/2);
        printf ("\n===========================================================================================");
    } else {
    
        //Sucessivas divisões pela base e extração do resto
        while (parte_inteira > 0){
            
            resto = parte_inteira % 2;
            
            temp[indice] = resto + '0';
            
            indice++;
            printf ("\n# Divisao de %d por %d = %d; Resto = %d", parte_inteira, 2, parte_inteira/2, resto);
            parte_inteira = parte_inteira/2;
            
        }
        printf ("\n---------------------------------------------------------------------------------------------");
        //Converte o número em char e armazena no array temp
        temp[indice + 1] = parte_inteira + '0';

        for (int i = 0; i < indice; i++){
            resultado[i] = temp[indice - i - 1];
        }
        
        //Impressão da conversão da parte inteira
        printf("\nResultado da conversao da parte inteira considerando os restos em ordem inversa: ");
        int tamanho = sizeof(resultado) / sizeof(resultado[0]);
        for (int i = 0; i < tamanho; i++){
            if (resultado[i] != -1){
                printf ("%c", resultado[i]);
            }
        }

        //Conversão da parte fracionária
        int digitos_fracionarios = contar_digitos_fracionarios(parte_fracionaria);
        printf ("\nquantidade de dígitos %d", digitos_fracionarios);
        
        for (int i = 0; i < digitos_fracionarios; i++){
            parte_fracionaria = parte_fracionaria * 2;

            if (parte_fracionaria > 1.0) {
                parte_fracionaria = parte_fracionaria - 1;
                //guarda 1 da parte inteira para formar o resto
            } else if (parte_fracionaria < 1.0){
                //guarda 0 a parte inteira para formar o resto
            }
        }
        //FALTAAAAAAAAAAAA --------------------------------------------------
        //abrir um array temporário para salvar os restos
        //inverter a ordem do array
        //formar o número juntando com a parte inteira
        //normalizar, colocando a vírgula após o primeiro 1 - imprimir bit de sinal
        //identificar o expoente e imprimir
        //aplicar o bias no expoente e imprimir
        //imprimir o número em float e double de acordo com a quantidade de bits


        
        printf ("\n=============================================================================================");
    }
    printf ("\n\n");
    system ("pause");

};

int contar_digitos_fracionarios(double parte_fracionaria) {
    int contador = 0;

    // Enquanto houver casas decimais após o ponto
    while (parte_fracionaria != 0.0 && contador < 15) { // Limitando a 15 casas decimais
        parte_fracionaria *= 10;
        parte_fracionaria -= (int)parte_fracionaria;  // Remove a parte inteira
        contador++;
    }

    return contador;
};

