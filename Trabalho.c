#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>


//Compilador: GCC
//Sistema Operacional: MacOS


void reverseString(char* str) 
{
    int length = strlen(str);
    int a, b;
    
    for (a = 0, b = length - 1; a < b; a++, b--) {
            char temp = str[a];
            str[a] = str[b];
            str[b] = temp;
    }
}


int binarioDecimal()
{   
    long long int decimal = 0, i = 0, resto, binario, temp, ret;

    printf("Insira o número em binário que deseja converter para decimal: ");

    ret = scanf("%lld", &binario);

    while (getchar() != '\n');


    if(ret != 1 || binario < 0)
    {
        printf("\nNúmero binário inválido.\n");
        printf("Tente novamente.\n\n");
        binarioDecimal();
        return 0;
    }

    temp = binario;

    while (binario != 0) {
        resto = binario % 10;
        
        if(resto > 1 || resto < 0)
        {
            printf("\nNúmero binário inválido.\n");
            printf("Tente novamente.\n\n");
            binarioDecimal();
            return 0;
        }
        binario /= 10;
        decimal += resto * pow(2, i);
        ++i;
    }

    printf("\n\n%lld(2) = %lld(10)\n", temp,decimal);

    return 0;


}

int binarioOctal()
{
    long long int j = 1, decimal = 0, i = 0, resto, binario, temp, octal = 0, ret;
    printf("Insira o número em binário que deseja converter para octal: ");

    ret = scanf("%lld", &binario);

    while (getchar() != '\n');


    if(ret != 1 || binario < 0)
    {
        printf("\nNúmero binário inválido.\n");
        printf("Tente novamente.\n\n");
        binarioOctal();
        return 0;
    }

    temp = binario;
    
    
    while (binario != 0) 
    {
        resto = binario % 10;
        
        if(resto > 1 || resto < 0)
        {
            printf("\nNúmero binário inválido.\n");
            printf("Tente novamente.\n\n");
            binarioOctal();
            return 0;
        }
        binario /= 10;
        decimal += resto * pow(2, i);
        i++;
    }


    while(decimal > 0)
    {
        octal += (decimal % 8) * j;
        j*=10;
        decimal /= 8;
    }
    
    printf("\n\n%lld(2) = %lld(8)\n\n", temp, octal);

    return 0;

}

int binarioHexa()
{
    long long int binario, decimal = 0, i = 0, resto, j = 0, binarionicio, ret;
    char hexadecimal[100] = "";
    
    printf("Insira o número em binário que deseja converter para hexadecimal: ");

    ret = scanf("%lld", &binario);

    while (getchar() != '\n');


    if(ret != 1 || binario < 0)
    {
        printf("\nNúmero binário inválido.\n");
        printf("Tente novamente.\n\n");
        binarioHexa();
        return 0;
    }

    binarionicio = binario;

    while (binario != 0) 
    {
        resto = binario % 10;
        
        if(resto > 1 || resto < 0)
        {
            printf("\nNúmero binário inválido.\n");
            printf("Tente novamente.\n\n");
            binarioHexa();
            return 0;
        }
        binario /= 10;
        decimal += resto * pow(2, i);
        i++;
    }

    while(decimal != 0)
    {
        resto = decimal % 16;

        switch(resto)
        {
            case 0:
                hexadecimal[j] = '0';
                break;
            case 1:
                hexadecimal[j] = '1';
                break;
            case 2:
                hexadecimal[j] = '2';
                break;
            case 3:
                hexadecimal[j] = '3';
                break;
            case 4:
                hexadecimal[j] = '4';
                break;
            case 5:
                hexadecimal[j] = '5';
                break;
            case 6:
                hexadecimal[j] = '6';
                break;
            case 7:
                hexadecimal[j] = '7';
                break;
            case 8:
                hexadecimal[j] = '8';
                break;
            case 9:
                hexadecimal[j] = '9';
                break;
            case 10:
                hexadecimal[j] = 'A';
                break;
            case 11:
                hexadecimal[j] = 'B';
                break;
            case 12:
                hexadecimal[j] = 'C';
                break;
            case 13:
                hexadecimal[j] = 'D';
                break;
            case 14:
                hexadecimal[j] = 'E';
                break;
            case 15:
                hexadecimal[j] = 'F';
                break;
        }

        decimal /= 16;
        j++;
    }

    hexadecimal[j] = '\0';
    reverseString(hexadecimal);

    printf("\n\n%lld(2) = %s(16)\n", binarionicio, hexadecimal);

    return 0;
}

int octalBinario()
{
    long long int octal, decimal = 0, i = 0, ret;
    char binario[200];

    printf("Insira o número em octal que deseja converter para binário: ");

    ret = scanf("%lld", &octal);

    while (getchar() != '\n');


    if(ret != 1 || octal < 0)
    {
        printf("\nNúmero octal inválido.\n");
        printf("Tente novamente.\n\n");
        octalBinario();
        return 0;
    }

    long long int temp = octal;

    while(octal != 0)
    {
        if(octal % 10 > 7 || octal % 10 < 0)
        {
            printf("\nNúmero octal inválido\n");
            printf("Tente novamente.\n\n");
            octalBinario();
            return 0;
        }

        decimal += octal % 10 * pow(8,i);
        octal/=10;
        i++;
    }

    i = 0;

    while(decimal != 0)
    {
        binario[i] = decimal % 2 + '0';
        decimal /=2;
        i++;
    }

    binario[i] = '\0';

    reverseString(binario);

    printf("\n\n%lld(8) = %s(2)\n", temp, binario);

    return 0;

}

int octalDecimal()
{
    long long int octal, decimal = 0, i = 0, temp, ret;
    printf("Insira o número em octal que deseja converter para decimal: ");

    ret = scanf("%lld", &octal);

    while (getchar() != '\n');


    if(ret != 1 || octal < 0)
    {
        printf("\nNúmero octal inválido.\n");
        printf("Tente novamente.\n\n");
        octalDecimal();
        return 0;
    }

    temp = octal;




    while(octal != 0)
    {
        if(octal % 10 > 7 || octal % 10 < 0)
        {
            printf("\nNúmero octal inválido\n");
            printf("Tente novamente.\n\n");
            octalDecimal();
            return 0;
        }

        decimal += octal % 10 * pow(8,i);
        octal/=10;
        i++;
    }

    printf("\n\n%lld(8) = %lld(10)\n", temp, decimal);

    return 0;
}

int octalHexa()
{
    long long int octal, decimal = 0, i = 0, temp, resto, ret;
    char hexa[100];

    printf("Insira o número em octal que deseja converter para hexadecimal: ");

    ret = scanf("%lld", &octal);

    while (getchar() != '\n');


    if(ret != 1 || octal < 0)
    {
        printf("\nNúmero octal inválido.\n");
        printf("Tente novamente.\n\n");
        octalHexa();
        return 0;
    }


    temp = octal;

    while(octal != 0)
    {
        if(octal % 10 > 7 || octal % 10 < 0)
        {
            printf("\nNúmero octal inválido\n");
            printf("Tente novamente.\n\n");
            octalHexa();
            return 0;
        }

        decimal += octal % 10 * pow(8,i);
        octal/=10;
        i++;
    }

    i = 0;

    while(decimal != 0)
    {
        resto = decimal % 16;
        switch(resto)
        {
            case 0:
                hexa[i] = '0';
                break;
            case 1:
                hexa[i] = '1';
                break;
            case 2:
                hexa[i] = '2';
                break;
            case 3:
                hexa[i] = '3';
                break;
            case 4:
                hexa[i] = '4';
                break;
            case 5:
                hexa[i] = '5';
                break;
            case 6:
                hexa[i] = '6';
                break;
            case 7:
                hexa[i] = '7';
                break;
            case 8:
                hexa[i] = '8';
                break;
            case 9:
                hexa[i] = '9';
                break;
            case 10:
                hexa[i] = 'A';
                break;
            case 11:
                hexa[i] = 'B';
                break;
            case 12:
                hexa[i] = 'C';
                break;
            case 13:
                hexa[i] = 'D';
                break;
            case 14:
                hexa[i] = 'E';
                break;
            case 15:
                hexa[i] = 'F';
                break;
        }
        i++;
        decimal/=16;
    }

    hexa[i] = '\0';
    reverseString(hexa);

    
    printf("\n\n%lld(8) = %s(16)\n", temp, hexa);


    return 0;
}

int decimalBinario()
{
    long long int decimal, temp;
    char binario[200];
    int j = 0, resto;

    printf("Insira o número em decimal que deseja converter para binário: ");
    long long int ret;

    ret = scanf("%lld", &decimal);

    while (getchar() != '\n');

    if(ret != 1 || decimal < 0)
    {
        printf("\nNúmero decimal inválido.\n");
        printf("Tente novamente.\n\n");
        decimalBinario();
        return 0;
    }
    
    
    temp = decimal;

    while(decimal != 0)
    {
        resto = decimal % 2;
        binario[j] = resto + '0';
        j++;
        decimal/=2;
    }

    binario[j] = '\0';

    reverseString(binario);

    printf("\n\n%lld(10) = %s(2)\n", temp, binario);
    return 0;
}

int decimalOctal()
{
    long long int decimal, i = 0, ret, temp, resto;
    char octal[200];
    printf("Insira o número em decimal que deseja converter para octal: ");
    
    ret = scanf("%lld", &decimal);
    
    while (getchar() != '\n');

    if(ret != 1 || decimal < 0)
    {
        printf("\nNúmero decimal inválido.\n");
        printf("Tente novamente.\n\n");
        decimalOctal();
        return 0;
    }

    temp = decimal;

    while(decimal != 0)
    {
        resto = decimal % 8;
        octal[i] = resto + '0';
        i++;
        decimal/=8;
    }

    octal[i] = '\0';

    reverseString(octal);

    printf("\n\n%lld(10) = %s(8)\n", temp, octal);


    
    return 0;
}

int decimalHexa()
{
    long long int decimal, i = 0, temp, ret, resto;
    char hexadecimal[200];

    printf("Insira o número em decimal que deseja converter para hexadecimal: ");

    ret = scanf("%lld", &decimal);

    while (getchar() != '\n');

    if(ret != 1 || decimal < 0)
    {
        printf("\nNúmero decimal inválido.\n");
        printf("Tente novamente.\n\n");
        decimalHexa();
        return 0;
    }

    temp = decimal;

    while(decimal != 0)
    {
        resto = decimal % 16;

        switch(resto)
        {
            case 0:
            hexadecimal[i] = '0';
            break;
            case 1:
            hexadecimal[i] = '1';
            break;
            case 2:
            hexadecimal[i] = '2';
            break;
            case 3:
            hexadecimal[i] = '3';
            break;
            case 4:
            hexadecimal[i] = '4';
            break;
            case 5:
            hexadecimal[i] = '5';
            break;
            case 6:
            hexadecimal[i] = '6';
            break;
            case 7:
            hexadecimal[i] = '7';
            break;
            case 8:
            hexadecimal[i] = '8';
            break;
            case 9:
            hexadecimal[i] = '9';
            break;
            case 10:
            hexadecimal[i] = 'A';
            break;
            case 11:
            hexadecimal[i] = 'B';
            break;
            case 12:
            hexadecimal[i] = 'C';
            break;
            case 13:
            hexadecimal[i] = 'D';
            break;
            case 14:
            hexadecimal[i] = 'E';
            break;
            case 15:
            hexadecimal[i] = 'F';
            break;
        }

        i++;
        decimal /= 16;
    }

    hexadecimal[i] = '\0';

    reverseString(hexadecimal);

    printf("\n\n%lld(10) = %s(16)\n",temp, hexadecimal);
    
    return 0;
}

int hexaBinario()
{
    char hexadecimal[100];
    char binario[200];
    long long int decimal;

    decimal = 0;

    printf("Insira o número em hexadecimal que deseja converter para binario: ");
    scanf("%s", hexadecimal);

    int i = strlen(hexadecimal) - 1;
    int valor = 0;

    reverseString(hexadecimal);


    for(int j = 0; j <= i;j++)
    {
        char hexChar = toupper(hexadecimal[j]);
        hexadecimal[j] = hexChar;        
        
        switch(hexChar)
        {
            case '0':
                valor = 0;
                break;
            case '1':
                valor = 1;
                break;
            case '2':
                valor = 2;
                break;
            case '3':
                valor = 3;
                break;
            case '4':
                valor = 4;
                break;
            case '5':
                valor = 5;
                break;
            case '6':
                valor = 6;
                break;
            case '7':
                valor = 7;
                break;
            case '8':
                valor = 8;
                break;
            case '9':
                valor = 9;
                break;
            case 'A': 
                valor = 10;
                break;
            case 'B': 
                valor = 11;
                break;
            case 'C': 
                valor = 12;
                break;
            case 'D':
                valor = 13;
                break;
            case 'E':
                valor = 14;
                break;
            case 'F':
                valor = 15;
                break;

            default:
                printf("\nNúmero hexadecimal inválido.\n");
                printf("Tente novamente.\n\n");
                hexaBinario();
                return 0;
        }

        decimal += valor * pow(16,j);
    }

    int j = 0;

    while(decimal != 0)
    {
        valor = decimal % 2;
        binario[j] = valor + '0';
        decimal/=2;
        j++;
    }

    binario[j] = '\0';

    reverseString(binario);
    reverseString(hexadecimal);

    printf("\n\n%s(16) = %s(2)\n", hexadecimal, binario);
    
    return 0;
}

int hexaOctal()
{
    char hexadecimal[100];
    char octal[200];
    long long int decimal;

    decimal = 0;

    printf("Insira o número em hexadecimal que deseja converter para octal: ");
    scanf("%s", hexadecimal);

    int i = strlen(hexadecimal) - 1;
    reverseString(hexadecimal);
    int valor = 0;


    for(int j = 0; j <= i;j++)
    {
        char hexChar = toupper(hexadecimal[j]);
        hexadecimal[j] = hexChar;        
        
        switch(hexChar)
        {
            case '0':
                valor = 0;
                break;
            case '1':
                valor = 1;
                break;
            case '2':
                valor = 2;
                break;
            case '3':
                valor = 3;
                break;
            case '4':
                valor = 4;
                break;
            case '5':
                valor = 5;
                break;
            case '6':
                valor = 6;
                break;
            case '7':
                valor = 7;
                break;
            case '8':
                valor = 8;
                break;
            case '9':
                valor = 9;
                break;
            case 'A': 
                valor = 10;
                break;
            case 'B': 
                valor = 11;
                break;
            case 'C': 
                valor = 12;
                break;
            case 'D':
                valor = 13;
                break;
            case 'E':
                valor = 14;
                break;
            case 'F':
                valor = 15;
                break;

            default:
                printf("\nNúmero hexadecimal inválido.\n");
                printf("Tente novamente.\n\n");
                hexaOctal();
                return 0;
        }

        decimal += valor * pow(16,j);
    }

    int j = 0;

    while(decimal != 0)
    {
        valor = decimal % 8;
        octal[j] = valor + '0';
        j++;
        decimal /= 8;
    }

    octal[j] = '\0';
    reverseString(octal);
    reverseString(hexadecimal);

    printf("\n\n%s(16) = %s(8)\n", hexadecimal, octal);

    return 0;


}

int hexaDecimal()
{
    char hexadecimal[100];
    long long int decimal;

    decimal = 0;

    printf("Insira o número em hexadecimal que deseja converter para octal: ");
    scanf("%s", hexadecimal);

    int i = strlen(hexadecimal) - 1;
    reverseString(hexadecimal);
    int valor = 0;


    for(int j = 0; j <= i;j++)
    {
        char hexChar = toupper(hexadecimal[j]);
        hexadecimal[j] = hexChar;        
        
        switch(hexChar)
        {
            case '0':
                valor = 0;
                break;
            case '1':
                valor = 1;
                break;
            case '2':
                valor = 2;
                break;
            case '3':
                valor = 3;
                break;
            case '4':
                valor = 4;
                break;
            case '5':
                valor = 5;
                break;
            case '6':
                valor = 6;
                break;
            case '7':
                valor = 7;
                break;
            case '8':
                valor = 8;
                break;
            case '9':
                valor = 9;
                break;
            case 'A': 
                valor = 10;
                break;
            case 'B': 
                valor = 11;
                break;
            case 'C': 
                valor = 12;
                break;
            case 'D':
                valor = 13;
                break;
            case 'E':
                valor = 14;
                break;
            case 'F':
                valor = 15;
                break;

            default:
                printf("\nNúmero hexadecimal inválido.\n");
                printf("Tente novamente.\n\n");
                hexaBinario();
                return 0;
        }

        decimal += valor * pow(16,j);
    }

    reverseString(hexadecimal);

    printf("\n\n%s(16) = %lld(10)\n", hexadecimal, decimal);

    return 0;

}



int main()
{
    int escolha1, escolha2, escolha3, ret;

    printf("\t\t-----Conversor de Bases-----\t\t\n\n");
    printf("Converter de:\n\n");
    printf("1|Binário\n");
    printf("2|Octal\n");
    printf("3|Decimal\n");
    printf("4|Hexadecimal\n");
    printf("5|Sair do programa\n\n");

    printf("Insira sua escolha: ");
    
    ret = scanf("%d", &escolha1);

    while(escolha1 < 1 || escolha1 > 5 || ret != 1)
    {
        printf("\nEscolha inválida\n");
        printf("Insira sua escolha novamente: ");
        while (getchar() != '\n');
        ret = scanf("%d", &escolha1);

    }

    printf("\n\n");

    switch(escolha1)
    {
        case 1:
            printf("Binário para:\n\n");
            printf("1|Octal\n");
            printf("2|Decimal\n");
            printf("3|Hexadecimal\n\n");

            printf("Insira sua escolha: ");
            
            ret = scanf("%d", &escolha2);

            while(escolha2 < 1 || escolha2 > 3 || ret != 1)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                while(getchar() != '\n');
                ret = scanf("%d", &escolha2);
            }

            printf("\n\n");

            switch(escolha2)
            {
                case 1:
                    binarioOctal();
                    break;
                case 2:
                    binarioDecimal();
                    break;
                case 3:
                    binarioHexa();
                    break;    
            }

            break;
        
        case 2:
            printf("Octal para:\n");
            printf("1|Binário\n");
            printf("2|Decimal\n");
            printf("3|Hexadecimal\n\n");

            printf("Insira sua escolha: ");
            
            ret = scanf("%d", &escolha2);

            while(escolha2 < 1 || escolha2 > 3 || ret != 1)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                
                while (getchar() != '\n');
                ret = scanf("%d", &escolha2);

            }

            printf("\n\n");

            switch(escolha2)
            {
                case 1:
                    octalBinario();
                    break;
                case 2:
                    octalDecimal();
                    break;
                case 3:
                    octalHexa();
                    break;    
            }

            break;
        
        case 3:
            printf("Decimal para:\n");
            printf("1|Binário\n");
            printf("2|Octal\n");
            printf("3|Hexadecimal\n\n");

            printf("Insira sua escolha: ");
            ret = scanf("%d", &escolha2);

            while(escolha2 < 1 || escolha2 > 3 || ret != 1)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                
                while (getchar() != '\n');
                ret = scanf("%d", &escolha2);

            }

            printf("\n\n");

            switch(escolha2)
            {
                case 1:
                    decimalBinario();
                    break;
                case 2:
                    decimalOctal();
                    break;
                case 3:
                    decimalHexa();
                    break;    
            }

            break;
        
        case 4:
            printf("Hexadecimal para:\n");
            printf("1|Binário\n");
            printf("2|Octal\n");
            printf("3|Decimal\n\n");

            printf("Insira sua escolha: ");
            ret = scanf("%d", &escolha2);

            while(escolha2 < 1 || escolha2 > 3 || ret != 1)
            {
                printf("\nEscolha inválida\n");
                printf("Insira sua escolha novamente: ");
                
                while (getchar() != '\n');
                ret = scanf("%d", &escolha2);

            }
            
            printf("\n\n");
            
            switch(escolha2)
            {
                case 1:
                    hexaBinario();
                    break;
                case 2:
                    hexaOctal();
                    break;
                case 3:
                    hexaDecimal();
                    break;    
            }

            break;
        
        case 5:
            return 0;
            break;
    }

    printf("\nGostaria de rodar o programa novamente?\n\n");
    printf("1|Sim\n");
    printf("2|Não\n\n");

    printf("Insira sua escolha: ");
    
    ret = scanf("%d", &escolha3);

    while(escolha3 != 1 && escolha3 != 2 || ret != 1)
    {
        printf("\nEscolha inválida.\n");
        printf("Insira sua escolha novamente: ");
        while (getchar() != '\n');
        ret = scanf("%d", &escolha3);  
    }

    if(escolha3 == 1)
    {
        system("clear");
        main();
    }
    else
    {
        return 0;
    }
}

